#include <iostream>
using namespace std;

int main(){
	int x, y, day_count = 0;
	cin >> x >> y;
	
	for(int i = 1; i < x; i++){
		day_count += 30;
		
		if(i == 1 || i == 3 || i == 5 || i == 7 || i ==8 || i == 10 || i == 12) {
			day_count++;
		}
		else if(i == 2)
			day_count -= 2;
	}
	
	day_count += y-1;
	
	switch(day_count % 7) {
		case 0:
			cout << "MON";
			break;
		case 1:
			cout << "TUE";
			break;
		case 2:
			cout << "WED";
			break;
		case 3:
			cout << "THU";
			break;
		case 4:
			cout << "FRI";
			break;
		case 5:
			cout << "SAT";
			break;
		case 6:
			cout << "SUN";
			
	}
	
	return 0;
}
