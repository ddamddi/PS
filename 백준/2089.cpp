#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    long long n, r;
    string ans = "";
    cin >> n;

    while(n != 0){
    	r = n%-2;
    	n = n/-2;
    	
    	if(r < 0){
    		r+=2;
    		n+=1;
		}	
		ans += to_string(r);
	}
	
	if(ans.size() == 0)
		cout << 0 << endl;
	else{
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}
