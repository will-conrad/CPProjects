#include<iostream>


using namespace std;

int main() {
	//Commence Rick-Roll
	system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
	
	bool tooHeavy;
	bool tooLarge;

	double weight;
	double length;
	double width;
	double height;
	double volume;

	double weightLimit = 27.0;
	double volumeLimit = 0.1;

	cout << endl;

	cout << "Enter package weight in kilograms: ";
	cin >> weight;
	cout << "Enter package length in meters: ";
	cin >> length;
	cout << "Enter package width in meters: ";
	cin >> width;
	cout << "Enter package height in meters: ";
	cin >> height;

	cout << endl;

	volume = length*width*height;

	if (weight > weightLimit) {
		tooHeavy = true;
	}
	if (volume > volumeLimit) {
		tooLarge = true;
	}

	if (tooHeavy && tooLarge) {
		cout << "Rejected: Package is too heavy and too large" << endl;
	}
	else if (tooHeavy) {
		cout << "Rejected: Package is too heavy" << endl;
	}
	else if (tooLarge) {
		cout << "Rejected: Package is too large" << endl;
	}
	else {
		cout << "Package Accepted" << endl;
	}
	
	cout << endl;
	return 0;
}