#include <iostream>
using namespace std;

int coin[10];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		coin[i] = tmp;
	}
	
	int ans = 0;
	while(k > 0){
		for(int i=n-1; i>=0; i--){
			if(k - coin[i] >= 0){
				k -= coin[i];
				ans++;
				break;
			}
		}
	}
	
	cout << ans << '\n';
} 
