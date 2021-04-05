#include<iostream>
#include "elements.h"
using namespace std;

int main() {
	string element;
	
	string symbol;
	string name;
	int number;
	double mass;
	int charge;
	do {
		cout << "Enter element: ";
		cin >> element;
		if (element != "end") {
			if (element.length() > 2) {
				name = element;
				symbol = AtomicSymbol(element);
			}
			else {
				name = AtomicName(element);
				symbol = element;
			}
			number = AtomicNumber(symbol);
			mass = AtomicMass(symbol);
			charge = IonicCharge(symbol);
			system("clear");
			cout << name <<endl;
			cout << symbol <<endl;
			cout << "Atomic #: " << number <<endl;
			cout << "Atomic mass: " << mass <<endl;
			cout << "Charge: " << charge <<endl;
			cout <<endl;
		}
	} while (element != "end");

	return 0;
}
