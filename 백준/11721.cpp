#include <iostream>
#include <string>
using namespace std;

int main() {
    string st;
    int pos = 0, s_len, T;
    
    cin >> st;
    T = ((st.length() % 10 == 0) ? st.length()/10 : st.length()/10 + 1);
    for(int i = 0; i < T; i++){
    	s_len = st.length() - pos;
        cout << st.substr(pos, ((s_len < 10) ? s_len : 10)) << endl;
        pos+=10;
    }
    
    return 0;
}
