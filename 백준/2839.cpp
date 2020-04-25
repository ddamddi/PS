#include <iostream>
using namespace std;

int main(){
	int cnt=0, left;
	cin >> left;
	
	while(left > 0){
		if(left % 5 == 0){
			left -= 5;
			cnt++;
		}
		else if(left % 3 == 0){
			left -= 3;
			cnt++;
		}
		else if(left > 5){
			left -= 5;
			cnt++;
		}
		else{
			cnt = -1;
			break;
		}
	}
	cout << cnt << endl;
}
