#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	bool alphabets[26];
	int group_words = n;
	
	for(int i=0; i<n; i++){
		fill(alphabets, alphabets+26, false);
		string tmp;
		cin >> tmp;
		char prev = tmp[0];
		alphabets[prev-'a'] = true;
		for(int j=1; j<tmp.size(); j++){
			if(tmp[j] == prev)
				continue;
			
			if(alphabets[tmp[j] - 'a']){
				group_words--;
				break;
			}
			else {
				prev = tmp[j];
				alphabets[tmp[j] - 'a'] = true;
			}
		}
	}
	
	cout << group_words << '\n';
	return 0;
}
