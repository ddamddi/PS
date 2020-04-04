#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[25][25] = {0,};
bool visited[25][25] = {false,};
int move_x[4] = {0,1,0,-1};
int move_y[4] = {-1,0,1,0};
vector<int> v;

bool boundary_check(int i, int j);
int bfs(int i, int j, int c);

int main(){
	string tmp;	
	int danji = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> tmp;
		for(int j=0; j<N; j++){
			map[i][j] = tmp[j] - '0';
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] != 0 && visited[i][j] == false){
				v.push_back(bfs(i, j, danji++));
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] << endl;
	return 0;
}

bool boundary_check(int i, int j){
	if(i >=0 && i < N && j >= 0 && j < N)
		return true;
	return false;
}

int bfs(int i, int j, int c){
	int cnt = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	visited[i][j] = true;
	
	while(!q.empty()){
		pair<int,int> current = q.front(), next;
		q.pop();
		map[current.first][current.second] = c+1;
		cnt++;
		
		for(int k=0; k<4; k++){
			next = make_pair(current.first+move_y[k], current.second+move_x[k]);
			if(boundary_check(next.first, next.second) && map[next.first][next.second] != 0 && visited[next.first][next.second] == false){
				q.push(next);
				visited[next.first][next.second] = true;
				map[next.first][next.second] = c+1;
			}
		}
	}
	return cnt;
}
