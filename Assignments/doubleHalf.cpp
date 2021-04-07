#include<iostream>
using namespace std;

void halfDouble(double n, double & h, double & d);

int main() {
	double input;
	double half;
	double doub;

	cout << "Enter number: ";
	cin >> input;
	cout <<endl;
	halfDouble(input, half, doub);
	cout << "\033[1;31mbold red text\033[0m\n";
	cout << "Your number halved is " << half <<endl;
	cout << "Your number doubled is " << doub <<endl;
	cout <<endl;
	return 0;
}

void halfDouble(double n, double & h, double & d) {
	h = n/2; //Half
	d = n*2; //Double
}
