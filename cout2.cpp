#include<iostream>
#include<cmath> 
using namespace std;

int main() {
	long number;
	cin >> number;
	int size = trunc(log10(number)) + 1;
	int array[size];
	for (int i = size - 1; i >= 0; i--) {
	    array[i] = number % 10;
	    number /= 10;
	}
	for (int i = 0; i < size; i++) {
		cout << array[i];
	}
	cout <<endl;
	cout << size <<endl;	
	return 0;
}
