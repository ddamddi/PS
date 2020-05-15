#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	if(c-b <= 0){
		cout << -1 << '\n';
	}
	else{
		int breakEvenPoint = a / (c-b);
		breakEvenPoint++;
		cout << breakEvenPoint << '\n';
	}
	
	return 0;
}
