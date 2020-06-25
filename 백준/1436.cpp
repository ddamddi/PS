#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, cnt=0, num=666;
	cin >> n;
	
	while(1){
		string str = to_string(num);
		if(str.find("666") != string::npos)
			cnt++;
		
		if(cnt == n){
			cout << num << '\n';
			break;
		}
		else
			num++;
	}
	return 0;
}
