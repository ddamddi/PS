#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool check(string s){
	int v, c;
	v = c = 0; 
	
	for(int i=0; i<s.size(); i++){
		bool v_flag = false;
		for(int j=0; j<5; j++){
			if(vowel[j] == s[i]){
				v_flag = true;
				v++;
			}
		}
		if(!v_flag)
			c++;
	}
	if(c >= 2 && v >= 1)
		return true;
	return false;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int l, c;
	cin >> l >> c;
	vector<char> alphabets;
	vector<int> flag;
	vector<string> s;
	for(int i=0; i<c; i++){
		char tmp;
		cin >> tmp;
		alphabets.push_back(tmp);	
	}
	
	for(int i=0; i<l; i++)
		flag.push_back(1);
	for(int i=0; i<c-l; i++)
		flag.push_back(0);
		
	sort(alphabets.begin(),alphabets.end());
	
//	for(auto x: alphabets)
//		cout << x;
	
	do{
		string str = "";
		for(int i=0; i<flag.size(); i++){
			if(flag[i]){
				string tmp_s(1, alphabets[i]);
				str += tmp_s;
			}			
		}
		if(check(str))
			cout << str << '\n';
		
	}while(prev_permutation(flag.begin(), flag.end()));

	return 0;
}
