#include <iostream>
using namespace std;

int T, N;
int p[1001];
bool visit[1001];

void dfs(int node);
void pCycle();
void init();

int main(){
	cin >> T;
	for(int test_case=1; test_case <= T; test_case++){
		cin >> N;
		init();
		pCycle();
	}
	
	return 0;
}

void dfs(int node){
	int child = p[node];
	visit[node] = true;
	
	if(visit[child] == false){
		visit[child] = true;
		dfs(child);
	}
}

void pCycle(){
	for(int i=1; i<=N; i++)
		cin >> p[i];
	
	int cycle=0; 
	for(int i=1; i<=N; i++){
		if(visit[i]==false){
			dfs(i);
			cycle++;
		}
	}
	cout << cycle << '\n';
}

void init(){
	fill(visit, visit+1001, false);
	fill(p, p+1001, 0);
}
