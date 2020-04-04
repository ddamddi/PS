#include <iostream>
using namespace std;

bool isPrime(int n){
    int cnt = 0;
    for(int i = 1; i < n+1; i++){
        if(n % i == 0)
            cnt++;
    }
    if(cnt == 2)
        return true;
    else
        return false;
}

int main(){
    int N, x, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(isPrime(x))
            count++;
    }
    
    cout << count;
    return 0;
}
