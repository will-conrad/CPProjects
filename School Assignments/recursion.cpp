#include<iostream>
using namespace std;

long exponent(long num, long p); //Number and power

int main()
{
	long number;
	long power;
	printf("Enter number: ");
	cin >> number;
	printf("Enter power: ");
	cin >> power;

	cout << exponent(number, power) <<endl; //7^4
	
	return 0;
}

long exponent(long num, long p)
{
	if (p == 1) {
		return num;
	}

	return num * exponent(num, p-1);
}


/*
Recursive functions
- a way of breaking a larger problem into its base steps, then building back up to the larger problem

7^5
  ↳7*7^4
	   ↳7*7^3
	   		↳7*7^2
	   			 ↳7*7

*/