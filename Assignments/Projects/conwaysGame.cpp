#include<iostream>
#include<iomanip>
#include<unistd.h>
#include <stdio.h>
using namespace std;

#define enter cout << endl;
#define clear system("clear");

const int WIDTH = 20;
const int HEIGHT = 20;
const string tile = "██";

void glider1(string a[][WIDTH], int w, int h);
void glider2(string a[][WIDTH], int w, int h);
void galaxy(string a[][WIDTH], int w, int h);

//Colors: https://stackoverflow.com/a/2616912
//Char In: https://stackoverflow.com/a/912184

int main() {
	int cursorColor = 2;

	int key = -1;
	char charIn;
	int neighbors = 0;
	bool alive = false;
	bool stable = true;
	bool edit, progress, advance;
	int cursorX = (WIDTH/2) -1;
	int cursorY = (HEIGHT/2) -1;

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
	do {
		cout << "Enter custom locations? (y/n): ";
		cin >> charIn;
	}
	while (charIn != 'y' && charIn != 'n');
	if (charIn == 'y') {
		edit = true;
	}
	do {
		if (edit) {
			do {
				clear;
				for (int h = 0; h < HEIGHT + 1; h++) {
					for (int w = 0; w < WIDTH + 1; w++) {
						if (h < HEIGHT && w < WIDTH) {
							if (FE_MAT[h][w] == "  " && (cursorX != w || cursorY != h)) { //Dead, No cur
								cout << "  ";
							}
							else if (FE_MAT[h][w] == "  " && (cursorX == w && cursorY == h)) { //Dead, cur
								//cout << "\033[34;1;40m▞▞\033[0m";
								cout << "\033[1;3"<<cursorColor<<"m▞▞\033[0m";
							}
							else if (FE_MAT[h][w] == tile && (cursorX != w || cursorY != h)) { //Alive, No cur
								cout << "\033[37;47m  \033[0m";
							}
							else if (FE_MAT[h][w] == tile && (cursorX == w && cursorY == h)) { //Alive, cur
								cout << "\033[7;4"<<cursorColor<<";37m▞▞\033[0m";
							}
						}
						else if (h == HEIGHT && w == WIDTH) {
							cout << "╝";
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
				cout << "(" << cursorX << "," << cursorY << ")" << endl;
				enter;
				cout << "\033[4mUse the Arrow Keys to move the cursor\033[0m" << endl;
				cout << "Press Space to toggle a block" << endl;
				cout << "Press 1 or 2 to add a glider, or press 3 to add a galaxy" << endl;
				cout << "Press 3 to add a galaxy" << endl;
				cout << "Press C to clear" << endl;
				enter;
				cout << "\033[1mPress E to exit\033[0m" << endl;
				
				system("stty raw"); 
				charIn = getchar();
				if ((int)charIn == 101) {
					key = 0; //e
				}
				else if ((int)charIn == 32) {
					key = 5; //Space
				}
				else if ((int)charIn == 99) {
					key = 6; //C
				}
				else if ((int)charIn == 49) {
					key = 7; // 1
				}
				else if ((int)charIn == 50) {
					key = 8; // 2
				}
				else if ((int)charIn == 51) {
					key = 9; // 3
				}
				else if ((int)charIn == 27) {
					for (int x = 0; x < 2; x++) {
						charIn = getchar();
						if ((int)charIn == 65) {
							key = 1; //Up
						}
						else if ((int)charIn == 66) {			
							key = 2; //Down
						}
						else if ((int)charIn == 68) {						
							key = 3; //Left
						}
						else if ((int)charIn == 67) {
							key = 4; //Right
						}
					}
				}
				else  {
					key = -1;
				}
				system("stty cooked"); 

				switch(key) {
					case 0:
						edit = false;
						break;
					case 1:
						if (cursorY != 0) {
							cursorY--;
						}
						else {
							cursorY = HEIGHT -1;
						}
						break;
					case 2:
						if (cursorY != HEIGHT -1) {
							cursorY++;
						}
						else {
							cursorY = 0;
						}
						break;
					case 3:
						if (cursorX != 0) {
							cursorX--;
						}
						else {
							cursorX = WIDTH -1;
						}
						break;
					case 4:
						if (cursorX < HEIGHT - 1) {
							cursorX++;
						}
						else {
							cursorX = 0;
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
					case 6:
						for (int h = 0; h < HEIGHT; h++) {
							for (int w = 0; w < WIDTH; w++) {
								FE_MAT[h][w] = "  ";
							}
						}
						break;
					case 7:
						glider1(FE_MAT, cursorX, cursorY);
						break;
					case 8:
						glider2(FE_MAT, cursorX, cursorY);
						break;
					case 9:
						galaxy(FE_MAT, cursorX, cursorY);
						break;
					default: 
						break;
				}
			} 
			while (edit == true);
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
		edit = false;

		do {
			for (int h = 0; h < HEIGHT; h++)  {
				for (int w = 0; w < WIDTH; w++) {
					BE_MAT[h+1][w+1] = FE_MAT[h][w];
				}
			}
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
				}
			}

			//Print Front end matrix
			clear; //Clear
			stable = true;
			for (int h = 0; h < HEIGHT; h++)  {
				for (int w = 0; w < WIDTH; w++) {
					if (BE_MAT[h+1][w+1] != FE_MAT[h][w]) {
						stable = false;
					}
					if (FE_MAT[h][w] != "  ") {
						cout << "\033[37;47m" << FE_MAT[h][w] << "\033[0m";
					}
					else {
						cout << "  ";
					}
				}
				enter;
			}
			if (stable) {
				return 0;
			}
			cout << "Hold Space to advance" <<endl;
			cout << "Press E to edit" <<endl;
			cout << "Press Tab to quit" <<endl;
			do {
				advance = false;
				
				system("stty raw"); 
				charIn = getchar();
				key = (int)charIn;
				system("stty cooked");

				if (key == 101) {
					edit = true;
					advance = true;
				}
				else if (key == 32) {
					advance = true;
				}
				else if (key == 9) {
					advance = true;
				}
			}
			while (advance == false);
		}
		while(edit == false && key != 9);
	}
	while(key != 9);
	return 0;
}

void glider1(string a[][WIDTH], int w, int h) {
	if (w < WIDTH - 1 && w > 0 && h < HEIGHT - 1 && h > 0) {
		a[h-1][w] = tile;
		a[h][w-1] = tile;
		a[h+1][w-1] = tile;
		a[h+1][w] = tile;
		a[h+1][w+1] = tile;
	}
}
void glider2(string a[][WIDTH], int w, int h) {
	if (w < WIDTH - 2 && w > 2 && h < HEIGHT - 2 && h > 0) {
		a[h-1][w] = tile;
		a[h-1][w+1] = tile;
		a[h][w-3] = tile;
		a[h][w-2] = tile;
		a[h][w-1] = tile;
		a[h][w+1] = tile;
		a[h][w+2] = tile;
		a[h+1][w-3] = tile;
		a[h+1][w-2] = tile;
		a[h+1][w-1] = tile;
		a[h+1][w] = tile;
		a[h+1][w+1] = tile;
		a[h+2][w-2] = tile;
		a[h+2][w-1] = tile;
		a[h+2][w] = tile;
	}
}

void galaxy(string a[][WIDTH], int w, int h) {
	if (w < WIDTH - 4 && w > 3 && h < HEIGHT - 4 && h > 3) {
		a[h-4][w-4] = tile;
		a[h-4][w-3] = tile;
		a[h-4][w-2] = tile;
		a[h-4][w-1] = tile;
		a[h-4][w] = tile;
		a[h-4][w+1] = tile;
		a[h-4][w+3] = tile;
		a[h-4][w+4] = tile;
		a[h-3][w-4] = tile;
		a[h-3][w-3] = tile;
		a[h-3][w-2] = tile;
		a[h-3][w-1] = tile;
		a[h-3][w] = tile;
		a[h-3][w+1] = tile;
		a[h-3][w+3] = tile;
		a[h-3][w+4] = tile;
		a[h-2][w+3] = tile;
		a[h-2][w+4] = tile;
		a[h-1][w-4] = tile;
		a[h-1][w-3] = tile;
		a[h-1][w+3] = tile;
		a[h-1][w+4] = tile;
		a[h][w-4] = tile;
		a[h][w-3] = tile;
		a[h][w+3] = tile;
		a[h][w+4] = tile;
		a[h+1][w-4] = tile;
		a[h+1][w-3] = tile;
		a[h+1][w+3] = tile;
		a[h+1][w+4] = tile;
		a[h+2][w-4] = tile;
		a[h+2][w-3] = tile;
		a[h+3][w-4] = tile;
		a[h+3][w-3] = tile;
		a[h+3][w-1] = tile;
		a[h+3][w] = tile;
		a[h+3][w+1] = tile;
		a[h+3][w+2] = tile;
		a[h+3][w+3] = tile;
		a[h+3][w+4] = tile;
		a[h+4][w-4] = tile;
		a[h+4][w-3] = tile;
		a[h+4][w-1] = tile;
		a[h+4][w] = tile;
		a[h+4][w+1] = tile;
		a[h+4][w+2] = tile;
		a[h+4][w+3] = tile;
		a[h+4][w+4] = tile;
	}
}
