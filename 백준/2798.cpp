#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int card[100];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> card[i];
	
	vector<int> v;
	
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				int sum = card[i] + card[j] + card[k];
				if(sum <= m)
					v.push_back(sum);
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << v[v.size()-1] << '\n';
	return 0;
}
