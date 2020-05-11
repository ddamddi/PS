#include <iostream>
#define WHITESPACE false
#define ALPHABETS true
using namespace std;

int main(){
	string s;
	getline(cin, s);
	
	int loc = 0, words = 0;
	bool state = WHITESPACE;
	while(loc < s.length()){
		if(state == ALPHABETS){
			if(s[loc] == ' '){
				state = WHITESPACE;
			}
		}
		else{
			if(s[loc] != ' '){
				state = ALPHABETS;
				words++;
			}
		}
		loc++;
	}
	cout << words << '\n';
	return 0;
}
