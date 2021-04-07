#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int hours;
	int overtime;
	
	double hrRate;
	

	double wage;
	
	
	cout << "Enter hours worked: ";
	cin >> hours;
	cout << "Enter hourly rate: ";
	cin >> hrRate;
	
	if (hours > 40) {
		wage = 40*hrRate;
		
		overtime = hours-40;

		wage = wage + overtime * (hrRate*1.5);
	}
	
	

	cout << "Gross wage: $" << fixed << setprecision(2) << wage <<endl;
	//cout << setprecision(2) << hrRate <<endl;




	return 0;
}