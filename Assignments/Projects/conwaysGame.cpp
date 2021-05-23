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

//Colors: https://stackoverflow.com/a/2616912
//Char In: https://stackoverflow.com/a/912184

int main() {
	cout << "\033[0m\033[0m";
	string tile = "▞▞";
	int key;
	char charIn;
	int neighbors = 0;
	bool alive = false;
	bool unique = false;

	int cursorX = 0;
	int cursorY = 0;

	string FE_MAT[HEIGHT][WIDTH]; //Front End Matrix
	string BE_MAT[HEIGHT + 2][WIDTH + 2]; //Back End Matrix

	for (int h = 0; h < HEIGHT + 2; h++) {
		for (int w = 0; w < WIDTH + 2; w++) {
			BE_MAT[h][w] = "  ";
			if (h < HEIGHT && w < WIDTH) {
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
			for (int h = 0; h < HEIGHT + 1; h++) {
				for (int w = 0; w < WIDTH + 1; w++) {
					if (h < HEIGHT && w < WIDTH) {
						if (FE_MAT[h][w] == "  " && (cursorX != w || cursorY != h)) { //Dead, No cur
							//cout << "\033[30m██\033[0m";
							cout << "  ";
						}
						else if (FE_MAT[h][w] == "  " && (cursorX == w && cursorY == h)) { //Dead, cur
							//cout << "\033[34;1;40m▞▞\033[0m";
							cout << "\033[1;36m▞▞\033[0m";
						}
						else if (FE_MAT[h][w] == tile && (cursorX != w || cursorY != h)) { //Alive, No cur
							//cout << "██";
							cout << "\033[37;47m"<<tile<<"\033[0m";

						}
						else if (FE_MAT[h][w] == tile && (cursorX == w && cursorY == h)) { //Alive, cur
							cout << "\033[7;46;37m▞▞\033[0m";
						}
						else {
							//return 0;
						}
					}
					else if (h == HEIGHT && w < WIDTH) {
						cout << "══";
					}
					else if (w == WIDTH && h < HEIGHT) {
						cout << "║";
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
					if (FE_MAT[cursorY][cursorX] == tile) {
						FE_MAT[cursorY][cursorX] = "  ";
					}
					else {
						FE_MAT[cursorY][cursorX] = tile;
					}
					break;
				default:
					break;
			}
		} 
		while (key != 6);
	}
	else {
		srand(time(NULL));
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				if (rand()%5 == 1) {
					FE_MAT[h][w] = tile;
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
		unique = false;
		//SET BACKEND TO SAME AS FRONT END
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				if (BE_MAT[h+1][w+1] != FE_MAT[h][w]) {
					unique = true;
				}
				BE_MAT[h+1][w+1] = FE_MAT[h][w];
				if (FE_MAT[h][w] != "  ") {
					cout << "\033[37;47m" << FE_MAT[h][w] << "\033[0m";
				}
				else {
					cout << "  ";
				}
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
		if (!unique) {
			return 0;
		}
		usleep(50000);
		
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
				if (BE_MAT[h][w] == tile) {
					alive = true;
				}
				if (BE_MAT[h-1][w-1] == tile) {
					neighbors++;
				}
				if (BE_MAT[h-1][w] == tile) {
					neighbors++;
				}
				if (BE_MAT[h-1][w+1] == tile) {
					neighbors++;
				}
				if (BE_MAT[h][w-1] == tile) {
					neighbors++;
				}
				if (BE_MAT[h][w+1] == tile) {
					neighbors++;
				}
				if (BE_MAT[h+1][w-1] == tile) {
					neighbors++;
				}
				if (BE_MAT[h+1][w] == tile) {
					neighbors++;
				}
				if (BE_MAT[h+1][w+1] == tile) {
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
							FE_MAT[h-1][w-1] = tile;
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
	}
	while(true);
	return 0;
}

int keyIn() {
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