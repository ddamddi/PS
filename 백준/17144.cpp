#include <iostream>
#include <algorithm>
using namespace std;

int map[50][50];
int x_move[4] = {0,1,0,-1};
int y_move[4] = {1,0,-1,0};
int R,C,T;
int air_purifier[2];

void spread_dust(){
	int temp[50][50];
	fill(&temp[0][0], &temp[49][50], 0);
	
	for(int i=0; i<2; i++){
		temp[air_purifier[i]][0] = -1;
	}
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] > 0){
				int spread = map[i][j]/5;
				int spread_cnt = 0;
				for(int k=0; k<4; k++){
					int new_x = i + x_move[k];
					int new_y = j + y_move[k];
					
								
					if(new_x >= 0 && new_x < R && new_y >= 0 && new_y < C){
						if(new_y == 0 && (new_x == air_purifier[0] || new_x == air_purifier[1]))
							continue;
					
						spread_cnt++;
						temp[new_x][new_y] += spread;
					}
				}
				
				temp[i][j] += map[i][j] - spread * spread_cnt;
			}
		}
	}
	
	copy(&temp[0][0], &temp[49][50], &map[0][0]);
}

void purify_air(){
	for(int i=air_purifier[0]-1; i>0; i--){
		map[i][0] = map[i-1][0];
	}
	
	for(int i=air_purifier[1]+1; i<R-1; i++){
		map[i][0] = map[i+1][0];
	}
	
	for(int i=0; i<C-1; i++){
		map[0][i] = map[0][i+1];
		map[R-1][i] = map[R-1][i+1];
	}
	
	for(int i=0; i<air_purifier[0]; i++){
		map[i][C-1] = map[i+1][C-1];
	}
	
	for(int i=R-1; i>air_purifier[1]; i--){
		map[i][C-1] = map[i-1][C-1];
	}
	
	for(int i=C-1; i>1; i--){
		for(int j=0; j<2; j++){
			map[air_purifier[j]][i] = map[air_purifier[j]][i-1];
		}
	}
	
	for(int i=0; i<2; i++){
		map[air_purifier[i]][1] = 0;
	}
	
}

void tick(){
	spread_dust();
	purify_air();
}

int total_dust(){
	int total = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			total += map[i][j];
		}
	}
	total += 2;
	return total;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin >>R>>C>>T;
	
	fill(&map[0][0], &map[49][50], 0);
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> map[i][j];
			if(map[i][j] == -1)
				air_purifier[1] = i;
		}
	}
	air_purifier[0] = air_purifier[1]-1;
	
	for(int i=0; i<R; i++){
		if(map[0][i] == -1){
			air_purifier[0] = i;
			air_purifier[1] = i+1;
			break;
		}
	}

	for(int i=0; i<T; i++)
		tick();
	cout << total_dust();
	return 0; 
	
}
