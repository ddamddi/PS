/*
����
nCm�� ���ڸ� 0�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n, m(0��m��n��2,000,000,000, n!=0)�� ���´�.

���
ù° �ٿ� 0�� ������ ����Ѵ�.
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
