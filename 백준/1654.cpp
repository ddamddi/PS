#include <iostream>
#include <climits>
#define MAX_NUM 10000
using namespace std;

int arr[MAX_NUM];

int main(){
	int k, n;
	cin >> k >> n;
	for(int i=0; i<k; i++)
		cin >> arr[i];
	
	long long min=0, max=INT_MAX, mid=0, ans=0;
	
	while(min <= max){
		mid = (max+min)/2;
		int cnt = 0;
		for(int i=0; i<k; i++)
			cnt += arr[i] / mid;
		
		if(cnt < n)
			max = mid-1;
		else{
			min = mid+1;
			if(ans < mid)
				ans = mid;
		}
	}
	cout << ans << '\n';
}
