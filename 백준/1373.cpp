#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string tmp;
    cin >> tmp;

    if(tmp.length() % 3 == 1)
        // cout << tmp[0];
        tmp = "00" + tmp;
    else if(tmp.length() % 3 == 2)
        // cout << 2*(tmp[0] - '0') + (tmp[1]-'0'); 
        tmp = "0" + tmp;


    for(int idx=tmp.length()%3; idx < tmp.length(); idx+=3){
        int x = 4*(tmp[idx] -'0') + 2*(tmp[idx+1] -'0') + (tmp[idx+2] -'0');
        cout << x;
    }

}