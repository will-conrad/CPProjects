#include<iostream>
using namespace std;
int main() {
	//Print Horse and Buggy Co. Logo
	cout << "  ______" << endl;
	cout << " /|_||_\\`.__" << endl;
	cout << "(   _    _ _\\" << endl;
	cout << "=`-(_)--(_)-'" << endl;
	cout << "Horse and Buggy Auto Co." <<endl;
	cout <<endl;

	int numInput; //Init user input
	bool carFaulty = false; //Set broken car bool to false
		
	do {
		//User input 
		cout << "Enter your car's model number (Enter 0 for done): ";
		cin >> numInput;

		if(numInput == 119 
			|| numInput == 179
			|| numInput == 189
			|| numInput == 221
			|| numInput == 780
			|| (numInput >= 189 && numInput <=195)
			){
			carFaulty = true;
		}
		else {
			carFaulty = false;
		}
		if(numInput != 0){ //Stop output if 0 is entered immediately
			if(carFaulty){
				cout << "Your car is defective. Please have it fixed."<<endl;
				cout <<endl;
			}
			else {
				cout << "Your car is OK." <<endl;
				cout <<endl;
			}
		}
	}while(numInput != 0);

	return 0;
}
