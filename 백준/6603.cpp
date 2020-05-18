#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int k;
	cin >> k;
	while(1){
		if(k==0)
			break;
		
		vector <int> v;
		vector <bool> select;
		for(int i=0; i<k; i++){
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			select.push_back(0);
		}
		sort(v.begin(), v.end());
		
		for(int i=0; i<6; i++)
			select[i] = 1;
		
		do{
			for(int i=0; i<k; i++){
				if(select[i] == 1)
					cout << v[i] << ' ';
			}
			cout << '\n';
			
		} while(prev_permutation(select.begin(), select.end()));
		
		cin >> k;
		cout << '\n';
	}

	return 0;	
}
