#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A, B, t, tmp, dec = 0;
    vector <int> ans;
    cin >> A >> B >> t;

    for(int i=0; i<t; i++){
        cin >> tmp;
        dec *= A;
        dec += tmp;
    }

    if (dec == 0)
        ans.push_back(0);

    int r;
    while(1){
        if(dec == 0)
            break;
        r = dec % B;
        ans.push_back(r);
        dec /= B;
    }

    for(int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";
}