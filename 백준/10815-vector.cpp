#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bs(vector<int> v, int min, int max, int k){
	if(max < min)
		return false;
	
	int mid = (min+max)/2;
	if(v[mid] < k)
		return bs(v, mid+1, max, k);
	else if(v[mid] > k)
		return bs(v, min, mid-1, k);
	else
		return true;
}

int main(){
	cin.tie(0);
	cout.tie(0);
    ios_base::sync_with_stdio(false);
	int n,m;
	vector <int> mycard;
	
	cin >> n;	
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		mycard.push_back(tmp);
	}
	sort(mycard.begin(), mycard.end());
	
	cin >> m;
	for(int i=0; i<m; i++){
		int tmp;
		cin >> tmp;
		cout << (bs(mycard, 0, n-1, tmp) ? 1 : 0) << ' ';	
	}
	return 0;
}
