#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
bool virus[101];

void bfs(int n){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    queue<int> q;
    q.push(n);
    virus[n] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<v[cur].size(); i++){
            int nxt = v[cur][i];
            if(virus[nxt] == false){
                q.push(nxt);
                virus[nxt] = true;
            }
        }
    }
}

int main(){
    int n, t;
    cin >> n >> t;
    for(int i=0; i<t; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    bfs(1);
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(virus[i]){
            cnt++;
            // cout << "#" << i << '\n';
        }         
    }
    cout << cnt << '\n';
    return 0;
}