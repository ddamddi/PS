#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int testcase=0; testcase<t; testcase++){
    	int n;
    	cin >> n;
    	unsigned long long a=1;
    	for(int i=1; i<=n; i++){
    		a *= i;
    		while(a % 10 == 0)
    			a /= 10;
    		a %= 1000000000000;
		}
		cout << a % 10 << '\n';
	}
}
