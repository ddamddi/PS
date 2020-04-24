#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    float sum = 0, max = 0;
    for(int i=0; i<n; i++){
        float tmp;
        cin >> tmp;
        sum += tmp;
        
        if(tmp > max)
            max = tmp;
    }

    cout << (double)(sum/max*100)/n << '\n';
}