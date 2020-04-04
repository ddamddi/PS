#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <char> v;
	int n, b, r;
	cin >> n >> b;
	
	while(n != 0){
		r = n%b;
		if(r > 9)
			v.push_back('A' + r - 10);	
		else
			v.push_back('0' + r);
		
		n /= b;
	}
	
	for(int i=v.size()-1; i >= 0; i--)
		cout << v[i];
}
