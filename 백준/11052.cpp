#include <iostream>
using namespace std;

int pack[1001];
int dp[10001];

int Max(int x, int y){
	return (x>y ? x : y);
}

int main(){
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++)
		cin >> pack[i];
	
	dp[1] = pack[1];
	dp[2] = Max(pack[2], dp[1]+dp[1]);
	
	for(int i=3; i<=N; i++){
		dp[i] = pack[i];
		for(int j=i-1; j>=i/2; j--){
			dp[i] = Max(dp[i], dp[j] + dp[i-j]);
		}		
	}
	cout << dp[N] << endl;
	
	
	return 0;
}
