#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < N-i; j++)		cout << " ";
		if(i > 1 && i < N){
			cout << "*";
			for(int j = 0; j < 2*i-3; j++)		cout << " ";
			cout << "*";
		}
		else if(i == N)
			for(int j = 0; j < 2*N-1; j++)	cout << "*";
		else
			cout << "*";
		if(i != N)
			cout << endl;
	}
	
	return 0;
}
