#include<iostream>
#include<iomanip>
#include<unistd.h>
//#include<stdio.h>
using namespace std;

#define enter cout << endl;
#define clear system("clear");

const int WIDTH = 30;
const int HEIGHT = 30;
const string tile = "██";

void glider(string a[][WIDTH], int w, int h);
void ship1(string a[][WIDTH], int w, int h);
void ship2(string a[][WIDTH], int w, int h);
void galaxy(string a[][WIDTH], int w, int h);

//Colors: https://stackoverflow.com/a/2616912
//Char In: https://stackoverflow.com/a/912184

int main() {
	int cursorColor = 2;
	int edge, corner;
	int key = -1;
	char charIn;
	int neighbors = 0;
	bool alive = false;
	bool stable = true;
	bool edit, progress, advance, toroidal;
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
				cout << "Press C to clear" << endl;
				enter;
				cout << "Presets:" << endl;
				cout << "1: Glider" << endl;
				cout << "2: Mini ship" << endl;
				cout << "3: Ship" << endl;
				cout << "4: Galaxy" << endl;
				enter;
				cout << "\033[1mPress E to exit\033[0m" << endl;
				
				system("stty raw"); 
				charIn = getchar();
				if ((int)charIn == 27) {
					for (int x = 0; x < 2; x++) {
						charIn = getchar();
					}
				}
				
				system("stty cooked"); 
	
				switch((int)charIn) {
					case 101: //E
						edit = false;
						break;
					case 65: //UP
						if (cursorY != 0) {
							cursorY--;
						}
						else {
							cursorY = HEIGHT -1;
						}
						break;
					case 66: //DOWN
						if (cursorY != HEIGHT -1) {
							cursorY++;
						}
						else {
							cursorY = 0;
						}
						break;
					case 68: //LEFT
						if (cursorX != 0) {
							cursorX--;
						}
						else {
							cursorX = WIDTH -1;
						}
						break;
					case 67: //RIGHT
						if (cursorX < HEIGHT - 1) {
							cursorX++;
						}
						else {
							cursorX = 0;
						}
						break;
					case 32: //SPACE
						if (FE_MAT[cursorY][cursorX] == tile) {
							FE_MAT[cursorY][cursorX] = "  ";
						}
						else {
							FE_MAT[cursorY][cursorX] = tile;
						}
						break;
					case 99: //C
						for (int h = 0; h < HEIGHT; h++) {
							for (int w = 0; w < WIDTH; w++) {
								FE_MAT[h][w] = "  ";
							}
						}
						break;
					case 49: //1
						glider(FE_MAT, cursorX, cursorY);
						break;
					case 50: //2
						ship1(FE_MAT, cursorX, cursorY);
						break;
					case 51: //3
						ship2(FE_MAT, cursorX, cursorY);
						break;
					case 52: //4
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
			for (int h = 1; h < HEIGHT + 1; h++)  {
				for (int w = 1; w < WIDTH + 1; w++) {
					neighbors = 0;
					alive = false;
					corner = 0;
					edge = 0;
					toroidal = true;
					
					if (toroidal) {
						if (h == 1 && w == WIDTH) {
							corner = 1;
						}
						else if (h == HEIGHT && w == WIDTH) {
							corner = 2;
						}
						else if (h == HEIGHT && w == 1) {
							corner = 3;
						}
						else if (w == 1 && h == 1) {
							corner = 4;
						}
						
						else if (h == 1) {
							edge = 1; //Top edge
						}
						else if (w == WIDTH) {
							edge = 2; //Right edge
						}
						else if (h == HEIGHT) {
							edge = 3; //Bottom edge
						}
						else if (w == 1) {
							edge = 4; //Left edge
						}
						if (BE_MAT[h][w] == tile) {
							alive = true;
						}
					}

					if (corner > 0) {
						switch(corner) {
							case 1:

							case 2:
							case 3:
							case 4:
								if (BE_MAT[h-1][w-1] == tile) {
									neighbors++; //TL
								}
								if (BE_MAT[h-1][w] == tile) {
									neighbors++; // T
								}
								if (BE_MAT[h-1][w+1] == tile) {
									neighbors++; //TR
								}
								if (BE_MAT[h][w-1] == tile) {
									neighbors++; //L
								}
								if (BE_MAT[h][w+1] == tile) {
									neighbors++; //R
								}
								if (BE_MAT[h+1][w-1] == tile) {
									neighbors++; //BL
								}
								if (BE_MAT[h+1][w] == tile) {
									neighbors++; //B
								}
								if (BE_MAT[h+1][w+1] == tile) {
									neighbors++; // BR
								}
								break;
						}
					}
					else if (edge > 0) {
						switch(edge) {
							case 1:
							case 2:
							case 3:
							case 4:
						}
					}
					else {
						if (BE_MAT[h-1][w-1] == tile) {
							neighbors++; //TL
						}
						if (BE_MAT[h-1][w] == tile) {
							neighbors++; // T
						}
						if (BE_MAT[h-1][w+1] == tile) {
							neighbors++; //TR
						}
						if (BE_MAT[h][w-1] == tile) {
							neighbors++; //L
						}
						if (BE_MAT[h][w+1] == tile) {
							neighbors++; //R
						}
						if (BE_MAT[h+1][w-1] == tile) {
							neighbors++; //BL
						}
						if (BE_MAT[h+1][w] == tile) {
							neighbors++; //B
						}
						if (BE_MAT[h+1][w+1] == tile) {
							neighbors++; // BR
						}
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
					if (FE_MAT[h][w] == tile) {
						cout << "\033[37;47m  \033[0m";
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
			cout << BE_MAT[0][0] << endl;
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
void glider(string a[][WIDTH], int w, int h) {
	if (w < WIDTH - 1 && w > 0 && h < HEIGHT - 1 && h > 0) {
		a[h-1][w] = tile;
		a[h][w-1] = tile;
		a[h+1][w-1] = tile;
		a[h+1][w] = tile;
		a[h+1][w+1] = tile;
	}
}
void ship1(string a[][WIDTH], int w, int h) {
	if (w < WIDTH - 2 && w > 1 && h < HEIGHT - 2 && h > 0) {
		a[h-1][w] = tile;
		a[h-1][w+1] = tile;
		a[h][w-2] = tile;
		a[h][w-1] = tile;
		a[h][w+1] = tile;
		a[h][w+2] = tile;
		a[h+1][w-2] = tile;
		a[h+1][w-1] = tile;
		a[h+1][w] = tile;
		a[h+1][w+1] = tile;
		a[h+2][w-1] = tile;
		a[h+2][w] = tile;
	}
}
void ship2(string a[][WIDTH], int w, int h) {
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
