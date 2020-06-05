#include <iostream>
#include <vector>
using namespace std;

typedef struct shark{
	int r,c,s,d,z;
};

int R, C, M;
vector<shark> sharks;
int map[101][101];
int current_pos = 0;
int ans = 0;
int x_move[5] = {0, -1, 1, 0, 0}; 
int y_move[5] = {0, 0, 0, 1, -1};

void print_all(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			cout << map[i][j] << ' '; 
		}
		cout << '\n';
	}
	cout << '\n';
}

void shark_fishing(){
	for(int i=1; i<=R; i++){
		int index = map[i][current_pos]-1;
		if(index > -1){
			ans += sharks[index].z;
			map[i][current_pos] = 0;
			return;
		}
	}
}

void shark_move(){
//	cout << "shark move!!" << '\n';
	int temp[101][101];
	fill(&temp[0][0], &temp[100][101], 0);
	
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			if(map[i][j] > 0){
//				cout << "Shark!!!" << '\n';
				int index = map[i][j]-1;
				int d = sharks[index].d;
				int z = sharks[index].z;
				int s = sharks[index].s;
				int new_r = sharks[index].r;
				int new_c = sharks[index].c;
				
				// 1 2
				if(d < 3){
					s = s % ((R-1)*2);
					for(int k=1; k<=s; k++){
						if((new_r == 1 && d==1) || (new_r == R && d==2)){
							d++;
							if(d==3)
								d=1;
						}
						new_r += x_move[d];
					}
				}
				// 3 4
				else {
					s = s % ((C-1)*2);
					for(int k=1; k<=s; k++){
						if((new_c == 1 && d==4 )|| (new_c == C && d==3)){
							d++;
							if(d==5)
								d=3;
						}
						new_c += y_move[d];
					}
				}
				
				sharks[index].r = new_r;
				sharks[index].c = new_c;
				sharks[index].d = d;
				
//				cout << new_r << ", " << new_c << '\n';
				
				if(temp[new_r][new_c] == 0){
					temp[new_r][new_c] = index+1;
				}
				else{
					int other_s = temp[new_r][new_c]-1;
					if(sharks[other_s].z < z)
						temp[new_r][new_c] = index+1;
					cout << "shark ธิศ๛" << '\n';
				}
			}
		}
	}
	copy(&temp[0][0], &temp[100][101], &map[0][0]);
}

void tick(){
	current_pos++;
	shark_fishing();
//	print_all();
	shark_move();
	print_all();
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>R>>C>>M;
	
	for(int i=0; i<M; i++){
		// R(row) C(col) S(speed) D(direction) Z(size)
		shark tmp_shark;
		cin>>tmp_shark.r>>tmp_shark.c>>tmp_shark.s>>tmp_shark.d>>tmp_shark.z;
		sharks.push_back(tmp_shark);
	}
	
	fill(&map[0][0], &map[100][101], 0);
	for(int i=1; i<=sharks.size(); i++){
		map[sharks[i-1].r][sharks[i-1].c] = i;
	}
	
//	print_all();
	for(int i=0; i<C; i++)
		tick();
		
	cout << ans << '\n';
	return 0;
}
