#include <iostream>
using namespace std;
int main(){
	int E, S, M, year;
	cin >> E >> S >> M;
	int e, s, m;
	e = s = m = year = 1;
	
	while(e != E || s != S || m != M){
		e++; s++; m++; year++;
		if(e == 16) e = 1;
		if(s == 29) s = 1;
		if(m == 20) m = 1;
	}
	
	cout << year << '\n';
	
	return 0;
}
