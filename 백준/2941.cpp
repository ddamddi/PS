#include <iostream>
using namespace std;

string croatian[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
	string s;
	cin >> s;
	int num_of_alphabets = 0;
	
	for(int i=0; i<s.length(); i++){
		for(int j=0; j<8; j++){
			if(s.substr(i, croatian[j].length()) == croatian[j]){
				i += (croatian[j].length()-1);
				break;
			}
		}
		num_of_alphabets++;
	}
	
	cout << num_of_alphabets << '\n';
	return 0;
}
