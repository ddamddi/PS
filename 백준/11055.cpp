#include <iostream>
using namespace std;

int dp[1001], arr[1001];

int Max(int x, int y){
	return (x>y)? x:y;
}

int main(){
	int N, max_sum, ans = 0;
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
	
	for(int i=1; i<=N; i++){
		dp[i] = arr[i];
		max_sum = 0;
		for(int j=1; j<i; j++){
			if(max_sum < dp[j] && arr[j] < arr[i]){
				dp[i] = dp[j] + arr[i];
				max_sum = dp[j];
			}
		}
		ans = Max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
