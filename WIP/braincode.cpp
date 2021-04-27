#include<iostream>
using namespace std;

double calculate(int a, int b, int c, int d, int e);
void randOps();

int op1;
int op2;
int op3;
int op4;
int op5;

int main() {
	
	double z;

	while (z != 18) {
		randOps();

		z = calculate(op1, op2, op3, op4, op5);
		//cout << op1 << op2 << op3 << op4 << op5 <<endl;
		cout << z <<endl;

	}
	system("clear");
	cout << z <<endl;
	cout << op1 << op2 << op3 << op4 << op5 <<endl;

	
	
	return 0;
}
void randOps() {
	srand(time(NULL));
	op1 = rand() % 2;
	op2 = rand() % 2;
	op3 = rand() % 2;
	op4 = rand() % 2;
	op5 = rand() % 2;
}
double calculate(int a, int b, int c, int d, int e) {
	int x;
	if (a == 0) {
		x = 33 + 5;
	}
	else {
		x = 33 - 5;
	}
	
	if (b == 0) {
		x = x + 2;
	}
	else {
		x = x - 2;
	}

	if (c == 0) {
		x = x + 6;
	}
	else {
		x = x - 6;
	}

	if (d == 0) {
		x = x + 6;
	}
	else {
		x = x - 6;
	}

	if (e == 0) {
		x = x + 12;
	}
	else {
		x = x - 12;
	}
	return x;
}

//((33 - (((5 / 2) / 6) / 6)) - 12) = 18