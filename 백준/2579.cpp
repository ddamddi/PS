#include <iostream>
#define MAX(X, Y) X > Y ? X : Y
using namespace std;

int dp[301], score[301];

int main(){
	int stairs;
	cin >> stairs;
	
	for(int i = 1; i <= stairs; i++){
		cin >> score[i];
	}
	
	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	
	for(int i = 3; i <= stairs; i++){
		dp[i] = MAX(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
	}
	cout << dp[stairs] << '\n';
	return 0;
}
