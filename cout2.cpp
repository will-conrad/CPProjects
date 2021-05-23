#include<iostream>
using namespace std;

int main() {
	int x = 32;
	cout << "██";
	cout << "\033["<<x<<";41m▞▞\033[0m\n";
	
	return 0;
}
