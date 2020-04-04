#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, P;
vector<int> v;
vector<int>::iterator it;

int nextNum(int num);

int main(){
	cin >> A >> P;
	v.push_back(A);
	int next = nextNum(A);
	while(1){
		it = find(v.begin(),v.end(), next);
		
		if(it != v.end()){
			cout << it - v.begin() << '\n';
			break;
		}
		
		v.push_back(next);
		next = nextNum(next);		
	}
	
	return 0;
}

int nextNum(int num){
	int ans = 0, sub_ans = 0;
	
	while(num != 0){
		int tmp = num % 10;
		num /= 10;
		sub_ans = tmp;
		
		for(int i=1; i<P; i++)
			sub_ans = sub_ans * tmp;
		
		ans += sub_ans;
	}
	return ans;
}
