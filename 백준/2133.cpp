#include <iostream>
using namespace std;

long long arr[31];

int main(){
	int N;
	cin >> N;
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
	
	for(int i = 3; i <= N; i++){
		if(i % 2 == 1)
			arr[i]= 0;
		else {
			arr[i] = arr[i-2];
			for(int j = i-2; j >= 0; j-=2)
				arr[i] += arr[j]*2;
		}
	}
	
	cout << arr[N] << '\n';
	return 0;
}
