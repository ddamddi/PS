#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int max(int x, int y){
	if(x>y) return x;
	return y;
}

int main(){
	int N, max_val, ans;
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
	
	max_val = arr[1];
	for(int i=1; i<=N; i++){
		dp[i] = 1;
		for(int j=i-1; j>0; j--){
			if(arr[j] < arr[i] && arr[j] > max_val){
				dp[i] = dp[j] + 1;
				max_val = arr[j];
			}
		}
		cout << "dp[" << i << "] : " << dp[i] << endl;
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}
