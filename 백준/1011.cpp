#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		long long x,y;
		cin>>x>>y;
		long distance = y-x;
		
		long long i = 1, cnt;
		while(1){
			if(i*i > distance)
				break;
			i++;
		}
		
		if((i-1)*(i-1) == distance)
			cnt = 2*(i-1) - 1;
		else if((i-1)*(i-1) + (i*i-(i-1)*(i-1))/2 >= distance)
			cnt = 2*(i-1);
		else
			cnt = 2*i - 1;
		
		cout << cnt << '\n';
	}
	
	return 0;
}
