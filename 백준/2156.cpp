#include <iostream>
#define MAX(X, Y) (X > Y) ? X : Y
using namespace std;

int wine[10000];
int dp[10000];

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> wine[i];
		
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1];
		dp[i] = MAX(dp[i], dp[i-2] + wine[i]);
		dp[i] = MAX(dp[i], dp[i-3] + wine[i-1] + wine[i]);
	}
	
	cout << dp[n] << '\n';	
	return 0;
}
