#include <iostream>
#define MAX 100
using namespace std;

int arr[MAX];

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(){
	int T, n;
	long long sum = 0;
	cin >> T;
	
	for(int t=0; t<T; t++){
		sum = 0;
		
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
