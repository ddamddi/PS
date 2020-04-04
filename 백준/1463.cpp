#include <iostream>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
using namespace std;

int table[1000001];

int memo(int x){
	int tmp, ans;
	
	if(x == 0 || x == 1)
		return 0;
	
	if(table[x] != 0)
		return table[x];
	
	table[x] = memo(x-1) + 1;
	
	if(x % 3 == 0)
		table[x] = MIN(table[x], memo(x/3) + 1);
	if(x % 2 == 0)
	table[x] = MIN(table[x], memo(x/2) + 1);
	
	return table[x];
}

int main(){
	table[0] = table[1] = 0;
	int N;
	cin >> N;
	cout << memo(N);
	
	return 0;
}
