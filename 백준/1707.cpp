#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 20001
#define RED 1
#define BLUE -1
using namespace std;

vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];
bool isBipartite;

void bfs(int x, int color){
	queue<int> q;
	q.push(x);
	visited[x] = color;
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		
		for(int i=0; i<graph[current].size(); i++){
			if(visited[graph[current][i]] == 0){
				visited[graph[current][i]] = visited[current] * -1;
				q.push(graph[current][i]);
			}
			else if(visited[graph[current][i]] + visited[current] != 0){
				isBipartite = false;
				return;
			}
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int t, v, e;
	cin >> t;
	while(t--){
		cin >> v >> e;
		isBipartite = true;
		int x, y;
		for(int i=0; i<e; i++){
			cin >> x >> y;
			
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		

		for(int i=0; i<MAX_SIZE; i++){
			if(visited[i] == 0)
				bfs(i, RED);
		}
		cout << (isBipartite ? "YES" : "NO") << '\n';
		
		// graph, visited ÃÊ±âÈ­ 
		for(int i=0; i<MAX_SIZE; i++)
			graph[i].clear();
		fill(visited, visited+MAX_SIZE, 0);
	}
	return 0;
}
