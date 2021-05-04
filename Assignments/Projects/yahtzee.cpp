#include<iostream>
#include<ctime>

using namespace std;

#define enter cout<<endl;
#define clear system("clear");

void play();
void roll(int a[], bool keep[]);
void sort(int a[]);
void printDice(int a[]);
void checkPossible(int dice[]);
void printPossible(int p[]);
bool threeOfAKind();
bool fourOfAKind();
bool fullHouse(int a[]);
bool smStraight(int a[]);
bool lgStraight(int a[]);
bool yahtzee(int a[]);
void printYahtzee();

bool canOnes = false, canTwos = false, canThrees = false, canFours = false, canFives = false, canSixes = false, canSmStraight = false, canLgStraight = false, canThreeOfAKind = false, canFourOfAKind = false, canFullHouse = false, canYahtzee = false, canChance = false;
bool usedOnes = false, usedTwos = false, usedThrees = false, usedFours = false, usedFives = false, usedSixes = false, usedSmStraight = false, usedLgStraight = false, usedThreeOfAKind = false, usedFourOfAKind = false, usedFullHouse = false, usedYahtzee = false, usedChance = false;
int scoreOnes, scoreTwos, scoreThrees, scoreFours, scoreFives, scoreSixes, scoreSmStraight, scoreLgStraight, scoreThreeOfAKind, scoreFourOfAKindm, scoreYahtzee, scoreChance;
int ones, twos, threes, fours, fives, sixes;
int possible;

int main() {
	clear;
	printYahtzee();
	bool playAgain = true;
	char reroll = 'n';
	int play = 0;
	//while play again
	int rollsLeft = 3;
	int rerollDice;

	bool keptDice[5] = {false, false, false, false, false}; //false to allow dice to be set for the first time
	int dice[5];
	
	roll(dice, keptDice);
	sort(dice);
	
	printDice(dice);
	checkPossible(dice);
	int possiblePlays[possible];
	printPossible(possiblePlays);
	enter;
	do {
		do {
			cout << "Reroll? (y/n): ";
			cin >> reroll;
		}
		while (reroll != 'y' && reroll != 'n');
		if (reroll == 'y') {
			cout << "How many would you like to reroll?: ";
			cin >> rerollDice;
			for (int n = 0; n < 5; n++) {
				keptDice[n] = true; //Keep all dice
			}
			int x = 0;
			for (int i = 0; i < rerollDice; i++) {
				cout << "Enter the die positions that you want to reroll (1,2,3,4,5): ";
				cin >> x;
				keptDice[x-1] = false;
			}
			roll(dice, keptDice);
			sort(dice);
			system("clear");
			printDice(dice);
			checkPossible(dice);
			printPossible(possiblePlays);

			rollsLeft--;
		}
		else {
			rollsLeft = 1;
		}
	}
	while (rollsLeft != 1);
	//----------------------------
	
	do {
		system("clear");
		printDice(dice);
		printPossible(possiblePlays);
		enter;
		cout << "What would you like to do? (Enter number next to available play): ";
		cin >> play;
		play--;
		switch(possiblePlays[play]) {
			case 1:
				scoreOnes = ones;
				usedOnes = true;
				break;
			case 2:
				scoreTwos = 2 * twos;
				usedTwos = true;
				break;
			case 3:
				scoreThrees = 3 * threes;
				usedThrees = true;
				break;
			case 4:
				scoreFours = 4 * fours;
				usedFours = true;
				break;
			case 5:
				scoreFives = 5 * fives;
				usedFives = true;
				break;
			case 6:
				scoreSixes = 6 * sixes;
				usedSixes = true;
				break;
			case 7:
				usedSmStraight = true;
				break;
			case 8:
				usedLgStraight = true;
				break;
			case 9:
				usedThreeOfAKind = true;
				break;
			case 10:
				usedFourOfAKind = true;
				break;
			case 11:
				usedFullHouse = true;
				break;
			case 12:
				usedYahtzee = true;
				break;
			case 13:
				usedChance = true;
				break;
			default:
				cout << "ERROR" <<endl;
				break;
		}
	}
	while ((play + 1) < 1 || (play + 1) > 13);
	
	//while (turnsLeft != 1);

	
	
	//show possible
	//in choise


	//Straight logic

	
	
	return 0;
}

void roll(int a[], bool keep[]) {
	srand(time(NULL));
	for(int i = 0; i < 5; i++) {
		if (keep[i] != true) {
			a[i] = rand() % 6 + 1;
		}
	}
	ones = 0;
	twos = 0;
	threes = 0;
	fours = 0;
	fives = 0;
	sixes = 0;
	
	for (int i = 0; i < 5; i++) {
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
void sort(int a[]) {
	int j = 0;
	for(int i = 1; i < 5; i++) {
		j = i;
		while (j > 0 && a[j-1] > a[j]) {
			swap(a[j], a[j-1]);
			j--;
		}
	}
}
void printDice(int a[]) {
	cout << "Your dice:" <<endl;
	cout << "┏━━━┳━━━┳━━━┳━━━┳━━━┓" <<endl;
	cout << "┃ "<<a[0]<<" ┃ "<<a[1]<<" ┃ "<<a[2]<<" ┃ "<<a[3]<<" ┃ "<<a[4]<<" ┃" <<endl;
	cout << "┗━━━┻━━━┻━━━┻━━━┻━━━┛" <<endl;
	/*
	┏━━━┳━━━┳━━━┳━━━┳━━━┓
	┃   ┃   ┃   ┃   ┃   ┃
	┗━━━┻━━━┻━━━┻━━━┻━━━┛
	*/
}
void checkPossible(int dice[]) {
	canOnes = false, canTwos = false, canThrees = false, canFours = false, canFives = false, canSixes = false, canSmStraight = false, canLgStraight = false, canThreeOfAKind = false, canFourOfAKind = false, canFullHouse = false, canYahtzee = false, canChance = false;
	possible = 0;
	if (ones > 0 && usedOnes == false) {
		canOnes = true;
		possible++;
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
	if (smStraight(dice) && usedSmStraight == false) {
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
	if (yahtzee(dice) && usedYahtzee == false) {
		canYahtzee = true;
		possible++;
	}
	if (usedChance == false) {
		canChance = true;
		possible++;
	}
}
void printPossible(int p[]) {
	cout << "Possible plays: " <<endl;
	int x = 1;
	if (canOnes) {
		cout<< x << ". Ones"<<endl;
		p[x-1] = 1;
		x++;
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
		cout<< x << ". Small straight"<<endl;
		p[x-1] = 7;
		x++;
	}
	if (canLgStraight) {
		cout<< x << ". Large straight"<<endl;
		p[x-1] = 8;
		x++;
	}
	if (canThreeOfAKind) {
		cout<< x << ". Three of a kind"<<endl;
		p[x-1] = 9;
		x++;
	}
	if (canFourOfAKind) {
		cout<< x << ". Four of a kind"<<endl;
		p[x-1] = 10;
		x++;
	}
	if (canFullHouse) {
		cout<< x << ". Full house"<<endl;
		p[x-1] = 11;
		x++;
	}
	if (canYahtzee) {
		cout<< x << ". Yahtzee"<<endl;
		p[x-1] = 12;
		x++;
	}
	if (canChance) {
		cout<< x << ". Chance"<<endl;
		p[x-1] = 13;
		x++;
	}
}
bool smStraight(int a[]) {
	bool x = true;
	int y = 0;
	int i = 0;
	do {
		if (a[i] == a[i+1] - 1 && i < 5) {
			i++;
			y++;
			x = true;
		
		}
		else {
			if (i != 0) {
				x = false;
			}
			i++;
		}
	}
	while (x == true); 
	if (y >= 3) {
		return true;
	}
	else {
		return false;
	}

}

bool lgStraight(int a[]) {
	bool x = true;
	int y = 0;
	int i = 0;
	do {
		if (a[i] == a[i+1] - 1 && i < 5) {
			i++;
			y++;
			x = true;
		
		}
		else {
			if (i != 0) {
				x = false;
			}
			i++;
		}
	}
	while (x == true); 
	if (y >= 4) {
		return true;
	}
	else {
		return false;
	}
}
bool threeOfAKind() {
	if (ones == 3) {
		return true;
	}
	else if (twos == 3) {
		return true;
	}
	else if (threes == 3) {
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
	if (ones == 4) {
		return true;
	}
	else if (twos == 4) {
		return true;
	}
	else if (threes == 4) {
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
	if (!fourOfAKind()) { 
		int uniqueNumbers = 0;
		for (int i = 0; i < 5; i++) {
			if (a[i] != a[i+1]) {
				uniqueNumbers++;
			}
		}
		if (uniqueNumbers == 2) {
			return true;
		}
	}
	return false;
}
bool yahtzee(int a[]) {
	if (a[0] == a[4]) {
		return true;
	}
	return false;
}
void printYahtzee() {
	cout<<"                                                               ▄▄▖    "<<endl;
	cout<<"                                                            ▗▟████▙▖  "<<endl;
	cout<<"                                                  ▗▄███▄▄  ▐███▛▜███▖ "<<endl;
	cout<<"                       ▗▄▄▄        ██      ▄▄▄██▖▗███████▙▗███    ██▌ "<<endl;
	cout<<"                       ▐███        ██▙▄▟████████▗██▛  ▝███▟█████████▌ "<<endl;
	cout<<"          ▗███▛        ▐███▄▄▄▄  ▜█████▐▛▀▀▀███▘▟██▙▟████████▛        "<<endl;
	cout<<" ▜████▄  ▗████▘     ▄▄▌▐████████▙  ███     ▟██▘ █████▀▀▀▀ ▜███  ▗███  "<<endl;
	cout<<"  ▀████▙ ▟███▘ ▄██████▌▐███▀▀▜███  ███   ▗███▘  ███▌  ▗▄▟█▝████████▘  "<<endl;
	cout<<"   ▀████████▘▄████▀▜██▌▐███  ▐███  ███  ▗██▛    ▜███▄▄███▘ ▝▀███▛▀    "<<endl;
	cout<<"    ▝██████▌▐██▛▘  ▐██▌▐███  ▐███  ███ ▗███▄▄▄▟█▘▜█████▛▘             "<<endl;
	cout<<"     ▝████▛ ███▌   ▐██▌▐███  ▐███  ███ ▟████████  ▀▀▘                 "<<endl;
	cout<<"      ▐███▌▝███    ▐██▌▐███  ▐███  ███ █▛▀▀▀▘                         "<<endl;
	cout<<"      ▐███▌▐███▌  ▗███▌▐███  ▐███  ▀▀                                 "<<endl;
	cout<<"      ▐███▌ ██████████▌▐██▀                                           "<<endl;
	cout<<"      ▐███▌ ▝▜████▀▀██▌                                               "<<endl;
	cout<<"      ▐███▌                                                           "<<endl;
}


/*
3ofakind 111, 222, 333, 444, 5
12346

11234

sm straight if on number that could start a sm straihgt ( 1 or 2 ) start checking next, keeping 

function for roll
multiple rolls keeping certain dice
*/
