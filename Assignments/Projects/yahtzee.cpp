#include<iostream>
#include<ctime>
using namespace std;
//From now on, "play" means a play that a user could make depending on their dice roll (Fours, Straight, three of a kind, yahtzee)
//"Possible plays" are plays that a user could legally make with their dice roll AND could legally score because they havn't already scored it
//"Available plays" are plays not yet scored that a user must score if they can't score any other plays with the dice they have (The zero rule)

//ALL RULES of Yahtzee have been implemented from https://www.hasbro.com/common/instruct/Yahtzee.pdf WITH THE EXCEPTION OF the Joker Rule

//Custom formatting commands for convenience 
#define enter cout<<endl; //New line
#define clear system("clear"); //Clear screen

//Function prototypes
void roll(int a[], bool keep[]); //Dice rolling
void sort(int a[]); //Insertion sorting
void printDice(int a[]); //Prints dice in nice boxes
void printScore(); //Prints game score
void checkPossible(int dice[]); //Checks possible plays and available arrays if no legal plays are left
void printPossible(int p[], int a[]); //Prints numbered list of possible plays and creates corrosponding array
bool threeOfAKind(); //Check 3 of a kind
bool fourOfAKind(); //Check 4 of a kind
bool fullHouse(int a[]); //Check full house
bool smStraight(int a[]); //Small straight
bool lgStraight(int a[]); //Large straight
bool yahtzee(int a[]); //Check 5 of a kind (yahtzee)
void printYahtzee(); //Prints yahtzee banner 
==
bool forceZero = false; //Keeps track of whether player must enter 0 in available score area because no valid plays are possible after 3 rolls.
bool canOnes = false, canTwos = false, canThrees = false, canFours = false, canFives = false, canSixes = false, canSmStraight = false, canLgStraight = false, canThreeOfAKind = false, canFourOfAKind = false, canFullHouse = false, canYahtzee = false, canChance = false; //keeps track of legality of moves
bool usedOnes = false, usedTwos = false, usedThrees = false, usedFours = false, usedFives = false, usedSixes = false, usedSmStraight = false, usedLgStraight = false, usedThreeOfAKind = false, usedFourOfAKind = false, usedFullHouse = false, usedYahtzee = false, usedChance = false;
int scoreOnes, scoreTwos, scoreThrees, scoreFours, scoreFives, scoreSixes, scoreSmStraight, scoreLgStraight, scoreThreeOfAKind, scoreFourOfAKind, scoreFullHouse, scoreYahtzee, bonusYahtzee, scoreChance;
//Quantity of each number die
int ones, twos, threes, fours, fives, sixes;
int possible = 0, available = 0;
//Possible: Number of legal plays based on dice roll
//Available: Number of plays not already used to score

int main() {
	int playsUsed = 0; //Number of plays
	int loopCatch = 0; //Entering a char into a cin expecting an int results in an endless loop. loopCatch catches endless loops and ends the program
	bool proceed = true; //Main valid input boolean
	char charIn = '.'; //Main char input
	int intIn = 0; //Main int input
	int play = 0; //User inputted chosen play
	int rollsLeft = 3; //Keeps tract
	int rerollDice; //Number of dice to be rerolled
	int dice[5]; //Dice array
	int possibleArr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Corosponds user input list with play-ID
	int availableArr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Corosponds user input list with play-ID
	bool keptDice[5] = {false, false, false, false, false}; //Keeps track of which dice to reroll
	
	clear;
	printYahtzee();
	enter;

	while(playsUsed < 13) { //13 possible plays, so code looped 13 times
		//Set variable defaults each round
		loopCatch = 1;
		proceed = false;
		rollsLeft = 3;
		intIn = 0;
		charIn = 'x';
		
		for (int n = 0; n < 5; n++) {
			//Reset keptDice to all false (keep no dice) so all dice get rerolled
			keptDice[n] = false;
		}
		
		roll(dice, keptDice); //Call roll function and pass dice[] & keptDice[]
		sort(dice); //Sort dice array
		
		printDice(dice); //Output dice array
		enter;
		checkPossible(dice); //Checks all possible valid plays 
		printPossible(possibleArr, availableArr); //Prints possible/available plays in numbered list
		enter;
		do {
			cout << "Print score? (y/n): ";
			cin >> charIn; //cin --> generic char variable for all char inputs
			if (charIn != 'y' && charIn != 'n') { //User input must be 'y' or 'n'
				proceed = false;
			}
			else { //User enters letter other than y or n
				proceed = true;
			}
			loopCatch++; //Increment loopCatch to detect endless loops
			if (loopCatch > 20) { //if loopCatch gets too high, end program
				enter;
				clear;
				cout << "INPUT ERROR" <<endl;
				return 0;
			}
		}
		while (!proceed ); //Ask until user inputs valid answer

		if (charIn == 'y') { //User inputs 'y'
			printScore();
			enter;

			cout << "[Input any character to continue]"; //Equivalent of "press any button to continue"
			cin>>charIn; //Cin used to detect enter key + character input
			//Reprint screen elements
			clear;
			printYahtzee();
			enter;
			printDice(dice);
			enter;
			printPossible(possibleArr, availableArr);
			enter;
		}
		do { // --- Reroll dice loop --- //
			do { //Ask for input
				cout << "Reroll? (y/n): ";
				cin >> charIn;
				if (charIn != 'y' && charIn != 'n') { //User input must be 'y' or 'n'
					proceed = false;
				}
				else {
					proceed = true;
				}
				loopCatch++;
				if (loopCatch > 20) {
					enter;
					clear;
					cout << "INPUT ERROR" <<endl;
					return 0;
				}
			}
			while (!proceed); //Ask until user inputs valid answer

			if (charIn == 'y') { //User wishes to reroll
				cout << "How many would you like to reroll?: ";
				cin >> rerollDice; //Get # of dice to reroll
				if (rerollDice == 5) { //If rerollDice=5, skip dice selection and tell keptDice[] to reroll everything
					for (int n = 0; n < 5; n++) {
						keptDice[n] = false; //Set keptDice[] all to false
					}
					//Reroll and sort
					roll(dice, keptDice);
					sort(dice);
					checkPossible(dice); //Check plays from new dice
				}
				else if (rerollDice > 5 || rerollDice < 1) { //Catch invalid numbers and give the Reroll-Dice-While loop another chance without rerolling
					rollsLeft++; //ignore invalid input and give user another chance
				}
				else { //User enters # between 1 and 4
					for (int n = 0; n < 5; n++) {
						keptDice[n] = true; //tell keptDice[] to keep everything, then it which ones not to keep
					}
					for (int i = 0; i < rerollDice; i++) { //Loop for every dice user wants to reroll (rerollDice)
						cout << "Enter the die positions that you want to reroll (1,2,3,4,5): ";
						cin >> intIn; //Cin --> generic integer variable for all integer inputs

						keptDice[intIn-1] = false; //Set keptDice index to user input -1 so "1" becomes index "0"
					}
					//Reroll and sort
					roll(dice, keptDice);
					sort(dice);
					checkPossible(dice); //Check plays from new dice
				}
				clear;
				//Reprint
				printYahtzee();
				enter;
				printDice(dice);
				enter;
				printPossible(possibleArr, availableArr); 
				enter;

				rollsLeft--; //Count down rolls 
			}
			else { //User inputs 'n'
				rollsLeft = 1; //Count off remaining rolls to end loop
			}
		}
		while (rollsLeft != 1); //Until user runs out of rolls
		//----------------------------
		do {
			cout << "What would you like to do? (Enter number next to available play): ";
			cin >> play;
			//Using possible + available because only one will have a value (the number of valid plays to choose from) so any input above either is invalid
			if (play > (possible + available) || play < 1) { //Also catches inputs < 0
				proceed = false;
			}
			else {
				proceed = true;
			}
			loopCatch++;
			if (loopCatch > 20) {
				enter;
				clear;
				cout << "INPUT ERROR" <<endl;
				return 0;
			}
		}
		while (!proceed);
		play--; //Subtracts 1 from user input so when 1 is inputted, index 0 is fetched
		if (forceZero == false) { //If user has a valid play and said valid play has not been used yet
			switch(possibleArr[play]) { //All of this index stuff is explained in printPossible()
				/*	possibleArr[] and availableArr[] are arrays representing the numbered list of valid choices presented to the user.
					Attatched to the index corrosponding to a number on the list is an identifying number that corrosponds to the play it represents.
					If the user chooses option 2 from the example list below, index 1 (play--) is fetched. Waiting at index 1 is the number 12 which represents
					yahtzee. 12 is placed into this switch(possibleArr[play]) and checked. 

					1. Twos
					2. Yahtzee
					3. Chance
				*/  
				case 1:
					clear; //Clear screen
					printYahtzee(); //Reprint yahtzee logo
					enter; //Return
					scoreOnes = ones; //scoreOnes = 1 * # of ones
					cout << "You scored " << scoreOnes << " points for [Aces]" <<endl;
					usedOnes = true; //Used Ones
					playsUsed++; //Increment play count
					break;
				case 2:
					clear;
					printYahtzee();
					enter;
					scoreTwos = 2 * twos; //scoreTwos = 2 * # of twos
					cout << "You scored " << scoreTwos << " points for [Twos]" <<endl;
					usedTwos = true;
					playsUsed++;
					break;
				case 3:
					clear;
					printYahtzee();
					enter;
					scoreThrees = 3 * threes;
					cout << "You scored " << scoreThrees << " points for [Threes]" <<endl;
					usedThrees = true;
					playsUsed++;
					break;
				case 4:
					clear;
					printYahtzee();
					enter;
					scoreFours = 4 * fours;
					cout << "You scored " << scoreFours << " points for [Fours]" <<endl;
					usedFours = true;
					playsUsed++;
					break;
				case 5:
					clear;
					printYahtzee();
					enter;
					scoreFives = 5 * fives;
					cout << "You scored " << scoreFives << " points for [Fives]" <<endl;
					usedFives = true;
					playsUsed++;
					break;
				case 6:
					clear;
					printYahtzee();
					enter;
					scoreSixes = 6 * sixes;
					cout << "You scored " << scoreSixes << " points for [Sixes]" <<endl;
					usedSixes = true;
					playsUsed++;
					break;
				case 7:
					clear;
					printYahtzee();
					enter;
					scoreSmStraight = 30;
					cout << "You scored 30 points for [Sm Straight]" <<endl;
					usedSmStraight = true;
					playsUsed++;
					break;
				case 8:
					clear;
					printYahtzee();
					enter;
					scoreLgStraight = 40;
					cout << "You scored 40 points for [Lg Straight]" <<endl;
					usedLgStraight = true;
					playsUsed++;
					break;
				case 9:
					clear;
					printYahtzee();
					enter;
					scoreThreeOfAKind = dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; //Dice total
					cout << "You scored " << scoreThreeOfAKind << " points for [3 of a Kind]" <<endl;
					usedThreeOfAKind = true;
					playsUsed++;
					break;
				case 10:
					clear;
					printYahtzee();
					enter;
					scoreFourOfAKind = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
					cout << "You scored " << scoreFourOfAKind << " points for [4 of a Kind]" <<endl;
					usedFourOfAKind = true;
					playsUsed++;
					break;
				case 11:
					clear;
					printYahtzee();
					enter;
					scoreFullHouse = 25;
					cout << "You scored 25 points for [Full House]" <<endl;
					usedFullHouse = true;
					playsUsed++;
					break;
				case 12:
					clear;
					printYahtzee();
					enter;
					if (usedYahtzee == true && scoreYahtzee != 0) { //If user already scored a Yahtzee, increase yahtzee bonus
						bonusYahtzee = bonusYahtzee + 100;
						cout << "You scored a 100 point Yahtzee Bonus" <<endl;
					}
					else if (usedYahtzee == false) { //1st yahtzee
						scoreYahtzee = 50;
						cout << "You scored 50 points for [Yahtzee]" <<endl;
						usedYahtzee = true;
						playsUsed++;
					}
					break;
				case 13:
					clear;
					printYahtzee();
					enter;
					scoreChance = dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; //Dice total
					cout << "You scored "<< scoreChance <<" points for [Chance]" <<endl;
					usedChance = true;
					playsUsed++;
					break;
				default: //This should never happen, but if it does, we're prepared
					cout << "Please enter a valid number" <<endl;
					enter;
					break;
			}
		}
		else {
			switch(availableArr[play]) { //Same checking but with different array 
				case 1:
					scoreOnes = 0; //Sets score to 0 for that play and doesnt let user score it anymore
					usedOnes = true;
					playsUsed++; //Increment round counter
					break;
				case 2:
					scoreTwos = 0;
					usedTwos = true;
					playsUsed++;
					break;
				case 3:
					scoreThrees = 0;
					usedThrees = true;
					playsUsed++;
					break;
				case 4:
					scoreFours = 0;
					usedFours = true;
					playsUsed++;
					break;
				case 5:
					scoreFives = 0;
					usedFives = true;
					playsUsed++;
					break;
				case 6:
					scoreSixes = 0;
					usedSixes = true;
					playsUsed++;
					break;
				case 7:
					scoreSmStraight = 0;
					usedSmStraight = true;
					playsUsed++;
					break;
				case 8:
					scoreLgStraight = 0;
					usedLgStraight = true;
					playsUsed++;
					break;
				case 9:
					scoreThreeOfAKind = 0;
					usedThreeOfAKind = true;
					playsUsed++;
					break;
				case 10:
					scoreFourOfAKind = 0;
					usedFourOfAKind = true;
					playsUsed++;
					break;
				case 11:
					scoreFullHouse = 0;
					usedFullHouse = true;
					playsUsed++;
					break;
				case 12:
					scoreYahtzee = 0;
					usedYahtzee = true;
					playsUsed++;
					break;
				case 13:
					scoreChance = 0;
					usedChance = true;
					playsUsed++;
					break;
				default: //This should also never happen
					cout << "Please enter a valid number" <<endl;
					enter;
					break;
			}
			clear;
			printYahtzee();
			enter;
		}
	}
	//GAME OVER
	clear;
	printScore(); //Print final score
	enter;
	cout << "Thanks for playing!" <<endl; //Wooooo
	return 0;
}
void roll(int a[], bool keep[]) { //Accepts dice array and array of which ones to keep
	srand(time(NULL)); //Random number using device clock
	for(int i = 0; i < 5; i++) { //For each dice
		if (keep[i] != true) { //If we aren't keeping it
			a[i] = rand() % 6 + 1; //Roll a new dice
		}
	}
	//Reset die quantity variables
	ones = 0;
	twos = 0;
	threes = 0;
	fours = 0;
	fives = 0;
	sixes = 0;
	for (int i = 0; i < 5; i++) { //Recount number of each dice
		switch(a[i]) {
			case 1: 
				ones++;
				break;
			case 2: 
				twos++;
				break;
			case 3: 
				threes++;
				break;
			case 4: 
				fours++;
				break;
			case 5: 
				fives++;
				break;
			case 6: 
				sixes++;
				break;
		}
	}
}
void sort(int a[]) { //Accepts dice array
	//Insertion sort code
	int j = 0;
	for(int i = 1; i < 5; i++) { //For each dice
		j = i; //Pull value out of array
		while (j > 0 && a[j-1] > a[j]) {
			swap(a[j], a[j-1]); //Move value back until it finds a smaller value to put it next to
			j--;
		}
	}
}
void printDice(int a[]) { //Accepts dice array
	//Print dice in cool boxes
	cout << "Your dice:" <<endl;
	cout << "┏━━━┳━━━┳━━━┳━━━┳━━━┓" <<endl;
	cout << "┃ "<<a[0]<<" ┃ "<<a[1]<<" ┃ "<<a[2]<<" ┃ "<<a[3]<<" ┃ "<<a[4]<<" ┃" <<endl;
	cout << "┗━━━┻━━━┻━━━┻━━━┻━━━┛" <<endl;
	/*
	┏━━━┳━━━┳━━━┳━━━┳━━━┓
	┃   ┃   ┃   ┃   ┃   ┃
	┗━━━┻━━━┻━━━┻━━━┻━━━┛
	*/
	/*
	━━━━━━━━━━━━━━━━━━━┓
	 GRAND TOTAL: XXXX ┃
	━━━━━━━━━━━━━━━━━━━┛
	*/
}
void printScore() {
	//Initialize some variables
	int upperScore, lowerScore;
	int bonus = 0;
	int upperTotal = 0;
	
	//Lots of text and formatting
	clear;
	cout<< "[UPPER SECTION]" <<endl;
	cout<< "Aces: " << scoreOnes <<endl;
	cout<< "Twos: " << scoreTwos <<endl;
	cout<< "Threes: " << scoreThrees <<endl;
	cout<< "Fours: " << scoreFours <<endl;
	cout<< "Fives: " << scoreFives <<endl;
	cout<< "Sixes: " << scoreSixes <<endl;
	upperScore = scoreOnes + scoreTwos + scoreThrees + scoreFours + scoreFives + scoreSixes;
	cout<< "UPPER SCORE: " << upperScore << endl;
	if (upperScore > 63) { //Add 35 bonus points if upper section total > 63 
		bonus = 35;
	}
	else {
		bonus = 0;
	}
	upperTotal = upperScore + bonus; //Total
	cout<< "BONUS: " << bonus <<endl;
	enter;
	cout<< "UPPER SECTION TOTAL: " << upperTotal <<endl;
	enter;
	cout << "------------------------" <<endl;
	enter;
	cout<< "[LOWER SECTION]" <<endl;
	cout<< "3 of a kind: "<< scoreThreeOfAKind <<endl;
	cout<< "4 of a kind: "<< scoreFourOfAKind <<endl;
	cout<< "Full House: "<< scoreFullHouse <<endl;
	cout<< "Sm Straight: "<< scoreSmStraight <<endl;
	cout<< "Lg Straight: "<< scoreLgStraight <<endl;
	cout<< "YAHTZEE: "<< scoreYahtzee <<endl;
	cout<< "Chance: "<< scoreChance <<endl;
	cout<< "YAHTZEE BONUS: " << bonusYahtzee <<endl;
	enter;
	lowerScore = scoreThreeOfAKind + scoreFourOfAKind + scoreFullHouse + scoreSmStraight + scoreLgStraight + scoreYahtzee + bonusYahtzee + scoreChance;
	cout<< "LOWER SECTION TOTAL: " << lowerScore << endl;
	enter;
	cout<< "GRAND TOTAL: " << upperTotal + lowerScore << endl;
}
void checkPossible(int dice[]) {
	//Reset canVariables before rechecking everything
	canOnes = false, canTwos = false, canThrees = false, canFours = false, canFives = false, canSixes = false, canSmStraight = false, canLgStraight = false, canThreeOfAKind = false, canFourOfAKind = false, canFullHouse = false, canYahtzee = false, canChance = false;
	possible = 0; //Reset number of possible (legal) plays
	available = 0; //Reset available counter
	if (ones > 0 && usedOnes == false) { //If dice roll has ones and user hasnt scored Ones, play is legal
		canOnes = true; //Set canOnes to true;
		possible++; //Increment possible count
	}
	if (twos > 0 && usedTwos == false) {
		canTwos = true;
		possible++;
	}
	if (threes > 0 && usedThrees == false) {
		canThrees = true;
		possible++;
	}
	if (fours > 0 && usedFours == false) {
		canFours = true;
		possible++;
	}
	if (fives > 0 && usedFives == false) {
		canFives = true;
		possible++;
	}
	if (sixes > 0 && usedSixes == false) {
		canSixes = true;
		possible++;
	}
	if (smStraight(dice) && usedSmStraight == false) { //Check with function if SmStraight is legal and check if user has already scored a sm straight
		canSmStraight = true;
		possible++;
	}
	if (lgStraight(dice) && usedLgStraight == false) {
		canLgStraight = true;
		possible++;
	}
	if (threeOfAKind() && usedThreeOfAKind == false) {
		canThreeOfAKind = true;
		possible++;
	}
	if (fourOfAKind() && usedFourOfAKind == false) {
		canFourOfAKind = true;
		possible++;
	}
	if (fullHouse(dice) && usedFullHouse == false) {
		canFullHouse = true;
		possible++;
	}
	if (yahtzee(dice) && !(scoreYahtzee == 0 && usedYahtzee == true)) { //Dont check if already scored yahtzee because user can score a bonus for scoring 2+ yahtzees
		canYahtzee = true; //^ check if scoreYahtzee has already been set to zero 
		possible++;
	}
	if (usedChance == false) { //Chance is always legal (dice total)
		canChance = true;
		possible++;
	}
	//=============================================
	if (possible == 0) { //All previous if statements DID NOT RUN possible was never incremented which means 
		forceZero = true; //Forcing user to score 0 for some remaining play
		if (usedOnes == false) {
			available++;
		}
		if (usedTwos == false) {
			available++;
		}
		if (usedThrees == false) {
			available++;
		}
		if (usedFours == false) {
			available++;
		}
		if (usedFives == false) {
			available++;
		}
		if (usedSixes == false) {
			available++;
		}
		if (usedSmStraight == false) {
			available++;
		}
		if (usedLgStraight == false) {
			available++;
		}
		if (usedThreeOfAKind == false) {
			available++;
		}
		if (usedFourOfAKind == false) {
			available++;
		}
		if (usedFullHouse == false) {
			available++;
		}
		if (usedYahtzee == false) {
			available++;
		}
	}
	else { //If at least one possible play
		forceZero = false; //Not forcing a 0 score play
	}
}
void printPossible(int p[], int a[]) { //Accepts possibleArr[] and availableArr[]
	for (int i = 0; i < 13; i++) {
		p[i] = 0; //Wipe possibleArr[]
		a[i] = 0; //Wipe availableArr[]
	}
	int x = 1; //The number next to elements in the numbered list presented to the user
	if (forceZero == false) { //User has possible plays
		cout << "Possible plays: " <<endl;
		if (canOnes) { //If canOnes (Dice roll contains at least 1x One AND user hasn't scores for ones yet)
			cout<< x << ". Aces"<<endl; //The 1996 manual calls ones = Aces
			p[x-1] = 1; //Set the identifier for [Ones] to the index corresponding to its spot in the numbered list shown to the user
			x++; //Increments list variable so the next possble play is next to the right number
		}
		if (canTwos) {
			cout<< x << ". Twos"<<endl;
			p[x-1] = 2;
			x++;
		}
		if (canThrees) {
			cout<< x << ". Threes"<<endl;
			p[x-1] = 3;
			x++;
		}
		if (canFours) {
			cout<< x << ". Fours"<<endl;
			p[x-1] = 4;
			x++;
		}
		if (canFives) {
			cout<< x << ". Fives"<<endl;
			p[x-1] = 5;
			x++;
		}
		if (canSixes) {
			cout<< x << ". Sixes"<<endl;
			p[x-1] = 6;
			x++;
		}
		if (canSmStraight) {
			cout<< x << ". Small straight (30pts)"<<endl;
			p[x-1] = 7; //Small straight ID = 7
			x++;
		}
		if (canLgStraight) {
			cout<< x << ". Large straight (40pts)"<<endl;
			p[x-1] = 8; //Small straight ID = 8
			x++;
		}
		if (canThreeOfAKind) {
			cout<< x << ". Three of a kind (Dice total)"<<endl;
			p[x-1] = 9; //Three of a kind ID = 9
			x++;
		}
		if (canFourOfAKind) {
			cout<< x << ". Four of a kind (Dice total)"<<endl;
			p[x-1] = 10; //Three of a kind ID = 10
			x++;
		}
		if (canFullHouse) {
			cout<< x << ". Full house (25pts)"<<endl;
			p[x-1] = 11; //Full house ID = 11
			x++;
		}
		if (canYahtzee) {
			cout<< x << ". Yahtzee (50pts)"<<endl;
			p[x-1] = 12; //Yahtzee ID = 12
			x++;
		}
		if (canChance) {
			cout<< x << ". Chance (Dice total)"<<endl;
			p[x-1] = 13; //Chance ID = 13
			x++;
		}
	}
	else { //forceZero = true
		cout << "Remaining unused plays: " <<endl; //Same process but forcing zero to input
		if (usedOnes == false) {
			cout<< x << ". Aces"<<endl;
			a[x-1] = 1;
			x++;
		}
		if (usedTwos == false) {
			cout<< x << ". Twos"<<endl;
			a[x-1] = 2;
			x++;
		}
		if (usedThrees == false) {
			cout<< x << ". Threes"<<endl;
			a[x-1] = 3;
			x++;
		}
		if (usedFours == false) {
			cout<< x << ". Fours"<<endl;
			a[x-1] = 4;
			x++;
		}
		if (usedFives == false) {
			cout<< x << ". Fives"<<endl;
			a[x-1] = 5;
			x++;
		}
		if (usedSixes == false) {
			cout<< x << ". Sixes"<<endl;
			a[x-1] = 6;
			x++;
		}!
		if (usedSmStraight == false) {
			cout<< x << ". Small straight"<<endl;
			a[x-1] = 7;
			x++;
		}
		if (usedLgStraight == false) {
			cout<< x << ". Large straight"<<endl;
			a[x-1] = 8;
			x++;
		}
		if (usedThreeOfAKind == false) {
			cout<< x << ". Three of a kind"<<endl;
			a[x-1] = 9;
			x++;
		}
		if (usedFourOfAKind == false) {
			cout<< x << ". Four of a kind"<<endl;
			a[x-1] = 10;
			x++;
		}
		if (usedFullHouse == false) {
			cout<< x << ". Full house"<<endl;
			a[x-1] = 11;
			x++;
		}
		if (usedYahtzee == false) {
			cout<< x << ". Yahtzee"<<endl;
			a[x-1] = 12;
			x++;
		}
	}
}
bool smStraight(int a[]) {
	bool x = true; //Keeps checking-loop checking
	int y = 0; //Straight length
	int i = 0; //Index
	do {
		if (a[i] == a[i+1] - 1) { //Current index is 1 less than the next index
			i++; //Increment index
			y++;
			x = true; //As long as this is true, the loop keeps checking subsequent numbers
		}
		else if (a[i] == a[i+2] - 1) { //Current index is 1 less than the next next index (checking cases like 12234 or 34556)
			i = i + 2; //Skips over duplicate number's index
			y++; //Increment straight length
			x = true;
		}
		else { //Dice no longer meet straight requirements
			x = false; //Stops loop
		}
	}
	while (x == true); 

	if (y >= 3) { //3 or more (counting from 0) = small straight
		return true; //Straight confirmed
	}
	else {
		return false;
	}
}
bool lgStraight(int a[]) {
	bool x = true;
	int y = 0;
	int i = 0;
	//SAME AS SMALL STRAIGHT FUNCT
	do {
		if (a[i] == a[i+1] - 1) {
			i++;
			y++;
			x = true;
		}
		else if (a[i] == a[i+2] - 1) {
			i = i + 2;
			y++;
			x = true;
		}
		else {
			x = false;
		}
	}
	while (x == true); 

	if (y >= 4) { //4 or more (counting from 0) = large straight
		return true;
	}
	else {
		return false;
	}
}
bool threeOfAKind() {
	if (ones == 3) { //3x "1" die rolled
		return true;
	}
	else if (twos == 3) { //3x "2" die rolled
		return true;
	}
	else if (threes == 3) { //3x "3" die rolled
		return true;
	}
	else if (fours == 3) {
		return true;
	}
	else if (fives == 3) {
		return true;
	}
	else if (sixes == 3) {
		return true;
	}
	else {
		return false;
		
	}
}
bool fourOfAKind() {
	if (ones == 4) { //4x "1" die rolled
		return true;
	}
	else if (twos == 4) { //4x "2" die rolled
		return true;
	}
	else if (threes == 4) { //4x "3" die rolled
		return true;
	}
	else if (fours == 4) {
		return true;
	}
	else if (fives == 4) {
		return true;
	}
	else if (sixes == 4) {
		return true;
	}
	else {
		return false;
	}
}
bool fullHouse(int a[]) {
	if (!fourOfAKind()) { //Don't proceed if there is a four of a kind
		int uniqueNumbers = 0;
		for (int i = 0; i < 5; i++) { //For each dice
			if (a[i] != a[i+1]) { //If current index dice isn't the same as the next index, increment number of unique die
				uniqueNumbers++;
			}
		}
		if (uniqueNumbers == 2) { //Full house rolls have only 2 unique numbers
			return true;
		}
	}
	return false; //Default return false
}
bool yahtzee(int a[]) {
	if (a[0] == a[4]) {  //If first and last dice are the same in a sorted roll, everything in between is the same
		return true;
	}
	return false;
}
void printYahtzee() {
	//Fun yahtzee logo generated from https://drewish.com/projects/unicoder/ and cleaned up by hand
	cout<<"                                                               ▄▄▖    "<<endl;
	cout<<"                                                            ▗▟████▙▖  "<<endl;
	cout<<"                                                  ▗▄███▄▄  ▐███▛▜███▖ "<<endl;
	cout<<"                       ▗▄▄▄        ██      ▄▄▄██▖▗███████▙▗███    ██▌ "<<endl;
	cout<<"                       ▐███        ██▙▄▟████████▗██▛  ▝███▟█████████▌ "<<endl;
	cout<<"          ▗███▛        ▐███▄▄▄▄  ▜█████▐▛▀▀▀███▘▟██▙▟█████████        "<<endl;
	cout<<" ▜████▄  ▗████▘     ▄▄ ▐████████▙  ███     ▟██▘ █████▀▀▀▀ ▜███  ▗███  "<<endl;
	cout<<"  ▀████▙ ▟███▘ ▄██████▌▐███▀▀▜███  ███   ▗███▘  ███▌  ▗▄▟█▝████████▘  "<<endl;
	cout<<"   ▀████████▘▄████▀▜██▌▐███  ▐███  ███  ▗██▛    ▜███▄▄███▘ ▝▀███▛▀    "<<endl;
	cout<<"    ▝██████▌▐██▛▘  ▐██▌▐███  ▐███  ███ ▗███▄▄▄▟█▘▜█████▛▘             "<<endl;
	cout<<"     ▝████▛ ███▌   ▐██▌▐███  ▐███  ███ ▟████████  ▀▀▘                 "<<endl;
	cout<<"      ▐███▌▗███    ▐██▌▐███  ▐███  ███ █▛▀▀▀▘                         "<<endl;
	cout<<"      ▐███▌▐███▌  ▗███▌▐███  ▐███  ▀▀                                 "<<endl;
	cout<<"      ▐███▌ ██████████▌▐██▀                                           "<<endl;
	cout<<"      ▐███▌ ▝▜████▀▀██▌                                               "<<endl;
	cout<<"      ▐███▌                                                           "<<endl;
}