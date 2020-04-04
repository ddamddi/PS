#include <iostream>
using namespace std;

int dp[100001];

int main(){
	int N, max = 1;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
		
	for(int i = 2; i <= N; i++){
		for(int j = 1; j*j <= i; j++){
			if(dp[i] > dp[i-j*j] + 1 || dp[i] == 0)
				dp[i] = dp[i-j*j] + 1; cout << j << endl;
		}
	}
	
	cout << dp[N] << '\n'; 
	return 0;
}
