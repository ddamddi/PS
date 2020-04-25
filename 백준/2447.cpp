#include <iostream>
#define MAX_NUM 2200
using namespace std;

char stars[MAX_NUM][MAX_NUM];

void star(int x, int y, int term){
	if(term == 1){
		stars[x][y] = '*';
		return;
	}
	
	int new_term = term/3;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i!=1 || j != 1){
				star(x + i*new_term,y + j*new_term, new_term);
			}
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	fill(&stars[0][0], &stars[MAX_NUM-1][MAX_NUM], ' ');
	star(0,0,n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << stars[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}
