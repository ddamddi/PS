#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(2,0));

    for(int i=0; i<N; i++)
        cin >> v[i][1] >> v[i][0];
    
    sort(v.begin(), v.end());

    for(auto p: v)
        cout << p[1] << ' ' << p[0] << '\n';
        
}