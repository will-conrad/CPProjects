#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	int w = 60;
	int h = 50;
	srand(time(NULL));
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			if (rand()%5 == 1) {
				cout << setw(2) << "██";
			}
			else {
				cout << setw(2) << "  ";
			}
		}
		cout << endl;
	}
	//█ █ █ █
	
	return  0;

}

