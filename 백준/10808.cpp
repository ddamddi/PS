#include <iostream>
#include <cstring>
using namespace std;

int alphabet[26];

int main(){
	string s;
	cin >> s;
	
	for(auto c: s)
		alphabet[c - 'a']++;
		
	for(auto c: alphabet)
		printf("%d ", c);
}
