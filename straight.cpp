#include<iostream>
using namespace std;

bool smStraight(int a[]);
int main() {
	int dice[5];
	for (int x = 0; x < 5; x++) {
		cin >> dice[x];
	}
	if (smStraight(dice)) {
		cout << "straight" <<endl;
	}
	else {
		cout << "no straight" <<endl;
	}
	return 0;
}


bool smStraight(int a[]) {
	bool x = true;
	int y = 0;
	int i = 0;
	do {
		if (a[i] == a[i+1] - 1 && i < 5) {
			i++;
			y++;
			x = true;
		}
		else if (a[i] == a[i+2] - 1 && i < 5) {
			i = i + 2;
			y++;
			x = true;
		}
		else {
			if (i != 0) {
				x = false;
			}
			i++;
		}
	}
	while (x == true); 
	if (y >= 3) {
		return true;
	}
	else {
		return false;
	}
}