#include <iostream>
#include <queue>
#define MAX_SIZE 1002
using namespace std;

int N,M;
int arr[MAX_SIZE][MAX_SIZE];
int x_move[4] = {-1, 0, 1, 0};
int y_move[4] = {0, 1, 0, -1};

void printAll(){
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int tomatoes(){
	queue<pair<int,int> > q;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(arr[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	
	int updates, days = 0;
	while(1){
//		cout << '\n' << "###### DAY " << days << " ######" << '\n';
//		printAll();
		
		updates = 0;
		int s = q.size();
		for(int i=0; i<s; i++){
			pair<int, int> current = q.front();
			int current_x = current.first;
			int current_y = current.second;
			q.pop();
			
			for(int j=0; j<4; j++){
				if(arr[current_x + x_move[j]][current_y + y_move[j]] == 0){
					q.push(make_pair(current_x + x_move[j], current_y + y_move[j]));
					arr[current_x + x_move[j]][current_y + y_move[j]] = 1;
					updates++;
				}
			}
		}
		
		if(updates == 0 && q.size() == 0)
			return days;
		else
			days++;

	}	
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	bool isAllRipe = true;
	int days;
	cin>>M>>N;
	fill(&arr[0][0], &arr[MAX_SIZE-1][MAX_SIZE], -1);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> arr[i][j];
		}
	}
	
	days = tomatoes();
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(arr[i][j] == 0)
				isAllRipe = false;
		}
	}
	
	cout << (isAllRipe ? days : -1) << '\n';
}
