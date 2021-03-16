#include<unistd.h>
#include<iostream>

using namespace std;

void clear() {
	system("clear");
}

int calibrate() {
	int width = 50;
	bool atEnd = false;
	char in;
	
	
	while(!atEnd) {
		clear();
		cout << "a: -5\ns: -1\nd: +1\nf: +5\nw: Input width\ne: Confirm"<<endl;
		cout << width <<endl;
		for (int n = 1; n <= width; n++) {
			cout << "~";
		}
		cout <<endl;

		cin >> in;
		if (in == 'a') {
			width = width - 5;
		}
		else if (in == 's') {
			width = width - 1;
		}
		else if (in == 'd') {
			width = width + 1;
		}
		else if (in == 'f') {
			width = width + 5;
		}
		else if (in == 'w') {
			clear();
			cout << "Enter window width: ";
			cin >> width;
			atEnd = true;
		}
		else if (in == 'e') {
			atEnd = true;
		}
	}
	return width;
}

int randNum() {
	int out;
	out = rand() %2;
	return out;
}

int calibInit() {
	int width;
	char calibChar;

	clear();

	cout << "Calibrate?(y/n): ";
	cin >> calibChar;
	if (calibChar == 'y') {
		width = calibrate();
	}
	else {
		width = 135;
	}
	return width;
}

int printer() {
	int e = 0;

	int width = calibInit();
	
	clear();
	
	while (true) {
		int n = 0;
		while (n < width) {
			cout << " ";
			cout <<randNum();

			n++;
		}
		
		cout <<endl;
		usleep(60000);
	}
	return 0;
}

int main() {
	printer();
}










