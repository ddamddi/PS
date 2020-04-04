#include <iostream>
#define REMAINDER 10007
using namespace std;

int dp[1001][10] = {{0,0,0,0,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1,1,1},};

int main(){
	int N;
	cin >> N;
	
	for(int i = 2; i <= N; i++){
		for(int j = 0; j < 10; j++){
			for(int k = j; k >= 0; k--){
				dp[i][j] += dp[i-1][k];
			}
			dp[i][j] %= REMAINDER;
		}
	}
	int sum = 0;
	for(int i = 0; i < 10; i++)
		sum = sum + dp[N][i];
	cout << (sum % REMAINDER) << endl;
	return 0;
}
