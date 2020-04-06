#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, k;
	vector<int> v, ans;
	cin >> n >> k;

	for(int i=0; i<n; i++)
		v.push_back(i+1);
	
	int current = 0;
	while(v.size() != 0){
		current += k-1;
		current %= v.size();
		ans.push_back(v[current]);
		v.erase(v.begin()+current);			
	}
	
	cout << "<";
	for(int i=0; i<n-1; i++)
		cout << ans[i] << ", ";
	cout << ans[n-1] << ">";
}
