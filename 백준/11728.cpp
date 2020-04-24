#include <iostream>
using namespace std;

void merge(int* arrA, int a, int* arrB, int b, int* arrC){
    int aa, bb, cc;
    aa = bb = cc = 0;

    while(aa < a || bb < b){
        if(aa == a){
            while(bb != b){
                arrC[cc++] = arrB[bb++];
            }
        }

        if(bb == b){
            while(aa != a){
                arrC[cc++] = arrA[aa++];
            }
        }

        if(arrA[aa] < arrB[bb]){
            arrC[cc++] = arrA[aa++];
        }
        else
            arrC[cc++] = arrB[bb++];
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int* arrA = new int[n];
    int* arrB = new int[m];
    int* arrC = new int[n+m];

    for(int i=0; i<n; i++)
        cin >> arrA[i];
    for(int i=0; i<m; i++)
        cin >> arrB[i];

    merge(arrA, n, arrB, m, arrC);

    for(int i=0; i<n+m; i++)
        cout << arrC[i] << ' ';
    
}