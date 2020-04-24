#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int cnt = 0;

void hanoi(int n, int from, int tmp, int to){
    cnt++;
    if(n==1)
        v.push_back(make_pair(from, to));
    else{
        hanoi(n-1, from, to ,tmp);
        v.push_back(make_pair(from, to));
        hanoi(n-1, tmp, from, to);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << cnt << '\n';
    for(auto x: v)
        cout << x.first << " " << x.second << '\n';
}