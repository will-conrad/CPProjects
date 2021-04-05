#include<iostream>
using namespace std;


string giveHint(int guess, int secret);


int main() {
	bool guessing = true; //Keep program running if true
	int guess; //User input
	srand(time(NULL));
	int secret = rand() %100 +1; //Const secret

	cout <<endl;
	while (guessing) {
		cout << "Enter guess: ";
		cin >>guess;
		if (guess >= 1 && guess <= 100) { //Check that input is a number
			cout << giveHint(guess, secret) <<endl; //Output hint message
			cout <<endl;
			if (guess == secret) { //End program if guessed correctly
				guessing = false;
			}
		}
		else { //If input is not a number
			guessing = false; //End program
		}
	}

	return 0;
}

string giveHint(int guess, int secret) { //Input guess and secret | Output message
	if (guess > secret) {
		return "Too high";
	}
	else if (guess < secret) {
		return "Too low";
	}
	else {
		return "You got it!";
	}
}

