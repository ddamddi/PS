#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visit[1001];

void bfs(int node);
void dfs(int node);
void init();

int main(){
	cin >> N >> M >> V;
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i=1; i<=N; i++)
		sort(graph[i].begin(), graph[i].end());
	
	init();
	dfs(V);
	cout << endl;
	init();
	bfs(V);
	
	return 0;
}

void bfs(int node){
	
	queue<int> q;
	q.push(node);
	visit[node] = true;
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		cout << current << ' ';
		
		for(int i=0; i<graph[current].size(); i++){
			int tmp = graph[current][i];
			if(visit[tmp]==false){
				q.push(tmp);
				visit[tmp]=true;
			}
		}
	}
	cout << endl;
}

void dfs(int node){
	cout << node << ' ';
	visit[node]=true;
	
	for(int i=0; i<graph[node].size(); i++){
		int child = graph[node][i];
		if(visit[child] == false){
			visit[child] = true;
			dfs(child);
		}
	}
}

void init(){
	fill(visit, visit+N+1, false);
}
