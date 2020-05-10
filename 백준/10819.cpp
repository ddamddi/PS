#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
    	int tmp;
    	cin >> tmp;
    	v.push_back(tmp);	
	}
    sort(v.begin(), v.end());
    
    int max = 0;
    do{
    	int sum = 0;
    	for(int i=0; i<v.size()-1; i++)
    		sum += abs(v[i] - v[i+1]);
    	if(sum > max) max = sum;
    	
	}while(next_permutation(v.begin(), v.end()));
	
	cout << max << '\n';
}
