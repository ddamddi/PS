/*
����
N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (0 �� N �� 500)

���
ù° �ٿ� ���� 0�� ������ ����Ѵ�.
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
