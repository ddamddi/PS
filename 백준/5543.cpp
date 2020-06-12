#include <iostream>
using namespace std;

int main(){
    int burger, bev, tmp;
    burger = bev = 2001;
    for(int i=0; i<3; i++){
        cin >> tmp;
        burger = min(burger,tmp);
    }
    for(int i=0; i<2; i++){
        cin >> tmp;
        bev = min(bev, tmp);
    }
    
    cout << burger + bev - 50 << '\n';
    
    return 0;
}
