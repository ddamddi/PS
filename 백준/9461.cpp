#include <iostream>
using namespace std;

long long arr[101] = {0,1,1,1,2,2,};

long long dp(int x){
	if(x < 6)
		return arr[x];
	else {
		if(arr[x] == 0)
			arr[x] = dp(x-1) + dp(x-5);
		return arr[x];
	}
	
}

int main(){
	int N, T;
	long long ans;
	cin >> T;
	
	for(int i = 1; i <= T; i++){
		cin >> N;
		cout << dp(N) << '\n';
	}
	return 0;
}
