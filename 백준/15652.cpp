#include <iostream>
using namespace std;

bool visited[9] = {false,};
int list[9];
int n, m;

void dfs(int x){
	int k;
	if(x == m){
		for(k=0; k<m-1; k++)
			if(list[k] > list[k+1])
				break;
		if(k == m-1){
			for(int i=0; i<m; i++)
				cout << list[i] << ' ';
			cout << '\n';
		}
		return;
	}
	for(int i=1; i<=n; i++){
		visited[i] = true;
		list[x] = i;
		dfs(x+1);
		visited[i] = false;
	}
}

int main(){
	cin >> n >> m;
	
	dfs(0);
	return 0;
}
