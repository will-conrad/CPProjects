#include<iostream>
#include<iomanip>
#include<unistd.h>
#include <stdio.h>
using namespace std;

#define enter cout << endl;
#define clear system("clear");

int keyIn();
const int WIDTH = 20;
const int HEIGHT = 20;


int main() {
	cout << "\033[0m\033[0m";
	int key;
	char charIn;
	int neighbors = 0;
	bool alive = false;
	int bgBlankColor = 30;
	//int bgUnderCursorColor = 
	//int selectedColor = 
	//int selectedUnderCursorColor = 

	int cursorX = 0;
	int cursorY = 0;

	string FE_MAT[HEIGHT][WIDTH]; //Front End Matrix
	bool BOOL_MAT[HEIGHT][WIDTH]; //Boolean Matrix
	string BE_MAT[HEIGHT + 2][WIDTH + 2]; //Back End Matrix

	for (int h = 0; h < HEIGHT + 2; h++) {
		for (int w = 0; w < WIDTH + 2; w++) {
			BE_MAT[h][w] = "  ";
			if (h < HEIGHT && w < WIDTH) {
				BOOL_MAT[h][w] = false;
				FE_MAT[h][w] = "  ";
			}
		}
	}
	/*
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			BOOL_MAT[h][w] = false;
			FE_MAT[h][w] = "  ";
		}
	}
	*/
	do {
		cout << "Enter custom locations? (y/n): ";
		cin >> charIn;
	}
	while (charIn != 'y' && charIn != 'n');
	
	if (charIn == 'y') {
		do {
			clear;
			for (int h = 0; h < HEIGHT; h++) {
				for (int w = 0; w < WIDTH; w++) {
					if (BOOL_MAT[h][w] == false && (cursorX != w || cursorY != h)) { //Dead, No cur
						//cout << "\033[30m██\033[0m";
						cout << "  ";
					}
					else if (BOOL_MAT[h][w] == false && (cursorX == w && cursorY == h)) { //Dead, cur
						//cout << "\033[34;1;40m▞▞\033[0m";
						cout << "\033[34m▞▞\033[0m";
					}
					else if (BOOL_MAT[h][w] == true && (cursorX != w || cursorY != h)) { //Alive, No cur
						cout << "██";
					}
					else if (BOOL_MAT[h][w] == true && (cursorX == w && cursorY == h)) { //Alive, cur
						cout << "\033[7;1;44m▞▞\033[0m";
					}
					else {
						return 0;
					}
				}
				enter;
			} 
			key = keyIn();
			switch(key) {
				case 1:
					if (cursorY != 0) {
						cursorY--;
					}
					break;
				case 2:
					if (cursorY != HEIGHT -1) {
						cursorY++;
					}
					break;
				case 3:
					if (cursorX != 0) {
						cursorX--;
					}
					break;
				case 4:
					if (cursorX != HEIGHT -1) {
						cursorX++;
					}
					break;
				case 5:
					BOOL_MAT[cursorY][cursorX] = !BOOL_MAT[cursorY][cursorX];
					break;
				default:
					break;
			}
		} 
		while (key != 6);
		
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				if (BOOL_MAT[h][w] == true) {
					FE_MAT[h][w] = "██";
				}
			}
		}
	}
	else {
		srand(time(NULL));
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				if (rand()%7 == 1) {
					FE_MAT[h][w] = "██";
				}
				else {
					FE_MAT[h][w] = "  ";
				}
			}
		}
	}
	/*
	for (int h = 0; h < HEIGHT; h++)  {
		for (int w = 0; w < WIDTH; w++) {
			if (BOOL_MAT[h][w] == true) {
				FE_MAT[h][w] = "██";
			}
			else {
				FE_MAT[h][w] = "  ";
			}
		}
	}
	*/
	do {
		
		clear;
		//SET BACKEND TO SAME AS FRONT END
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				BE_MAT[h+1][w+1] = FE_MAT[h][w];
				cout << FE_MAT[h][w];
				/*
				if (FE_MAT[h][w] == "██") {
					cout << FE_MAT[h][w];
				}
				else {
					cout << FE_MAT[h][w];
					//cout << "\033[30m██\033[0m";
				}
				*/
			}
			enter;
		}
		usleep(8000);
		
		/*
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				if (FE_MAT[h][w] == "██") {
					cout << FE_MAT[h][w];
				}
				else {
					cout << FE_MAT[h][w];
					//cout << "\033[30m██\033[0m";
				}
			}
			enter;
		}
		*/
		for (int h = 1; h < HEIGHT + 2; h++)  {
			for (int w = 1; w < WIDTH + 2; w++) {
				neighbors = 0;
				alive = false;
				if (BE_MAT[h][w] == "██") {
					alive = true;
				}
				if (BE_MAT[h-1][w-1] == "██") {
					neighbors++;
				}
				if (BE_MAT[h-1][w] == "██") {
					neighbors++;
				}
				if (BE_MAT[h-1][w+1] == "██") {
					neighbors++;
				}
				if (BE_MAT[h][w-1] == "██") {
					neighbors++;
				}
				if (BE_MAT[h][w+1] == "██") {
					neighbors++;
				}
				if (BE_MAT[h+1][w-1] == "██") {
					neighbors++;
				}
				if (BE_MAT[h+1][w] == "██") {
					neighbors++;
				}
				if (BE_MAT[h+1][w+1] == "██") {
					neighbors++;
				}
				if (h < HEIGHT + 1 && w < WIDTH + 1) {
					if (alive) {
						if (neighbors < 2) {
							FE_MAT[h-1][w-1] = "  ";
						}
						else if (neighbors > 3) {
							FE_MAT[h-1][w-1] = "  ";
						}
					}
					else {
						if (neighbors == 3) {
							FE_MAT[h-1][w-1] = "██";
						}
					}
				}
				/*
				else {
					if (alive) {
						if (neighbors < 2) {
							FE_MAT[h-2][w-2] = "  ";
						}
						else if (neighbors > 3) {
							FE_MAT[h-2][w-2] = "  ";
						}
					}
					else {
						if (neighbors == 3) {
							FE_MAT[h-2][w-2] = "██";
						}
					}
				}
				*/

			}
		}

		system("stty raw");
		//charIn = getchar();
		key = (int)charIn;
		system("stty cooked"); 
	}
	while(key != 9);
	return 0;
}

int keyIn() {
	//https://stackoverflow.com/a/912184
	char input;
	system("stty raw"); 
	input = getchar();

	if ((int)input == 32) {
		system("stty cooked"); 
		return 5; //Space
	}
	else if ((int)input == 9) {
		system("stty cooked"); 
		return 6; //Tab
	}
	else if ((int)input == 27) {
		for (int x = 0; x < 2; x++) {
			input = getchar();
			if ((int)input == 65) {
				system("stty cooked"); 
				return 1; //Up
			}
			else if ((int)input == 66) {
				system("stty cooked"); 
				return 2; //Down
			}
			else if ((int)input == 68) {
				system("stty cooked"); 
				return 3; //Left
			}
			else if ((int)input == 67) {
				system("stty cooked"); 
				return 4; //Right
			}
		}
	}
	system("stty cooked"); 
	return 0;
}