#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int ans=0, bar=0;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '('){
			if(s[i+1] == ')')	// LASER 나올 때 
				ans += bar;
			else				// s[i+1] == '(' : 새로운 쇠막대기 나올때 
				bar++;
		}
		else {					// s[i] == ')' : LASER  
			if(s[i-1] == '('){
				continue;	
			}
			else{				// s[i-1] == ')' : 쇠막대기 끝 
				bar--;
				ans+=1;
			}
		}
	}
	
	cout << ans;	
}
