#include <iostream>
using namespace std;

int main(){
	int N, min, max, tmp;
	cin >> N;
	
	cin >> tmp;
	max = min = tmp;
	
	for(int i = 1; i < N; i++){
		cin >> tmp;
		if(max < tmp)	max = tmp;
		if(min > tmp)	min = tmp;
	}
	
	cout << min << " " << max << endl;
	
	return 0;
}
