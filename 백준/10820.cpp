#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		int a, b, c, d;
		a = b = c = d = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] >= 'a' && s[i] <= 'z')
				a++;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				b++;
			else if(s[i] >= '0' && s[i] <= '9')
				c++;
			else
				d++;
		}
		printf("%d %d %d %d\n",a,b,c,d);
	}
	
	return 0;
}
