#include <iostream>
using namespace std;

bool primeNumber[10001];

int main(){
    int m,n;
    cin>>m>>n;
    
    fill(primeNumber, primeNumber+10001, true);
    primeNumber[0] = primeNumber[1] = false;
    for(int i=2; i<=n; i++){
        if(primeNumber[i]){
            int j = i*2;
            while(j <= n){
//            	cout << j << " ";
                primeNumber[j] = false;
                j += i;
            }
        }
    }
    
    int min = 0, sum = 0; 
    for(int i=m; i<=n; i++){
        if(primeNumber[i]){
            sum += i;
            if(min == 0)
                min = i;
        }
    }
    
    if(min == 0)
    	cout << -1 << '\n';
    else{
    	cout << sum << '\n';
    	cout << min << '\n';
	}
    
    return 0;
}
