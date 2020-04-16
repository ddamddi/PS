#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sanggeun;
int n;

int lower_bound(int target){
	int left, right, mid;
	left=0, right=n;
	
	while(left < right){
		mid = (left+right)/2;
		
		if(sanggeun[mid] >= target)
			right = mid;
		else
			left = mid+1;
	}
	return right;
}

int upper_bound(int target){
	int left, right, mid;
	left=0, right=n;
	
	while(left < right){
		mid = (left+right)/2;
		
		if(sanggeun[mid] <= target)
			left = mid+1;
		else
			right = mid;
	}
	return right;
}


int main(){
	cin.tie(0);
	cout.tie(0);
    ios_base::sync_with_stdio(false);
	
	int tmp;
	vector<int> compare;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> tmp;
		sanggeun.push_back(tmp);
	}
	sort(sanggeun.begin(), sanggeun.end());
	
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> tmp;
		compare.push_back(tmp);
	}
	
	for(auto c: compare){
		int u = upper_bound(c);
		int l = lower_bound(c);
		cout <<  u-l << ' ';
	}
}
