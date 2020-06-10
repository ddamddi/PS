#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    
    int i=1, cnt=0;
    for(;;i++){
        cnt += i;
        if(cnt >= x)
            break;
    }
    
    if(i%2 == 1)
    	cout << 1+(cnt-x) << '/' << i-(cnt-x) << '\n';
	else
		cout << i-(cnt-x) << '/' << 1+(cnt-x) << '\n';
    
    return 0;
}
