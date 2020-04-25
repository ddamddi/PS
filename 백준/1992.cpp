#include <iostream>
#include <cstring>
#define MAX_NUM 64
using namespace std;

int arr[MAX_NUM][MAX_NUM];
int n;

string dnq(int x, int y, int term){
	bool isSame = true;
	int num = arr[x][y];
	
	for(int i=0; i<term; i++){
		for(int j=0; j<term; j++){
			if(arr[x+i][y+j] != num)
				isSame = false;
		}
	}
	
	if(isSame)
		return to_string(num);
	else{
		return "(" + dnq(x, y, term/2) + dnq(x, y+term/2, term/2) + dnq(x+term/2, y, term/2) + dnq(x+term/2, y+term/2, term/2) + ")";
	}
}

int main(){
	cin >> n;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<n; j++){
			arr[i][j] = s[j] - '0';
		}
	}
	cout << dnq(0,0,n) << '\n';
}
