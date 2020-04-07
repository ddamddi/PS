#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	int n;
	stack<int> s;
	cin >> n;
	
	string cmd;
	while(n--){
		cin >> cmd;
		if(cmd == "top"){
			if(!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';			
		}
		else if(cmd == "empty")
			cout << (s.empty() ? 1 : 0) << '\n';
		else if(cmd == "size")
			cout << s.size() << '\n';
		else if(cmd == "pop"){
			if(s.empty())
				cout << -1 << '\n';
			else{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else{
			int x;
			cin >> x;
			s.push(x);
		}
	}
}
