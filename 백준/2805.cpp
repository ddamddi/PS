#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector<long long> trees;
    int n;
	long long m, tmp;
	
    cin >> n >> m;
    for(int i=0; i<n; i++){
    	cin >> tmp;
    	trees.push_back(tmp);
	}
	sort(trees.begin(), trees.end());
	
	long long right = trees[n-1], left=0, mid=0, ans=0;
	while(left <= right){
		mid = (right+left)/2;
		long long sum = 0;
		for(auto tree: trees){
			tmp = tree - mid;
			if(tmp > 0)
				sum += tmp;
		}
		
//		cout << left << " " << right << " " << mid << " " << sum;
		
		if(sum >= m){
			ans = mid;
			left = mid+1;
		}
		else{
			right = mid-1;
		}
		
//		cout << " " << ans << endl;
	}
	cout << ans << '\n';
    return 0;
}
