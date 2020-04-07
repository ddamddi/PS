#include <iostream>
#include <cstring>
using namespace std;

void vps(string s){
	int x=0;
	for(int i=0; i<s.size(); i++){
		if(x < 0)
			break;
		
		if(s[i] == '(')
			x++;
		else if(s[i] == ')')
			x--;
	}
	if(x == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}


int main(){
	int T;
	string s;
	cin >> T;
	for(int t=0; t<T; t++){
		cin >> s;
		vps(s);
	}
}
