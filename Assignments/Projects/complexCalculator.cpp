#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//Function prototypes
void entr();
void printInstructions();
void input(double & X,double & Y);
void output(double X,double Y);
void refresh(double A, double B);
void add(double & A, double & B, double C, double D);      // +
void subtract(double & A, double & B, double C, double D); // -
void multiply(double & A, double & B, double C, double D); // *
void divide(double & A, double & B, double C, double D);   // /
double length(double & A, double & B); // absolute value

int main() {	
	//Init variables
	char choice = ' ';  // keeps track of input request
	double A = 0; // keeps track of the current real value
	double B = 0; // keeps track of the current imaginary value
	double C = 0; // the real value to +, -, *, or /
	double D = 0; // the imaginary value to +, -, *, or /
	
	system("clear"); //Clear terminal screen 
	printInstructions();
	
	while(choice != 'q') {
		entr();
		cout << "Enter what you want to do: ";
		cin >> choice; //Get new choice
		entr();
		
		switch(choice) {
			case 'i': //Input new complex number
				input(A, B); //Input new current A, B
				refresh(A, B); //CMD window formatting & output A, B
				break;
			case '+': //Add complex number
				cout << "Enter addend" <<  endl;
				input(C, D); //Input numbers to be added to A, B
				add(A, B, C, D);
				refresh(A, B);
				break;
			case '-': //Subtract complex number
				cout << "Enter subtrahend" << endl;
				input(C, D);
				subtract(A, B, C, D);
				refresh(A, B);
				break;
			case '*': //Multiply complex number
				cout << "Enter multiplier" << endl;
				input(C, D);
				multiply(A, B, C, D);
				refresh(A, B);
				break;
			case '/': //Divide complex number
				cout << "Enter divisor" << endl;
				input(C, D);
				divide(A, B, C, D);
				refresh(A, B);
				break;
			case 'l': //Get absolute value of complex number
				refresh(A, B);
				cout << "The length is " << fixed << setprecision(2) << length(A, B) << endl; //output length
				break;
			case 'q': //Quit calculator
				system("clear");
				cout << "Thanks for using our calculator!" << endl;
				break;
			default: //Default/Error case
				refresh(A, B);
				cout << "Not a valid choice!" << endl;
				break;
		}
	}
	return 0;
}
// ================================================================
void entr(){
	//Return line
	cout << endl;
}
void printInstructions() {
	//Prints available input options
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
	//Enter new complex number
	cout << "Real part: ";
	cin >> X; //Pass by ref
	cout << "Imaginary part: ";
	cin >> Y; //Pass by ref
}
void output(double X,double Y) {
	//Output complex number in "A + Bi" format
	cout << "Current value: " << fixed << setprecision(2) << X << " + " << Y << "i" << endl;
}
void refresh(double A, double B) {
	entr(); //Return
	system("clear"); //Clear
	printInstructions(); //Print instructions
	entr(); //Return
	output(A, B); //Print current value
}
void add(double & A, double & B, double C, double D) {
	//Adding equation
	A = A + C;
	B = B + D;
}
void subtract(double & A, double & B, double C, double D) {
	//Subtraction equation
	A = A - C;
	B = B - D;
}
void multiply(double & A, double & B, double C, double D) {
	double tempA = A; //Hold [A] during calculations
	//Multiplication equation
	A = (A * C) - (B * D);
	B = (B * C) + (tempA * D); //Use original A (tempA) not the A computed above
}
void divide(double & A, double & B, double C, double D) {
	double tempA = A; //Hold [A] during calculations
	//Division equation
	A = ((A * C) + (B * D)) / ((C * C) + (D * D));
	B = ((B * C) - (tempA * D)) / ((C * C) + (D * D)); //Use original A (tempA) not the A computed above
}
double length(double & A, double & B) {
	//Absolute value/length equation
	return sqrt((A * A) + (B * B)); //Sqrt of A^2 + B^2
}
