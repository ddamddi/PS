#include <iostream>
#define MAX 500001
using namespace std;

long long ans = 0;
int arr[MAX];

void merge(int i, int mid, int j){
    int *sortArr = new int[j+1];

    int left = i;
    int right = mid+1;
    int sort_idx = left;

    int line_cnt = 0;
    long long swap_cnt = 0;
    while(left <= mid && right <= j){
        if(arr[left] <= arr[right]){
            sortArr[sort_idx++] = arr[left++];
            swap_cnt += line_cnt;
        }
        else{
            sortArr[sort_idx++] = arr[right++];
            line_cnt++;
        }
    }

    if(left > mid){
        while(right <= j){
            sortArr[sort_idx++] = arr[right++];
            line_cnt++;
        }
    }

    if(right > j){
        while(left <= mid){
            sortArr[sort_idx++] = arr[left++];
            swap_cnt += line_cnt;
        }
    }
    
    ans += swap_cnt;

    for(int k=i; k<=j; k++){
        arr[k] = sortArr[k];
    }
    
    delete(sortArr);
}

void divide(int i, int j){
    if(i < j){
        int mid = (i + j) / 2;
        
        divide(i, mid);
        divide(mid+1, j);
        merge(i, mid, j);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    divide(0, n-1);
    cout <<ans << '\n';
    return 0;
}