#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    string str;
    
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> str;
        cout << (str[0] - '0') + (str[2] - '0') << endl;
    }
    
    return 0;
}
