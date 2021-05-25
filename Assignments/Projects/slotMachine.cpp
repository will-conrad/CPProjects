#include<iostream>
using namespace std;

//getEmoji(n) returns the correct emoji for the number passed to it.
string getEmoji(int n) {
	string cherry, orange,  melon, output; //Inits
	//Unicode for emojis
	cherry = "\U0001F352";
	orange = "\U0001F34A";
	melon =  "\U0001F349";

	if (n == 1) { 		//1 - Orange
		output = orange;
	}
	else if (n == 2) {  //2 - Cherry
		output = cherry;
	}
	else { 				//3 - Melon
		output = melon; 
	}
	return output; //Returns emoji unicode (string)
}

int main() {
	// ---- VARIABLES BEGIN ---- //
	int num1Top, num2Top, num3Top, num1, num2, num3, num1Down, num2Down, num3Down;
	int tokens = 100;
	char charIn; //(y/n) Input used for useEmoji and playAgain
	bool usingEmoji = false;
	bool playAgain = true;
	// ---- VARIABLES END ---- //
	
	//Clear screen for aesthetic cleanliness
	system("clear"); 
	
	//Check if user wants to use emojis instead of numbers
	cout << "Use emojis?(y/n) ";
	cin >> charIn;
	if (charIn == 'y') {
		usingEmoji = true;
	}

	system("clear");

	while (playAgain && tokens > 0) {
		if (tokens != 1) { //100% absolutely crucial that we say singular "token" not "tokens" when player has 1
			cout << "You have " << tokens << " tokens. Pull?(y/n) "; //Plural
		}
		else {
			cout << "You have " << tokens << " token. Pull?(y/n) "; //Singular
		}

		cin >> charIn;
		if (charIn == 'y') {
			system("clear");
			tokens--; //Slot machine takes 1 token each turn
			
			//Generate random numbers for slot machine
			num1 = rand() %3+1;
			num2 = rand() %3+1;
			num3 = rand() %3+1;

			//Solve top and bottom numbers
			num1Down = num1 %3+1;
			num2Down = num2 %3+1;
			num3Down = num3 %3+1;

			num1Top = num1Down %3+1;
			num2Top = num2Down %3+1;
			num3Top = num3Down %3+1;

			//Outputs with emojis
			if (usingEmoji) {	
				cout << "   " << getEmoji(num1Top)  << "  " << getEmoji(num2Top)  << "  " << getEmoji(num3Top)  << endl;
				cout << " >[" << getEmoji(num1)     << "][" << getEmoji(num2)     << "][" << getEmoji(num3)     << "]<" << endl;
				cout << "   " << getEmoji(num1Down) << "  " << getEmoji(num2Down) << "  " << getEmoji(num3Down) << endl;

				if (num1 == 1 && num2 == 1 && num3 == 1) { //All 1
					tokens = tokens + 4; //Add 4 token prize
					cout << getEmoji(1) << getEmoji(1) << getEmoji(1) << " Triple oranges! You won 4 tokens.";
				}
				else if (num1 == 2 && num2 == 2 && num3 == 2) { //All 2
					tokens = tokens + 8; //Add 8 token prize
					cout << getEmoji(2) << getEmoji(2) << getEmoji(2) << " Triple cherries! You won 8 tokens.";
				}
				else if (num1 == 3 && num2 == 3 && num3 == 3) { //All 3
					tokens = tokens + 12; //Add 12 token prize
					cout << getEmoji(3) << getEmoji(3) << getEmoji(3) << " Jackpot melons! You won 12 tokens.";
				}
				else {
					cout << "Better luck next time."; //If no 3-in-a-row, output message
				}
			}
			
			//Outputs without emojis
			else {
				cout << "   " << num1Top  << "  " << num2Top  << "  " << num3Top  << endl;
				cout << " >[" << num1     << "][" << num2     << "][" << num3     << "]<" << endl;
				cout << "   " << num1Down << "  " << num2Down << "  " << num3Down << endl;
				
				if (num1 == 1 && num2 == 1 && num3 == 1) {
					tokens = tokens + 4;
					cout << "Triple ones! You won 4 tokens.";
				}
				else if (num1 == 2 && num2 == 2 && num3 == 2) {
					tokens = tokens + 8;
					cout << "Triple twos! You won 8 tokens.";
				}
				else if (num1 == 3 && num2 == 3 && num3 == 3) {
					tokens = tokens + 12;
					cout << "Jackpot! You won 12 tokens.";
				}
				else {
					cout << "Better luck next time.";
				}
			}
			
			cout <<endl;
		}
		else if (charIn == 'n') { 
			playAgain = false; //Break while loop
		}
		else { //User inputted character not y/n
			system("clear");
		} //Ask for input again
	}
	
	if (tokens <= 0) {
		//Game end because player out of tokens
		cout << "Out of tokens. ";
	}
	
	cout << "Thanks for playing!" <<endl;
	cout <<endl;

	return 0;
}