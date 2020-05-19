#include <iostream>
#define MAX 10000
using namespace std;

int arr[MAX];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	int low, high, sum = arr[0];
	low = high = 0;
	int ans = 0;
	while(1){
//		cout << "s: " << low << " e:" << high << " sum:" <<  sum << '\n';
		
		if(high == n)
			break;
		
		if(sum == m){
			ans++;
			high++;
			sum += arr[high];
		}
		else if(sum < m){
			high++;
			sum += arr[high];
		}
		else if(sum > m){
			sum -= arr[low];
			low++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
