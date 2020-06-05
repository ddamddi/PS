#include <iostream>
#include <queue>
using namespace std;

int map[100][100][100]; // h x m x n
int m,n,h,days=0;
int z_move[6] = {1,-1, 0, 0, 0, 0};
int x_move[6] = {0, 0, 1,-1, 0, 0};
int y_move[6] = {0, 0, 0, 0, 1,-1};

struct coordinates{
	int h,n,m;
};

void tomatoes(){
	queue <coordinates> q;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(map[i][j][k] == 1){
					coordinates tmp = {i, j, k};
					q.push(tmp);
				}
			}
		}
	}
	while(1){
		int ripe = q.size();
		for(int i=0; i<ripe; i++){
			coordinates current = q.front();
			q.pop();
			
			for(int j=0; j<6; j++){
				coordinates next = {current.h + z_move[j], current.n + x_move[j], current.m + y_move[j]};
				if(next.h >= 0 && next.h < h && next.m >= 0 && next.m < m && next.n >= 0 && next.n < n){
					if(map[next.h][next.n][next.m] == 0){
						q.push(next);
						map[next.h][next.n][next.m] = 1;
					}
				}
			}
		}
		
		if(q.size() == 0)
			return;
		else
			days++;
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin>>m>>n>>h;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				cin >> map[i][j][k];
			}
		}
	}
	
	tomatoes();
	
	bool isAllRipe = true;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(map[i][j][k] == 0){
					isAllRipe = false;
				}
			}
		}
	}
	
	if(isAllRipe)
		cout << days << '\n';
	else
		cout << -1 << '\n';
	
	return 0;
}
