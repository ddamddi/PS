#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a,b) << '\n';
	}
}
