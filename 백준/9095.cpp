#include <iostream>
using namespace std;

int arr[11];

int memo(int x){
	if(x < 3)
		return arr[x];
	
	if(arr[x] != 0)
		return arr[x];
	
	arr[x] = memo(x-1) + memo(x-2) + memo(x-3);
	return arr[x];
}

int main(){
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	int T, N;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;
		cout << memo(N) << '\n';
	}
	return 0;
}
