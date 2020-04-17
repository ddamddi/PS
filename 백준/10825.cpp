#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{   
    string name;
    int kor, eng, math;
};

bool cmp(student a, student b){
    if(a.kor > b.kor)
        return true;
    else if(a.kor == b.kor){
        if(a.eng < b.eng)
            return true;
        else if(a.eng == b.eng){
            if(a.math > b.math)
                return true;
            else if(a.math == b.math){
                if(a.name < b.name)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<student> v;
    for(int i=0; i<n; i++){
        student tmp;
        cin >> tmp.name >> tmp.kor >> tmp.eng >> tmp.math;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    cout <<'\n' << '\n';
    for(auto s: v){
        cout << s.name << '\n';
    }
}