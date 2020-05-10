#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int x, int y){
	if(x <= y)
		return false;
	return true;
}

int main(){
	vector<int> v;
	string s;
	cin >> s;
	
	int len = s.size();
	long long sum = 0, zeros = 0;
	for(int i=0; i<len; i++){
		int num = (s[i] - '0');
		v.push_back(num);
		sum += num;
		if(num == 0)
			zeros++;
	}
	
	if(sum % 3 == 0 && zeros > 0){
		sort(v.begin(), v.end(), cmp);
		for(auto x : v)
			cout << x;
		cout << '\n';
	}
	else
		cout << -1 << '\n';
		
	return 0;
}
