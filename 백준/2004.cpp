/*
문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.
*/
#include <iostream>
using namespace std;

int main(){
	long long i, n, m, two, five;
	cin >> n >> m;
	
	two = five = 0;
	
	for(i=2; i<=n; i*=2)
		two += n/i;
	for(i=5; i<=n; i*=5)
		five += n/i;
	
	for(i=2; i<=m; i*=2)
		two -= m/i;
	for(i=5; i<=m; i*=5)
		five -= m/i;
	
	for(i=2; i<=n-m; i*=2)
		two -= (n-m)/i;
	for(i=5; i<=n-m; i*=5)
		five -= (n-m)/i;
		
	cout << ( (two < five)? two : five ) << endl;
	return 0;
}
