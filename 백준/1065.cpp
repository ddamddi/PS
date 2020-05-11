#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int cnt = 0;
	for(int i=1; i<=n; i++){
		string s = to_string(i);
		if(s.length() < 3){
			cnt++;
			continue;
		}
		int dist = s[0] - s[1];
		bool isHansu = true;
		for(int i=1; i<s.length()-1; i++){
			if(dist != s[i] - s[i+1]){
				isHansu = false;
				break;
			}
		}	
		if(isHansu)
			cnt++;
	}
	cout << cnt << '\n';
}
