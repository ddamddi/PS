#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int synergy[21][21];
bool check[21] = {false,};
int n, ans = INF;

void bfs(int current, int cnt){
	if(cnt >= n/2){
		vector<int> team_start, team_link;
		
		for(int i=1; i<=n; i++){
			if(check[i])
				team_start.push_back(i);
			else
				team_link.push_back(i);
		}
		
		int stat_start = 0, stat_link = 0;
		for(int i=0; i<team_start.size(); i++){
			for(int j=i+1; j<team_start.size(); j++){
				int start_x = team_start[i], start_y = team_start[j];
				int link_x = team_link[i], link_y = team_link[j];
				stat_start += synergy[start_x][start_y]; 
				stat_start += synergy[start_y][start_x];
				stat_link += synergy[link_x][link_y];
				stat_link += synergy[link_y][link_x];
			}
		}
		
		ans = min(ans, abs(stat_start- stat_link));
		return;
	}
	
	for(int i=current+1; i<=n; i++){
		if(!check[i]){
			check[i] = true;
			bfs(i, cnt+1);
			check[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> synergy[i][j];
		}
	}
	
	bfs(0, 0);
	cout << ans << '\n';
	return 0;
}
