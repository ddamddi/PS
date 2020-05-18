#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, s;
	int cnt = 0;
	vector<int> v;
	cin >> n >> s;
	bool *select = new bool[n];
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	for(int i=1; i<=n; i++){
		fill(select, select+n, false);
		for(int j=0; j<i; j++){
			select[j] = true;
		}
		
		do{
			int sum = 0;
			for(int k=0; k<=n; k++){
				if(select[k])
					sum += v[k];
			}
			if(sum == s)
				cnt++;
		
		} while(prev_permutation(select, select+n));
		
	}
	
	cout << cnt << '\n';
	return 0;	
}
