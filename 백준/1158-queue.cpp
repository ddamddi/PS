#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, k;
	queue<int> q;
	cin >> n >> k;
	
	for(int i=0; i<n; i++)
		q.push(i+1);
	
	cout << "<";
	for(int i=0; i<n; i++){
		if(q.size() == 1){
			cout << q.front();
			break;
		}
		
		for(int j=0; j<k-1; j++){
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front() << ", ";
		q.pop();
	}
	cout << ">";
}
