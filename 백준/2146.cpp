#include <iostream>
#include <queue>
#define MAX_SIZE 102
using namespace std;

int N;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int x_move[4] = {-1, 0, 1, 0};
int y_move[4] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt){
	map[x][y] = cnt;
	visited[x][y] = true;
	
	for(int i=0; i<4; i++){
		if(map[x+x_move[i]][y+y_move[i]] == 1 && visited[x+x_move[i]][y+y_move[i]] == false)
			dfs(x+x_move[i], y+y_move[i], cnt);
	}
}

int bfs(int cnt){
	queue<pair<int,int> > q;
	int result = 0;
	
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			if(map[i][j] == cnt){
				q.push(make_pair(i,j));
				visited[i][j] = true;
			}
		}
	}
	
	while(!q.empty()){
		int q_size = q.size();
		for(int i=0; i<q_size; i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for(int j=0; j<4; j++){
				int new_x = x + x_move[j];
				int new_y = y + y_move[j];
				
				// 갈 수 있는 곳인지 check 
				if(new_x > 0 && new_x < N+1 && new_y > 0 && new_y < N+1){
					
					if(map[new_x][new_y] != 0 && map[new_x][new_y] != cnt)
						return result;
					
					
					if(map[new_x][new_y] == 0 && visited[new_x][new_y] == false){
						q.push(make_pair(new_x, new_y));
						visited[new_x][new_y] = true;
					}
				}		
			}
		}
		result++;
	}
	return MAX_SIZE*MAX_SIZE;
}

void printAll(){
	
	cout << '\n' << '\n';
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n' << '\n';
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			cin >> map[i][j];
		}
	}
	
	int cnt=1;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			if(map[i][j]==1 && visited[i][j]==false)
				dfs(i,j,cnt++);
		}
	}
	
//	printAll();

	int answer = MAX_SIZE*MAX_SIZE;
	for(int i=1; i<=cnt; i++){
		fill(&visited[0][0], &visited[MAX_SIZE-1][MAX_SIZE], false);
		answer = min(answer, bfs(i));
	}
	
	cout << answer << '\n';
}
