#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> v;
	for(int i=n; i>=0; i--){
		int m=i,x=i;
		while(x != 0){
			m += x%10;
			x /= 10;
		}
		if(m == n)
			v.push_back(i);
	}
	
	if(v.size() == 0)
		cout << 0 << '\n';
	else{
		sort(v.begin(), v.end());
		cout << v[0] << '\n';
	}
	return 0;
}
