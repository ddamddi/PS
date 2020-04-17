#include <iostream>
#define MAX_NUM 10000
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, tmp;
    cin >> n;
    int arr[MAX_NUM];
    fill(arr, arr+MAX_NUM, 0);
    for(int i=0; i<n; i++){
        cin >> tmp;
        arr[tmp-1]++;
    }

    for(int i=0; i<MAX_NUM; i++){
        for(int j=arr[i]; j>0; j--)
            cout << i+1 << '\n';
    }
}