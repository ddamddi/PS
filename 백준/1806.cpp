#include <iostream>
#define INF 987654321
using namespace std;

int arr[100000];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, s, ans = INF;
	cin >> n >> s;
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	int start = 0, end = 0;
	long long sum = arr[0];
	while(start <= end && end < n){
//		cout << "S: " << start << " E: " << end << " Sum:" << sum << " len:" << end-start+1 << '\n'; 
		
		if(sum < s){
			end++;
			sum += arr[end];
		}
		else if(sum == s){
			ans = min(ans, end-start+1);
			end++;
			sum += arr[end];
		}
		else if(sum > s){
			ans = min(ans, end-start+1);
			sum -= arr[start];
			start++;
		}
	}
	
	if(ans == INF)
		ans = 0;
	cout << ans << '\n';
	return 0;	
}
