#include<iostream>
using namespace std;

void hiLo(int x, int y, int & lo, int & hi);
int main() {
	int num1;
	int num2;

	cout << "Enter num1: ";
	cin >> num1;
	cout << "Enter num2: ";
	cin >> num2;
	hiLo(num1, num2);
	cout << "High is num1: ";
	cin >> num1;
	cout << "Low is : ";
	cin >> num2;

	return 0;
}
void hiLo(int x, int y, int & lo, int & hi) {

}