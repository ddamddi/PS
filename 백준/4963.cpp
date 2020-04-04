#include <iostream>
#include <queue>
using namespace std;

int w = -1, h = -1, islands = 0;
int map[50][50] = {1,};
bool visited[50][50] = {false,};
int move_x[8] = {0,1,1,1,0,-1,-1,-1};
int move_y[8] = {-1,-1,0,1,1,1,0,-1};

void init();
void bfs(int i, int j);
bool boundary_check(int i, int j);

int main(){
    while(1){
        init();
        cin >> w >> h;
        if(w == 0 && h == 0)
            return 0;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]==1 && visited[i][j]==false){
                    bfs(i,j);
                    islands++;
                }
            }
        }
        cout << islands << endl;   
    }
}

void init(){
    islands = 0;
    fill(&visited[0][0], &visited[49][50], false);
    fill(&map[0][0], &map[49][50], 0);
}

void bfs(int i, int j){
    int cnt = 0;
    queue<pair<int,int> > q;
    visited[i][j] = true;
    q.push(make_pair(i,j));
    
    while(!q.empty()){
        pair<int,int> current = q.front(), next;
        q.pop();
        cnt++;

        for(int i=0; i<8; i++){
            next = make_pair(current.first+move_y[i], current.second+move_x[i]);
            if(boundary_check(next.first, next.second) && map[next.first][next.second] == 1 && visited[next.first][next.second] == false){
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

bool boundary_check(int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w) 
        return true;
    return false;
}

