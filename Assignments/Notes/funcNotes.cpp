#include<iostream>
using namespace std;
/* Functions
- Piece of code that accomplishes a specific task

- Structure: returnType name(parameters) {}

- [Return Type] Information returned after function is called
  - void: function runs an action and returns no information
  - int
  - double
  - string
  - char
  - bool


- [Name]
  - Name should make sense
  - cammelCase

- [Parameters] Information passed into the function and used as variables
------------------------------------------
- Check if your name is on a list
bool nameCheck(string n) {
	
}
------------------------------------------
1. Create function prototype
	- returnType name(parameters);
	- Before main()
2. Create function definition
	- (Prototype - ;) + {code}
3. Call the funciton
	- Done inside another function
- 


*/

string whoWon(string teamA, int aScore, string teamB, int bScore) {
	string tie = "Tie";
	if (aScore > bScore) {
		return teamA;
	}
	else if (bScore > aScore) {
		return teamB;
	}
	else {
		return tie;
	}
}

int main() {
	int pats;
	int steelers;
	cout << "Patriots score: ";
	cin >> pats;
	cout << "Steelers score: ";
	cin >> steelers;
	cout <<endl;

	cout << whoWon("Pats", pats, "Steelers", steelers) << " won the game!" <<endl;
	return 0;
}