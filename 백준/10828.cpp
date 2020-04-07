#include <iostream>
#include <cstring>
#define MAX_NUM 10000
using namespace std;

int s[MAX_NUM];

int main(){
	int n, top=-1;
	cin >> n;
	
	string cmd;
	while(n--){
		cin >> cmd;
		if(cmd == "top"){
			if (top < 0)
				cout << -1 << '\n';
			else
				cout << s[top] << '\n';
		}
		else if(cmd == "empty")
			cout << ((top == -1) ? 1 : 0) << '\n';
		else if(cmd == "size")
			cout << top+1 << '\n';
		else if(cmd == "pop"){
			if(top > -1){
				cout << s[top] << '\n';
				top--;	
			}
			else
				cout << -1 << '\n';
		}
		else{
			int x;
			cin >> x;
			top++;
			s[top] = x;
		}
	}
}
