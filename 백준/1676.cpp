/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(){
	int n, two, five;
	cin >> n;
	two = five = 0;
	
	for(int i=2; i<=n; i*=2)
		two += n/i;
	
	for(int i=5; i<=n; i*=5)
		five += n/i;
		
	cout << ( (two < five)? two:five ) << endl;
}
