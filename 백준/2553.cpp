#include <iostream>
using namespace std;

int main(){
	unsigned long long a=1;
	int n;
	cin >> n;	
	for(int i=1; i<=n; i++){
		a *= i;
		while(a % 10 == 0)
			a /= 10;
		a %= 1000000000000;
	}
	cout << a % 10 << '\n';
}
