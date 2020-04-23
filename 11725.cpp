#include <iostream>
#include <vector>
#define MAX_NUM 100002
#define ROOT 1
using namespace std;

bool visited[MAX_NUM];
vector<int> tree[MAX_NUM];
int parents[MAX_NUM];

void find_parent(int num){
    visited[num] = true;
    
    for(int i=0; i<tree[num].size(); i++){
        int nxt = tree[num][i];
        if(visited[nxt] == false){
            find_parent(nxt);
            parents[nxt] = num;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    find_parent(ROOT);

    for(int i=2; i<n+1; i++)
        cout << parents[i] << '\n';
}