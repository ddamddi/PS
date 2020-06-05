#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	
	vector<int> v;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++){	// j-i
		for(int j=0; j<=n-i; j++){
			int sum = 0;
			for(int k=j; k<j+i; k++){
				sum += v[k];
			}
			if(sum == m)
				cnt++;
		}
	}
	
	cout << cnt << '\n';
	
	return 0;	
}
