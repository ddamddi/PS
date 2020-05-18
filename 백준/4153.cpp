#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    while(a+b+c != 0){
        int heru = max(max(a,b),c);
        if((pow(a,2) + pow(b,2) + pow(c,2)) == (pow(heru,2) * 2))
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
        cin>>a>>b>>c;
    }
}
