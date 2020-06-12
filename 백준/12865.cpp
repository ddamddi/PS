#include <iostream>
using namespace std;

int w[101], v[101], dp[100001];
int n, k;

void knapsack(){
	for(int i=1; i<=n; i++){
		for(int j=k; j>=1; j--){
			if(w[i] <= j)
				dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
		}
	}
	
	cout << dp[k] << '\n';
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> w[i] >> v[i];
		
	knapsack();
	
	return 0;
}
