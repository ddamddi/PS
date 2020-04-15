#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long long> v;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
//    for(auto x: v)
//    	cout << x << ' ';

    int cnt=1, best_cnt=0;
    long long pre_num = v[0], best = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i] == pre_num)
            cnt++;
        else{
            if(cnt > best_cnt){
                best_cnt = cnt;
                best = pre_num;
            }
            cnt = 1;
            pre_num = v[i];
        }
    }
    cout << best << '\n';

    return 0;
}
