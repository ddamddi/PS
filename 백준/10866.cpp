#include <iostream>
#include <deque>
using namespace std;

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    deque <int> dq;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s == "push_front"){
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(s == "push_back"){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(s == "pop_front"){
            if(dq.size() == 0)
                cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(s == "pop_back"){
            if(dq.size() == 0)
                cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(s == "size")
            cout << dq.size() << '\n';
        else if(s == "empty")
            cout << dq.empty() << '\n';
        else if(s == "front"){
            if(dq.size() == 0)
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else {
            if(dq.size() == 0)
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }

    return 0;
}