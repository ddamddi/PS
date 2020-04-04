#include <iostream>
#define REMAINDER 1000000000
using namespace std;

long long dp[101][10] = { {0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1}, };

long long sum(int x){
	long long result=0;
	for(int i=0; i < 10; i++)
		result = (result + dp[x][i]) % REMAINDER;
	return result;
}

int main(){
	int N;
	cin >> N;
	
	for(int i=2; i<=N; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for(int j=1; j <= 8; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % REMAINDER;
		}
	}
	cout << sum(N) << endl;
	return 0;
}
