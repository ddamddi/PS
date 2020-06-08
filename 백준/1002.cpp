#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		int x1,y1,r1,x2,y2,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		
		long long dx = x1-x2;
		long long dy = y1-y2;
		long long d = dx*dx + dy*dy;
		long long add = r1+r2;
		add = add * add;
		long long sub = r1-r2;
		sub = sub * sub;
		
		if(d == 0){
			if(r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(add == d || (sub == d && d != 0))
			cout << 1 << '\n';
		else if(sub < d && d < add)
			cout << 2 << '\n';
		else if(add < d || d < sub)
			cout << 0 << '\n';
			
	}
	
	return 0;
}
