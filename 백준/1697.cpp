#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
int movement[2] = {1, -1};
int map[MAX];
bool visit[MAX];

int bfs(){
    int seconds = 0;
    queue <int> q;
    q.push(n);
    visit[n] = true;

    while(!q.empty()){
        int q_size = q.size();
        for(int j=0; j<q_size; j++){
            int cur = q.front();
            if(cur == k)
                return seconds;
            q.pop();

            for(int i=0; i<3; i++){
                int nxt;
                if(i < 2)
                    nxt = cur + movement[i];
                else
                    nxt = cur * 2;
            
                if(nxt >= 0 && nxt <= 100000){
                    if(!visit[nxt]){
                        q.push(nxt);
                        visit[nxt] = true;
                    }
                }
            }
        }
        seconds++;
    }
    return seconds;
}

int main(){
    fill(map, map+MAX, 0);
    fill(visit, visit+MAX, false);
    cin >> n >> k;

    cout << bfs() << '\n';
    return 0;
}