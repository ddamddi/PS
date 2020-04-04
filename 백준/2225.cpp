#include <iostream>
#define REMAINDER 1000000000
using namespace std;

long long dp[201][201]; // [N][K]

int main(){
	int N, K;
	cin >> N >> K;
	
	for(int i = 0; i < 201; i++){
		dp[0][i] = 1;
		dp[i][1] = 1;
	}
	
	for(int n = 1; n <= N; n++){
		for(int k = 2; k <= K; k++){
			dp[n][k] = (dp[n-1][k] + dp[n][k-1]) % REMAINDER;
		}
	}
		
	cout << dp[N][K] % REMAINDER << '\n';
	return 0;
}
