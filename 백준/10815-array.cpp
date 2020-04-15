#include <iostream>
#include <algorithm>
using namespace std;

bool bs(int* mycard, int min, int max, int k){
	if(max < min)
		return false;
	
	int mid = (min+max)/2;
	if(mycard[mid] < k)
		return bs(mycard, mid+1, max, k);
	else if(mycard[mid] > k)
		return bs(mycard, min, mid-1, k);
	else
		return true;
}

int main(){
	cin.tie(0);
	cout.tie(0);
    ios_base::sync_with_stdio(false);
	int n,m;
	
	cin >> n;
	int* mycard = new int[n];
	for(int i=0; i<n; i++)
		cin >> mycard[i];
	sort(mycard, mycard+n);
	
	cin >> m;
	int tmp;
	int * ans = new int[m];
	for(int i=0; i<m; i++){
		cin >> tmp;
		ans[i] = bs(mycard, 0, n-1	, tmp) ? 1 : 0;	
	}
	
	for(int i=0; i<m; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
