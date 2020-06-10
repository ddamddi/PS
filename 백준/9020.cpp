#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[10001];

void goldbach_partition(int n){
	vector<int> v;
	
	for(int i=2; i<=n/2; i++){
		int x=n-i;
		if(arr[i] && arr[n-i])
			v.push_back(n-i-i);
	}
	sort(v.begin(),v.end());
	
	cout << (n-v[0])/2 << " " << (n-v[0])/2 + v[0] << '\n';
}

void prime_number(){
	fill(arr, arr+10001, true);
	arr[0] = arr[1] = false;
	for(int i=2; i<=10000; i++){
		if(arr[i] == true){
			int x = i+i;
			while(x <= 10000){
				arr[x] = false;
				x+=i;
			}
		}
	}
}

int main(){
	prime_number();
	
	int T;
	cin >> T;
	for(int testcase=1; testcase<=T; testcase++){
		int n;
		cin >> n;
		
		goldbach_partition(n);
	}
	
	return 0;
}
