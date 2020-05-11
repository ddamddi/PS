#include <iostream>
using namespace std;

string reverse(string s){
	string ans = "";
	for(int i=s.size()-1; i>=0; i--)
		ans += s[i];
	return ans;
}

int main(){
	string a, b;
	cin >> a >> b;
	
	a = reverse(a);
	b = reverse(b);
	
	int x = stoi(a);
	int y = stoi(b);
	
	cout << max(x, y) << '\n';
}
