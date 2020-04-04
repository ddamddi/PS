#include <iostream>
#include <string>
#define MOD 1000000
using namespace std;

long long dp[5001];

int main(){
	string password;
	cin >> password;
	int N = password.length();
	int now, mask;
    
	if(password[0] == '0') {
		cout << "0" << '\n';
	}
	else{
        dp[0] = dp[1] = 1;
        
		for(int i = 2; i <= N; i++){
			now = i-1;
			if(password[now] > '0')
				dp[i] += dp[i-1];
			
			mask = (password[now-1] - '0') * 10 + (password[now] - '0');
			if(mask >= 10 && mask <= 26){
				dp[i] += dp[i-2] % MOD;
			}
		}
	
		cout << dp[N] % MOD << '\n';
	}
	return 0;
}
