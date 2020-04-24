#include <iostream>
using namespace std;

int main(){
    int n, new_n = 0, cnt = 0;
    cin >> n;

    int a = n;
    do{ 
        int x, y, z;
        x = a / 10; // 10의 자리 수
        y = a % 10; // 1의 자리 수
        z = x + y;  // x+y의 합
        new_n = (y * 10) + (z % 10);
        cnt++;
        a = new_n;
    } while(new_n != n);

    cout << cnt;
}