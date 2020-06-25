#include <iostream>
#include <vector>
#define MAX 4000000
using namespace std;

bool isPrime[MAX+1];

int main(){
	fill(isPrime+2, isPrime+MAX+1, true);
	long long n, answer=0;
	cin >> n;
	
	for(long long i=2; i<=n; i++){
		if(!isPrime[i])
			continue;
		for(long long j=i*i; j<=n; j+=i)
			isPrime[j] = false;
	}
	
	vector <int> prime;
	for(int i=0; i<=n; i++){
		if(isPrime[i])
			prime.push_back(i);
	}
	
	int start = 0, end = 0, sum = 0;
	while(1){
		if(sum == n)
			answer++;
		
		if(sum < n){
			if(end == prime.size())
				break;
			sum += prime[end++];
		}
		else if(sum >= n){
			sum -= prime[start++];
		}
	}
	cout << answer << '\n';
	return 0;
}
