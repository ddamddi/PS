#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    
    bool* checked = new bool[n+1];
    fill(checked, checked+n+1, true);
    checked[0] = checked[1] = false;
    
    for(int i=2; i<=n; i++){
    	if(checked[i]){
			int j=2;
			while(i*j <= n){
				checked[i*j] = false;
				j++;
			}	
		}
	}
	
	for(int i=m; i<n+1; i++){
		if(checked[i])
			cout << i << '\n';
	}	
}
