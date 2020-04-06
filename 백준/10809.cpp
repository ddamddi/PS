#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	for(int i=0; i<26; i++)
		cout << s.find('a'+i) << ' ';
	
	return 0;
}
