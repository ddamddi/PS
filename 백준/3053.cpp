#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int r;
	cin >> r;
	
	double s1 = M_PI*r*r;
	double s2 = 2*r*r;
	
	printf("%f\n%f\n",s1,s2);
	return 0;
}
