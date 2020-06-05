#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[11];
int op[4], used[4];
vector <int> ans;
int n;

int calculate(int sub_result, int i, int n){
	int result;
	switch(i){
		case 0:
			result = sub_result + n;
			break;
		case 1:
			result = sub_result - n;
			break;
		case 2:
			result = sub_result * n;
			break;
		case 3:
			if(result < 0){
				result = -result;
				result = sub_result / n;
				result = -result;
			}
			else
				result = sub_result / n;
	}
	return result;
}

void dfs(int x, int sub_result){
	if(x >= n-1){
		ans.push_back(sub_result);
		return;
	}
	
	for(int i=0; i<4; i++){
		if(op[i] > used[i]){
			used[i]++;
			int new_sub_result = calculate(sub_result, i, num[x+1]);
			dfs(x+1, new_sub_result);
			used[i]--;
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> num[i];
	for(int i=0; i<4; i++)
		cin >> op[i];
	
	dfs(0, num[0]);
		
	sort(ans.begin(), ans.end());
	cout << ans[ans.size()-1] << '\n';
	cout << ans[0] << '\n';
	return 0;
}
