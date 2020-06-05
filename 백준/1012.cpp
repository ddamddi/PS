#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
bool visit[50][50];
int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};
int m, n, k, ans = 0;

void bfs(int r, int c){
	queue <pair<int, int> > q;
	q.push(make_pair(r, c));
	visit[r][c] = true;
	map[r][c] = ans+1;
	
	while(!q.empty()){
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int next_x = current_x + x_move[i];
			int next_y = current_y + y_move[i];
			if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && visit[next_x][next_y] == false && map[next_x][next_y] == 1){
				q.push(make_pair(next_x, next_y));
				visit[next_x][next_y] = true;
				map[next_x][next_y] = ans+1;	
			}
		}
	}
	
	ans++;
}

int main(){
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		cin>>m>>n>>k;
		fill(&map[0][0], &map[49][50], 0);
		fill(&visit[0][0], &visit[49][50], false);
		ans = 0;
		for(int i=0; i<k; i++){
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(!visit[i][j] && map[i][j] == 1){
					bfs(i,j);
				}
			}
		}
		
//		for(int i=0; i<n; i++){
//			for(int j=0; j<m; j++){
//				cout << map[i][j] << ' ';
//			}
//			cout <<'\n';
//		}
		
		cout << ans << '\n';
	}
}
