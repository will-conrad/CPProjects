#include<iostream>
using namespace std;

long factorial(int n);

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << number << "! = " << factorial(number) << endl;
	
	return 0;
}

long factorial(int n) {
	if (n == 1) {
		return n;
	}
	return n * factorial(n - 1);
}
/*
5!
5*4!
  4*3!
    3*2!
      2*1!
        1*1


*/