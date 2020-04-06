#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	for(int i=0; i<s.size(); i++){
		unsigned char tmp = s[i];
		if(s[i] >= 'a' && s[i] <= 'z'){
			tmp += 13;
			if(tmp > 'z')
				tmp -= 26;
			s[i] = tmp;
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			tmp += 13;
			if(tmp > 'Z')
				tmp -= 26;
			s[i] = tmp;
		}
	}
	cout << s;
}
