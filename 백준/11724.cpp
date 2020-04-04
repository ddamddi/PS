#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<int> node[], bool check[]){
	queue<int> q;
	q.push(start);
	check[start] = true;
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		
		for(int i=0; i<node[current].size(); i++){
			if(check[node[current][i]] == false){
				q.push(node[current][i]);
				check[node[current][i]] = true;
			}
		}
	}
}

int main(){
	int N, M;
	cin >> N >> M;
	
	vector<int> graph[N+1];
	bool check[N+1];
	fill(check, check+N+1, false);
	
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int component=0;
	for(int i=1; i<=N; i++){
		if(check[i] == false){
			bfs(i, graph, check);
			component++;
		}
	}
	
	cout << component << "\n";
	return 0;
}
