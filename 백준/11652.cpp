#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    
    int cnt=1, max_count=0;
    long long max_num, current_num = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] == current_num)
            cnt++;
        else{
            if(cnt > max_count){
                max_count = cnt;
                max_num = current_num;
            }
            cnt = 1;
            current_num = arr[i];
        }
    }

    // 한번더 check
    // e.g. 7 (1 1 2 2 3 3 3) 일 때
    if(cnt > max_count){
        max_count = cnt;
        max_num = current_num;
    }
    
    cout << max_num << '\n';
}