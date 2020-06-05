#include <iostream>
using namespace std;

int map[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool square_check[9][10];

int get_square_idx(int row, int col){
	return (row / 3) * 3 + (col / 3);
}

void print_sudoku(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sudoku(int x){
	
	if(x == 81){
		print_sudoku();
		exit(0);
	}

	int row = x / 9;
	int col = x % 9;
	
	if(map[row][col] != 0)
		sudoku(x+1);
	else{
		for(int i=1; i<10; i++){
			if(!row_check[row][i] && !col_check[col][i] && !square_check[get_square_idx(row, col)][i]){
				map[row][col] = i;
				row_check[row][i] = true;
				col_check[col][i] = true;
				square_check[get_square_idx(row,col)][i] = true;
				sudoku(x+1);
				map[row][col] = 0;
				row_check[row][i] = false;
				col_check[col][i] = false;
				square_check[get_square_idx(row,col)][i]= false;
			}
		}
	}
}

int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> map[i][j];
			if(map[i][j] != 0){
				row_check[i][map[i][j]] = true;
				col_check[j][map[i][j]] = true;
				int square_idx = get_square_idx(i, j);
				square_check[square_idx][map[i][j]] = true;
			}
		}
	}
	
	sudoku(0);
}
