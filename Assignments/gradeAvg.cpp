#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	double input;
	int grdCount = 0;
	double sum = 0;
	double avg;
	
	bool exit = false;
	cout <<endl;
	while (!exit) {
		cout << "Enter your grade: ";
		cin >> input;
		if (input != 101) {
			sum = sum + input;
			grdCount++;
		}
		else {
			exit = true;
		}
	}
	avg = sum / grdCount;
	cout <<endl;
	cout << "Your class average is " << fixed << setprecision(3) << avg <<endl;
	return 0;
}