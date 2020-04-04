#include <iostream>
#define MAX(X,Y) (X>Y) ? X : Y
using namespace std;

int arr[1001];
int dp[1001];

int main(){
	int N, len;
	cin >> N;
	for(int i = 1; i <= 1000; i++){
		cin >> arr[i];
	}
	
	dp[1] = 1;
	for(int i = 2; i <= N; i++){
		len = 0;
		for(int j = i; j > 0; j--){
			for(int k = j-1; k > 0; k--){
				arr[k] 
			}
		}
		
		dp[i] = MAX(dp[i-1], len);
	}
	
	return 0;
}
