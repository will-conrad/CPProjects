#include<iostream>
#include<iomanip>
using namespace std;

char letterGrade(int grade);
double askAverage();

int main() {
	double avgNumber;
	char avgLetter;

	avgNumber = askAverage();
	cout << "Your grade average is " << fixed << setprecision(3) << avgNumber <<endl;
	cout << "Your letter grade is " << letterGrade(avgNumber) <<endl;
	cout << endl;
	return 0;
}
char letterGrade(int n) {
	if (n >= 90) {
		return 'A';
	}
	else if (n >= 80 && n < 90) {
		return 'B';
	}
	else if (n >= 71 && n <= 79) {
		return 'C';
	}
	else if (n == 70) {
		return 'D';
	}
	else {
		return 'F';
	}
}

double askAverage() {
	double input;
	double sum = 0;
	int grdCount = 0;
	bool exit = false;

	while (!exit) {
		cout << "Enter your grade(Enter 101 to finish): ";
		cin >> input;
		if (input != 101) {
			sum = sum + input;
			grdCount++;
		}
		else {
			exit = true;
		}
	}
	return sum / grdCount;
}