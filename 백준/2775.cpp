#include <iostream>
using namespace std;

int arr[15][15];

int main(){
	
	for(int i=1; i<15; i++){
		arr[0][i] = i;
		arr[i][1] = 1;
	}
	for(int i=1; i<15; i++){	
		for(int j=2; j<15; j++){
			arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
	
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		int k,n;
		cin >> k >> n;
		cout << arr[k][n] << '\n';
	}
	return 0;
}
