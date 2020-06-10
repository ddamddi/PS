#include <iostream>
using namespace std;

int main(){
	int n, cnt=1, stage=6;
	cin>>n;
	
	n--;
	while(n > 0){
		cnt++;
		n -= stage;
		stage += 6;
	}
	
	cout << cnt << '\n';
	return 0;
}
