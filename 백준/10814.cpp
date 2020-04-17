#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, tmp;
    string tmp_s;
    cin >> N;
    vector<vector<string>> v(200);
    for(int i=0; i<N; i++){
        cin >> tmp >> tmp_s;
        v[tmp-1].push_back(tmp_s);
    }

    for(int i=0; i<200; i++){
        for(int j=0; j<v[i].size(); j++){
            cout << i+1 << " " << v[i][j] << '\n';
        }
    }
}
