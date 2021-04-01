#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void printInstructions();
void entr();
void input(double & X,double & Y);
void output(double X,double Y);
void add(double & A, double & B, double C, double D);
void subtract(double & A, double & B, double C, double D);

int main() {	
	char choice;
	double A = 0; // keeps track of the current real value
	double B = 0; // keeps track of the current imaginary value
	double C = 0; // the real value to +, -, *, or /
	double D = 0; // the imaginary value to +, -, *, or /
	
	system("clear");
	printInstructions();
	
	while(choice != 'q') {
		
		cout << "Enter what you want to do: ";
		cin >> choice;
		
		switch(choice) {
			case 'i':
				input(A, B);
				entr();
				break;
			case '+':
				cout << "Enter addend" <<  endl;
				input(C, D);
				add(A, B, C, D);
				entr();
				break;
			case '-':
				cout << "Enter subtrahend" << endl;
				input(C, D);
				subtract(A, B, C, D);
				entr();
				break;
			case 'q':
				cout << "Thanks for using our calculator!" << endl;
				break;	
			default:
				cout << "Not a valid choice!" << endl;
				break;
		}
		system("clear");
		printInstructions();
		
		output(A, B);
		entr();
		
	}
	
	return 0;
}
// ==========================
void entr(){
	cout <<endl;
}
void printInstructions() {
	cout << "Welcome to the Complex Number Calculator!" << endl;
	cout << "Here are your options: " << endl;
	cout << "+ (addition)" << endl;
	cout << "- (subtraction)" << endl;
	cout << "* (multiplication)" << endl;
	cout << "/ (division)" << endl;
	cout << "l (length)" << endl;
	cout << "i (new input)" << endl;
	cout << "q (quit)" << endl;
}
void input(double & X,double & Y) {
	cout << "Real part: ";
	cin >> X;
	cout << "Imaginary part: ";
	cin >> Y;
}
void output(double X,double Y) {
	cout << "Current value: " << fixed << setprecision(2) << X << " + " << Y << "i" << endl;
}
void add(double & A, double & B, double C, double D) {
	A = A + C;
	B = B + D;
}
void subtract(double & A, double & B, double C, double D) {

}






