#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector <long long> v;
	int n, c;
	long long tmp;
	cin >> n >> c;
	for(int i=0; i<n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	long long max = v[n-1] - v[0];
	long long min = 0, ans=0;
	
	while(min <= max){
		long long mid = (max+min)/2;
		long long cnt=1;
		long long installed = v[0];
		
		for(int i=1; i<n; i++){
			if(v[i] - installed >= mid){
				cnt++;
				installed = v[i];
			}
		}
		
		if(cnt >= c){
			min = mid + 1;
			if(ans < mid)
				ans = mid;
		}
		else
			max = mid - 1;
	}
	
	cout << ans << '\n';
}
