#include <iostream>
using namespace std;

int square[100][100];

long long sum(int s_x, int s_y, int f_x, int f_y){
    long long sum = 0;
    for(int i=s_x; i<=f_x; i++){
        for(int j=s_y; j<=f_y; j++){
            sum += square[i][j];
        }
    }
    return sum;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            square[i][j] = s[j] - '0';
        }
    }

    long long ans = 0;
    long long a,b,c;
    for(int i=0; i < m-1; i++){
        for(int j=i+1; j < m-1; j++){
            a = sum(0,0  ,n-1,i);
            b = sum(0,i+1,n-1,j);
            c = sum(0,j+1,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    for(int i=0; i < n-1; i++){
        for(int j=i+1; j < n-1; j++){
            a = sum(0  ,0,i  ,m-1);
            b = sum(i+1,0,j  ,m-1);
            c = sum(j+1,0,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            a = sum(0  ,0  ,j  ,i);
            b = sum(j+1,0  ,n-1,i);
            c = sum(0  ,i+1,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            a = sum(0  ,0  ,n-1,i);
            b = sum(0  ,i+1,j  ,m-1);
            c = sum(j+1,i+1,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){ 
            a = sum(0  ,0  ,i  ,j);
            b = sum(0  ,j+1,i  ,m-1);
            c = sum(i+1,0  ,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            a = sum(0  ,0  ,i  ,m-1);
            b = sum(i+1,0  ,n-1,j);
            c = sum(i+1,j+1,n-1,m-1);
            long long mul = a*b*c;
            ans = max(ans, mul);
        }
    }

    cout << ans << '\n';
    return 0;
}   