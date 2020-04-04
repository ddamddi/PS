#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    string N;
    int B, ans = 0;
    cin >> N >> B;

    for(int i=0; i<N.size(); i++){
        if(N[N.size()-1-i] >= 'A')
            ans += (N[N.size()-1-i] - 'A' + 10) * pow(B, i);
        else
            ans += (N[N.size()-1-i] - '0') * pow(B, i);
    }

    cout << ans;
}