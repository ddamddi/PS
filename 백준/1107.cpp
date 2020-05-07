#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isBroken[10];


int isPossible(int num){
	if(num == 0){
		if(isBroken[0])
			return false;
		else
			return true;	
	}
	while(num > 0){
		if(isBroken[num % 10])
			return false;
		num /= 10;
	}
	return true;
}


int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int channel, n, current=100;
	cin >> channel >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		isBroken[tmp] = true;
	}
	
	int answer = abs(channel - 100);
	for(int i=0; i<=1000000; i++){
		if(isPossible(i)){
			int pushes = to_string(i).size();
			if(pushes > 0){
				int c = pushes + abs(channel-i);
				answer = (answer < c) ? answer : c;
			}
		}
	}
	
	cout << answer << endl;
}
