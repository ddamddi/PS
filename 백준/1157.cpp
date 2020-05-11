#include <iostream>
using namespace std;

int alphabets[26];

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            alphabets[s[i]-'a']++;
        else
            alphabets[s[i]-'A']++;
    }
    
    int max_idx = 0;
    for(int i=1; i<26; i++){
        if(alphabets[max_idx] < alphabets[i])
            max_idx = i;
    }
    
    int max_cnt = alphabets[max_idx], cnt = 0;
    for(int i=0; i<26; i++){
        if(max_cnt == alphabets[i])
            cnt++;
    }
    
    if(cnt != 1)
        cout << '?' << '\n';
    else
        cout << (char)(max_idx + 'A') << '\n';
    
    return 0;
}
