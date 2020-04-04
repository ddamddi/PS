#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    for(int i = 0; i < input; i++){
        for(int j = i; j > 0; j--)
            cout << " ";
        for(int k = input - i; k > 0; k--)
            cout << "*";
        cout << endl;
    }
    
    return 0;
}
