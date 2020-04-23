#include <iostream>
#include <vector>
#define MAX_NUM 10001
#define ROOT 1
using namespace std;

bool visited[MAX_NUM];
vector<pair<int,int>> edges[MAX_NUM];
int d[MAX_NUM];

int dfs(int num){
    visited[num] = true;
    int ret = num;

    for(int i=0; i<edges[num].size(); i++){
        int nxt = edges[num][i].first;
        int cost = edges[num][i].second;
        if(visited[nxt] == false){
            d[nxt] = d[num] + cost;
            int ret_nxt = dfs(nxt);
            if(d[ret] < d[ret_nxt]){
                ret = ret_nxt;
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int x,y,w;
        cin >> x >> y >> w;

        edges[x].push_back(make_pair(y, w));
        edges[y].push_back(make_pair(x, w));
    }

    int dv = dfs(ROOT);
    fill(visited, visited+MAX_NUM, false);
    fill(d, d+MAX_NUM, 0);
    int another_dv = dfs(dv);

    cout << d[another_dv] <<  '\n'; 
}