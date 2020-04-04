#include <iostream>
#include <cstring>
using namespace std;

string b2h[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main(){
    string tmp, bin;
    cin >> tmp;

    if (tmp == "0")
        cout << 0;

    for(int i=0; i<tmp.size(); i++){
        bin += b2h[tmp[i]-'0'];
    }

    int idx=0;
    while(1){
        if(bin[idx] != '0')
            break;
        idx++;
    }

    cout << bin.substr(idx, bin.size());
}