#include <iostream>
using namespace std;

int arr[100001];
long long dp[100001];

int max(int x, int y){
	return x > y ? x : y;
}

int main(){
	int N;
	long long max_val;
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
		
	max_val = dp[1] = arr[1];
	for(int i=2; i<=N; i++){
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
		max_val = max(max_val, dp[i]);	
		cout << "dp[" << i << "] : " << dp[i] << endl;
	}
	cout << max_val << endl;
	return 0;
}
