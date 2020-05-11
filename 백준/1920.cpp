#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int binary_search(int n, int left, int right){
	while(left <= right){
		int mid = (left + right)/2;
		if(arr[mid] == n)
			return 1;
		else if(arr[mid] > n){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return 0;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	
	cin >> m;
	for(int i=0; i<m; i++){
		int tmp;
		cin >> tmp;
		cout << binary_search(tmp, 0, n-1) << '\n';
	}
	
	return 0;
}
