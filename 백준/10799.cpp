#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int ans=0, bar=0;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '('){
			if(s[i+1] == ')')	// LASER ���� �� 
				ans += bar;
			else				// s[i+1] == '(' : ���ο� �踷��� ���ö� 
				bar++;
		}
		else {					// s[i] == ')' : LASER  
			if(s[i-1] == '('){
				continue;	
			}
			else{				// s[i-1] == ')' : �踷��� �� 
				bar--;
				ans+=1;
			}
		}
	}
	
	cout << ans;	
}
