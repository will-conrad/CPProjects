#include<iostream>
using namespace std;

void swap(int & a, int & b);

int main() {
	int num1, num2;
	cout << "Enter num1: ";
	cin >>num1;
	cout << "Enter num2: ";
	cin >>num2;
	cout <<endl;

	cout << "Num1 is " << num1 <<endl;
	cout << "Num2 is " << num2 <<endl;

	swap(num1, num2);
	cout << "SWAP Num1 is " << num1 <<endl;
	cout << "SWAP Num2 is " << num2 <<endl;

	return 0;
}

void swap(int & a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;

}

/*Passing a parameter by reference.
Indicate that the variable being passed should be changed by the function
Parameter (type int & n);
void swap(int & a, int & b) {}
*/