#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		int h,w,n;
		cin >> h >> w >> n;
		
		int floor = (n % h);
		int num = (n / h);
		
		if(floor <= 0)
			floor = h;
		else
			num++;
				
		cout << floor * 100 + num << '\n';
	}
}
