#include<iostream>
using namespace std;

#define enter cout<<endl;

void roll(int a[]);
void sort(int a[]);
bool threes(int a[]);
bool fours(int a[]);
bool fullHouse(int a[]);
bool smStraight(int a[]);
bool lgStraight(int a[]);
bool yahtzee(int a[]);




int main() {
	int dice[5];
	roll(dice);
	
	int sorted[5] = {dice[0], dice[1], dice[2], dice[3], dice[4]};
	sort(sorted);

	for(int i = 0; i < 5; i++) {
		cout << dice[i] << endl; // output them unsorted
	}
	enter;
	for(int i = 0; i < 5; i++) {
		cout << sorted[i] << endl; // output them unsorted
	}

	cout << smStraight(sorted) <<endl;

	
	return 0;
}

void roll(int a[]) {
	srand(time(NULL));
	for(int i = 0; i < 5; i++) {
		a[i] = rand() % 6 + 1;
	}
}
void sort(int a[]) {
	int j = 0;
	for(int i = 1; i < 5; i++) {
		j = i;
		while (j > 0 && a[j-1] > a[j]) {
			swap(a[j], a[j-1]);
			j--;
		}
	}
}
/*
bool threes(int a[]) {

}
bool fours(int a[]) {

}
bool fullHouse(int a[]) {

}
*/
bool smStraight(int a[]) {
	bool x = false;
	int i = 0;
	do {
		cout << "index" << i <<endl;
		if (a[i] == 1 && i < 2) { //1 in index 0 or 1
			if (a[i] == a[i+1]) {
				x = true;
			}
			else {
				x = false;
			}
		}
		else if (a[i] == 2 && i < 2) { //2  in index 0 or 1
			if (a[i] == a[i+1]) {
				x = true;
			}
			else {
				x = false;
			}
		}
		else {
			return false;
		}
		i++;
	}
	while (x == true && i != 4);
	return x;

}
/*
bool lgStraight(int a[]) {

}
*/
bool yahtzee(int a[]) {
	if (a[0] == a[4]) {
		return true;
	}
	return false;
}


/*
3ofakind 111, 222, 333, 444, 5
12346

11234

sm straight if on number that could start a sm straihgt ( 1 or 2 ) start checking next, keeping 

function for roll
multiple rolls keeping certain dice
*/
