#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int num;
	cin >> num;
	int size = log10(num);
	//int size = trunc(log10(num)) + 1;
	//int size = trunc(log10(num)) + 1;
	cout << size << endl;
	return 0;
}

