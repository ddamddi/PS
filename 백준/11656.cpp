#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string s;
	vector<string> v;
	cin >> s;
	
	for(int i=0; i<s.size(); i++){
		v.push_back(s.substr(i));
	}
	
	sort(v.begin(),v.end());
	
	for(auto s : v)
		cout << s << '\n';
}
