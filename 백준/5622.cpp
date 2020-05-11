#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int seconds = 0;
	for(int i=0; i<s.size(); i++){
		int d = s[i] - 'A';
		if(d < 3)
			seconds += 3;
		else if (d < 6)
			seconds += 4;
		else if (d < 9)
			seconds += 5;
		else if (d < 12)
			seconds += 6;
		else if (d < 15)
			seconds += 7;
		else if (d < 19)
			seconds += 8;
		else if (d < 22)
			seconds += 9;
		else
			seconds += 10;	
	}
	
	cout << seconds << '\n';
	return 0;
}
