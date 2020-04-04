#include <iostream>
//#define MAX(X,Y) ((X)>(Y)) ? (X) : (Y)
using namespace std;

int sticker[2][100001];
int dp[2][100001];

int max(int x, int y){
	if(x>y)
		return x;
	return y;
}

int main(){
	int testcase, n;
	cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		cin >> n;
		for(int j = 1; j <= n; j++)
			cin >> sticker[0][j];
		for(int j = 1; j <= n; j++)
			cin >> sticker[1][j];
		
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		dp[0][2] = max(dp[1][1] + sticker[0][2], dp[1][0] + sticker[0][2]);
		dp[1][2] = max(dp[0][1] + sticker[1][2], dp[0][0] + sticker[1][2]);
		
//		cout << "dp[0][0] : " << dp[0][0] << endl;
//		cout << "dp[1][0] : " << dp[1][0] << endl;
//		cout << "dp[0][1] : " << dp[0][1] << endl;
//		cout << "dp[1][1] : " << dp[1][1] << endl;
//		cout << "dp[0][2] : " << dp[0][2] << endl;
//		cout << "dp[1][2] : " << dp[1][2] << endl;
		
		for(int j = 3; j <= n; j++){
			dp[0][j] = max(dp[1][j-1] + sticker[0][j], dp[1][j-2] + sticker[0][j]);
			dp[1][j] = max(dp[0][j-1] + sticker[1][j], dp[0][j-2] + sticker[1][j]);
			
//			cout << "dp[0][" << j << "] : " << dp[0][j] << endl;
//			cout << "dp[1][" << j << "] : " << dp[1][j] << endl;
		}
		
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}
