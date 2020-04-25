#include <iostream>
#define MAX_NUM 3100
using namespace std;

char stars[MAX_NUM][MAX_NUM*2];

char mark[][6] =
{
	"  *  ",
	" * * ",
	"*****"
};

void star(int x, int y, int term){
	
	if(term == 1){
		for(int i =0; i<3; i++){
			for(int j=0; j<5; j++){
				stars[x+i][y+j] = mark[i][j];
			}
		}
	}
	else{
		int new_term = term/2;
		star(x , y + 3 * term / 2, new_term);
		star(x + 3 * term / 2, y , new_term);
		star(x + 3 * term / 2, y + 3 * term, new_term);
	}
	
}

int main(){
	int n;
	cin >> n;
	
	fill(&stars[0][0],&stars[MAX_NUM-1][MAX_NUM*2],' ');
	star(1,1,n/3);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n*2; j++){
			cout << stars[i][j];
		}
		cout << '\n';
	}
	
}
