#include <iostream>
#include <queue>
#define MAX_NUM 102
using namespace std;

int N, M;
int map[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];

int x_move[4] = {-1, 0, 1, 0};
int y_move[4] = {0, 1, 0, -1};

int maze(int start_x, int start_y, int fin_x, int fin_y){
	queue<pair<int,int> > q;
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			if(map[x+x_move[i]][y+y_move[i]] == 1 && visited[x+x_move[i]][y+y_move[i]] == 0){
				visited[x+x_move[i]][y+y_move[i]] = visited[x][y] + 1;
				q.push(make_pair(x+x_move[i], y+y_move[i]));
			}
		}
	}
	return visited[fin_x][fin_y];
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	fill(&map[0][0],&map[MAX_NUM-1][MAX_NUM], 0);
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		string tmp;
		cin >> tmp;
		for(int j=1; j<=M; j++)
			map[i][j] = tmp[j-1] - '0';
	}
	
	cout << maze(1,1,N,M) << '\n';
}
