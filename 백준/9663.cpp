#include <iostream>
using namespace std;

int n, ans=0;
int col[16];

bool isPossible(int row){
	for(int i=1; i<row; i++){
		if(col[i] == col[row])
			return false;
		
		if(abs(col[i]- col[row]) == abs(row - i))
			return false;
	}
	return true;
}

void dfs(int row){
	if(row > n){
		ans++;
		return;
	}
		
	for(int i=1; i<=n; i++){
		col[row] = i;
		if(isPossible(row))
			dfs(row+1);
		else
			col[row] = 0;
	}
}

int main(){
	cin >> n;
	
	for(int i=1; i<=n; i++){
		fill(col, col+16, 0);
		col[1] = i;
		dfs(2);	
	}
	
	cout << ans << '\n';
	return 0;
}
