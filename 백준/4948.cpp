#include <iostream>
#define MAX_NUMBER 123456*2+1
using namespace std;

bool primeNumber[MAX_NUMBER];

int main(){    
    fill(primeNumber, primeNumber+MAX_NUMBER, true);
    primeNumber[0] = primeNumber[1] = false;
    for(int i=2; i<=MAX_NUMBER; i++){
        if(primeNumber[i]){
            int j = i*2;
            while(j <= MAX_NUMBER){
                primeNumber[j] = false;
                j += i;
            }
        }
    }
    int n;
    cin >> n; 
    while(n != 0){
    	int cnt = 0;
    	for(int i=n+1; i<=2*n; i++){
    		if(primeNumber[i])
    			cnt++;
		}
    	cout << cnt << '\n';
    	cin >> n;
	}
    return 0;
}
