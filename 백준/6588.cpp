#include <iostream>
#define MAX_NUM 1000001
using namespace std;

int n, a, checked=2;

int main(){
	bool* arr = new bool[MAX_NUM];
	fill(arr, arr+MAX_NUM, true);
	arr[0] = arr[1] = false;

	while(1){	
		scanf("%d", &n);
		a = -1;
		if(n == 0)
			break;
			
		if(checked < n){
			for(int i=checked+1; i<n; i+=2){
				if(arr[i]){
					int j=3;
					while(i*j <= MAX_NUM){
						arr[i*j] = false;
						j+=2;
					}
				}
			}			
			checked = n;	
		}
		
		for(int i=3; i<=n/2; i+=2){
			if(arr[i] && arr[n-i]){
				a = i;
				break;
			}		
		}
		
		if(a == -1)
			printf("Goldbach's conjecture is wrong.\n");
		else
			printf("%d = %d + %d\n", n, a, n-a);
	}
}
