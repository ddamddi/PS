#include <iostream>
using namespace std;

int main(){
	int n, divider = 2;
	cin >> n;
	
	while(n != 1){
		if(n % divider == 0){
			cout << divider << '\n';
			n /= divider;
		}
		else
			divider++;
	}
	return 0;
}
