#include <iostream>
#define MAX_NUM 100001
using namespace std;

int T, n, ans;
int teammate[MAX_NUM];
bool visited[MAX_NUM];
bool finished[MAX_NUM];

void init();
void dfs(int x);


int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> n;
        init();
        for(int i=1; i<=n; i++)
            cin >> teammate[i];
        
        for(int i=1; i<=n; i++)
            dfs(i);

        cout << n - ans << '\n';
    }

}

void init(){
    fill(teammate, teammate+MAX_NUM, 0);
    fill(visited, visited+MAX_NUM, false);
    fill(finished, finished+MAX_NUM, false);
    ans = 0;
}

void dfs(int now){
    if(visited[now] == true)
        return;
    
    visited[now] = true;
    int next = teammate[now];

    if(visited[next] != true){
        dfs(next);
    }
    else{
        if(finished[next] != true){
            for(int i=next; i != now; i = teammate[i]) 
                ans++;
            ans++;
        }
    }
    finished[now] = true;
}
