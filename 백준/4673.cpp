#include <iostream>
using namespace std;

bool num[10001];

int self_number(int n){
    int sum = n;
    while(n != 0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
    fill(num, num+10001, true);
    num[0] = false;
    for(int i=1; i<10001; i++){
    	if(num[i] == true){
    		int sn = self_number(i);
    		while(sn < 10001){
            	num[sn] = false;
            	sn = self_number(sn);
        	}
		}
    }
    
    for(int i=1; i<10001; i++){
    	if(num[i])
    		cout << i << '\n';
	}
	return 0;
}
