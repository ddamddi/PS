#include <iostream>
using namespace std;

int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin>>n>>m>>k;
	
	int numOfTeam = 0;
	while(1){
		if((n-2)+(m-1) < k)
			break;
		else{
			if(n>=2 && m>=1){
				n-=2;
				m--;
				numOfTeam++;
			}
			else
				break;
		}
	}
	
	cout << numOfTeam << '\n';
}
