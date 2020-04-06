#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string a, b, c, d;
	cin>>a>>b>>c>>d;
	
	cout << atoll((a+b).c_str()) + atoll((c+d).c_str()) << endl;
	return 0;
}
