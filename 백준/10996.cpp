#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
    	if(n==1)
    		cout << '*' << '\n';
    	else{
    		for(int j=0; j<2; j++){
    			for(int k=0; k<n; k++){
    				if((j == 0 && k%2 == 0) || (j==1 && k%2 == 1))
    					cout << '*';
    				else
    					cout << ' ';
				}
				cout << '\n';
			}
		}
	}
    
    return 0;
}
