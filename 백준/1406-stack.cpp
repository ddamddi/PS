#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string s, cmd;
	int n;
	stack<char> front, rear;
	cin >> s >> n;
	
	for(int i=0; i<s.size(); i++)
		front.push(s[i]);
	
	for(int i=0; i<n; i++){
		cin >> cmd;
		if(cmd == "L"){
			if(front.size() != 0){
				rear.push(front.top());
				front.pop();
			}
		}
		else if(cmd == "D"){
			if(rear.size() != 0){
				front.push(rear.top());
				rear.pop();
			}
		}
		else if(cmd == "B"){
			if(front.size() != 0){
				front.pop();
			}
		}
		else{
			cin >> cmd;
			front.push(cmd[0]);
		}
	}
	
	while(!front.empty()){
		rear.push(front.top());
		front.pop();
	}
	
	while(!rear.empty()){
		cout << rear.top();
		rear.pop();
	}
	
}
