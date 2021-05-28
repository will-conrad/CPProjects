#include<iostream>
#include<iomanip>
using namespace std;

//Formatting macros for convenience
#define enter cout << endl;
#define clear system("clear");

//Matrix height and width
const int WIDTH = 30;
const int HEIGHT = 30;

//Preset/Precoded patterns that the user can add while editing
void glider(bool a[][WIDTH], int w, int h);
void ship1(bool a[][WIDTH], int w, int h);
void ship2(bool a[][WIDTH], int w, int h);
void galaxy(bool a[][WIDTH], int w, int h);

//Colors: https://stackoverflow.com/a/2616912
//Char In: https://stackoverflow.com/a/912184

int main() {
	int edge, corner; //Identifies if any given tile is a corner, edge, which corner or edge, or if it's neither
	char charIn; //Used as a buffer from cin >> anytime a character needs inputting
	int neighbors = 0; //Number of neighbors any given tile has
	bool stable = true; //If a matrix will never change (Stable)
	bool edit = false; //If a user is in edit mode
	bool wrapping = false; //True if game has edge wrapping
	bool advance = true; //Continue looping only if user has entered acceptable keys
	int cursorX = (WIDTH/2) -1; //Sets the cursor in the middle of the grid by default
	int cursorY = (HEIGHT/2) -1; //Sets the cursor in the middle of the grid by default
	do { //Ask user if they want to enable wrapping until they enter either a 'y' or a 'n'
		cout << "Enable wrapping? (y/n): ";
		cin >> charIn;
	}
	while (charIn != 'y' && charIn != 'n');
	if (charIn == 'y') {
		wrapping = true; //Set to true if 'y'
	}

	do { //Ask user if they want to proceed into edit mode
		cout << "Enter custom locations? (y/n): ";
		cin >> charIn;
	}
	while (charIn != 'y' && charIn != 'n');
	if (charIn == 'y') {
		edit = true; //Set to true if 'y'
	}
	//There are 2 copys of the code, one allows wrapping and one doesnt.
	//With wrapping, tiles on the right edge treat the adjacent edge like a continuation of the left edge, making a
	//theoretically infinite matrix.  With wrapping, the Front-end and back-end matricies are the same size.
	//Without wrapping, the back-end matrix is 2 taller and 2 wider than the front-end matrix so there is a perimeter
	//of always dead cells.  This protects the matrix from checking volatile cells outside of the index range.
	if (wrapping == false) { //NO WRAPPING, 
		bool FE_MAT[HEIGHT][WIDTH]; //Front End Matrix (shown to user)
		bool BE_MAT[HEIGHT + 2][WIDTH + 2]; //Back End Matrix is 2 wider and 2 higher so there is a perimeter of dead cells
		for (int h = 0; h < HEIGHT + 2; h++) {
			for (int w = 0; w < WIDTH + 2; w++) {
				BE_MAT[h][w] = false; //Clear Back end matrix
				if (h < HEIGHT && w < WIDTH) {
					FE_MAT[h][w] = false; //Clear front end matrix (Uses if-statement so index range isnt exceeded)
				}
			}
		}
		do { //while user hasn't inputted tab
			if (edit) { //if user chose edit mode immediately
				do { //While in edit mode
					clear; //Clear screen
					for (int h = 0; h < HEIGHT + 1; h++) { //Height and Width +1 to add border
						for (int w = 0; w < WIDTH + 1; w++) {
							if (h < HEIGHT && w < WIDTH) { //If not at the border
								if (FE_MAT[h][w] == false && (cursorX != w || cursorY != h)) { //Dead cell, No cursor
									cout << "  "; //Blank tile
								}
								else if (FE_MAT[h][w] == false && (cursorX == w && cursorY == h)) { //Dead cell, With cursor
									//Format: "\033[MODIFIER CODES SEPARATED BY ; + m + COUT MESSAGE\033[0(Resets modifiers) + m"
									//Prints checkboard pattern with green foreground
									cout << "\033[1;32m▞▞\033[0m";
								}
								else if (FE_MAT[h][w] == true && (cursorX != w || cursorY != h)) { //Live cell, No cursor
									//Prints white space (2 spaces with white background fill)
									cout << "\033[37;47m  \033[0m";
								}
								else if (FE_MAT[h][w] == true && (cursorX == w && cursorY == h)) { //Live cell, with cursor
									//Prints checkerboard with white background and green foreground
									cout << "\033[7;42;37m▞▞\033[0m";
								}
							}
							//Printing area border
							else if (h == HEIGHT && w == WIDTH) { //Corner case
								cout << "╝";
							}
							else if (h == HEIGHT && w < WIDTH) { //Bottom edge case
								cout << "══";
							}
							else if (w == WIDTH && h < HEIGHT) { //Right edge case
								cout << "║";
							}
						}
						enter; //Return
					}
					cout << "(" << cursorX << "," << cursorY << ")" << endl; //Prints cursor coords
					enter;
					//Instructions
					cout << "\033[4mUse the Arrow Keys to move the cursor\033[0m" << endl;
					cout << "Press Space to toggle a block" << endl;
					cout << "Press C to clear" << endl;
					cout << "Press R for random tiles" << endl;
					enter;
					cout << "Presets:" << endl;
					cout << "1: Glider" << endl;
					cout << "2: Mini ship" << endl;
					cout << "3: Ship" << endl;
					cout << "4: Galaxy" << endl;
					enter;
					cout << "\033[1mPress E to exit\033[0m" << endl;
					
					system("stty raw"); //Set terminal to raw input (Doesn't wait for user to hit enter)
					charIn = getchar(); //Read the character from the terminal
					//Arror keys have 3 double digit values associated with them, all with this format: 27 91 XX,
					//So if the ascii value of the character input is 27, get 2 more inputs to get the unique identifier.
					if ((int)charIn == 27) { 
						for (int x = 0; x < 2; x++) { //Get 2 more inputs
							charIn = getchar();
						}
					}
					system("stty cooked"); //Reset terminal to normal mode
		
					switch((int)charIn) { //Switch with the ascii value associated with the character
						case 101: //E
							edit = false; //Exit edit mode
							break;
						case 65: //UP
							if (cursorY != 0) { //If the cursor isnt at the top of the matrix...
								cursorY--; //Move up
							}
							else { //If at the top
								cursorY = HEIGHT -1; //Wrap cursor to the bottom of the screen
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
							FE_MAT[cursorY][cursorX] = !FE_MAT[cursorY][cursorX]; //Toggle current cell
							break;
						case 99: //C
							//Clear entire matrix
							for (int h = 0; h < HEIGHT; h++) {
								for (int w = 0; w < WIDTH; w++) {
									FE_MAT[h][w] = false;
								}
							}
							break;
						case 114: //R
							//Fill matrix with random cell states
							srand(time(NULL));
							for (int h = 0; h < HEIGHT; h++)  {
								for (int w = 0; w < WIDTH; w++) {
									if (rand()%5 == 1) { //Using rand()%5 for more sparcity
										FE_MAT[h][w] = true;
									}
									else {
										FE_MAT[h][w] = false;
									}
								}
							}
							break;
						case 49: //1
							glider(FE_MAT, cursorX, cursorY); //Adds precoded pattern
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
			else { //User didnt enter edit mode, so fill matrix with random cell states
				srand(time(NULL));
				for (int h = 0; h < HEIGHT; h++)  {
					for (int w = 0; w < WIDTH; w++) {
						if (rand()%5 == 1) {
							FE_MAT[h][w] = true;
						}
						else {
							FE_MAT[h][w] = false;
						}
					}
				}
			}
			edit = false; //Toggle off edit mode
			do { //While not in edit mode AND user hasn't hit tab to exit
				for (int h = 0; h < HEIGHT; h++)  {
					for (int w = 0; w < WIDTH; w++) {
						BE_MAT[h+1][w+1] = FE_MAT[h][w]; //Copy Front end matric to backend martix centered with a 1 wide border
					}
				}
				for (int h = 1; h < HEIGHT + 1; h++)  { //For the portion of the Back end matrix with the same dimentions as the Front End matrix (1 to 20)
					for (int w = 1; w < WIDTH + 1; w++) {
						neighbors = 0; //Reset neighbor count

						//Check status of tiles in all 8 directions 1
						if (BE_MAT[h-1][w-1] == true) {
							neighbors++; //TL
						}
						if (BE_MAT[h-1][w] == true) {
							neighbors++; //T
						}
						if (BE_MAT[h-1][w+1] == true) {
							neighbors++; //TR
						}
						if (BE_MAT[h][w-1] == true) {
							neighbors++; //L
						}
						if (BE_MAT[h][w+1] == true) {
							neighbors++; //R
						}
						if (BE_MAT[h+1][w-1] == true) {
							neighbors++; //BL
						}
						if (BE_MAT[h+1][w] == true) {
							neighbors++; //B
						}
						if (BE_MAT[h+1][w+1] == true) {
							neighbors++; //BR
						}
						if (BE_MAT[h][w] == true) { //If cell is alive
							if (neighbors < 2) { //If 1 neighbor
								//Currenly using for loop adjusted for Back end matrix, so shift up and left to compensate for front end matrix size
								FE_MAT[h-1][w-1] = false; //Kill
							}
							else if (neighbors > 3) { //If 4 neighbors
								FE_MAT[h-1][w-1] = false; //Kill
							}
						}
						else { //Cell is dead
							if (neighbors == 3) { //If cell has exactly 3 neighbors
								FE_MAT[h-1][w-1] = true; //Revive cell
							}
						}
					}
				}
				clear; //Clear
				stable = true; //Default case is Stable
				for (int h = 0; h < HEIGHT; h++) {
					for (int w = 0; w < WIDTH; w++) {
						//For each tile
						if (BE_MAT[h+1][w+1] != FE_MAT[h][w]) { 
							//If any front end tile is different than its 
							//corrosponding back end tile (which is always 1 time step behind),
							//We know that there is still evolution happening
							stable = false;
						}
						if (FE_MAT[h][w] == true) { //If alive
							cout << "\033[37;47m  \033[0m"; //Print white cell
						}
						else { //Dead
							cout << "  "; //Print blank space
						}
					}
					enter; //Return
				}
				if (stable) { //If the Back end and front end matrices are the same, end program
					return 0;
				}
				//Print instructions
				cout << "Hold Space to advance" <<endl;
				cout << "Press E to edit" <<endl;
				cout << "Press Tab to quit" <<endl;
				do { //Loop until user enters valid character
					advance = false; //Default to invalid  
					system("stty raw"); //Set terminal to raw input
					charIn = getchar(); //Get char input
					system("stty cooked"); //Reset terminal
					if ((int)charIn == 101) { //Ascii for E
						edit = true; //Exit main loop and switch to edit mode
						advance = true; //Exit input loop
					}
					else if ((int)charIn == 32 || (int)charIn == 9) { //Ascii for either Space or Tab
						advance = true; //Exit loop
					}
				}
				while (advance == false);
			}
			while(edit == false && (int)charIn != 9);
		}
		while((int)charIn != 9);
	}
	//===============================================================================================================
	else { //WRAPPING
		//Front end and back end matrices can be the same size because edge/corner tiles don't check adjacent tiles
		bool FE_MAT[HEIGHT][WIDTH]; //Front End Matrix
		bool BE_MAT[HEIGHT][WIDTH]; //Back End Matrix
		for (int h = 0; h < HEIGHT; h++) {
			for (int w = 0; w < WIDTH; w++) {
				//Set everything to false
				BE_MAT[h][w] = false;
				FE_MAT[h][w] = false;
			}
		}
		//Lines 331 - 478 are the same as the non-wrapping code
		do {
			if (edit) {
				do {
					clear;
					for (int h = 0; h < HEIGHT + 1; h++) {
						for (int w = 0; w < WIDTH + 1; w++) {
							if (h < HEIGHT && w < WIDTH) {
								if (FE_MAT[h][w] == false && (cursorX != w || cursorY != h)) { //Dead, No cursor
									cout << "  ";
								}
								else if (FE_MAT[h][w] == false && (cursorX == w && cursorY == h)) { //Dead, cursor
									cout << "\033[1;32m▞▞\033[0m";
								}
								else if (FE_MAT[h][w] == true && (cursorX != w || cursorY != h)) { //Alive, No cursor
									cout << "\033[37;47m  \033[0m";
								}
								else if (FE_MAT[h][w] == true && (cursorX == w && cursorY == h)) { //Alive, cursor
									cout << "\033[7;42;37m▞▞\033[0m";
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
					cout << "Press R for random tiles" << endl;
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
							else { //Wrap 
								cursorX = 0;
							}
							break;
						case 32: //SPACE
							FE_MAT[cursorY][cursorX] = !FE_MAT[cursorY][cursorX];
							break;
						case 99: //C
							for (int h = 0; h < HEIGHT; h++) {
								for (int w = 0; w < WIDTH; w++) {
									FE_MAT[h][w] = false;
								}
							}
							break;
						case 114: //R
							srand(time(NULL));
							for (int h = 0; h < HEIGHT; h++)  {
								for (int w = 0; w < WIDTH; w++) {
									if (rand()%5 == 1) {
										FE_MAT[h][w] = true;
									}
									else {
										FE_MAT[h][w] = false;
									}
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
							FE_MAT[h][w] = true;
						}
						else {
							FE_MAT[h][w] = false;
						}
					}
				}
			}
			edit = false;
			do {
				for (int h = 0; h < HEIGHT; h++)  {
					for (int w = 0; w < WIDTH; w++) {
						BE_MAT[h][w] = FE_MAT[h][w]; //Set backend mat to same as front end
					}
				}
				//For each cell
				for (int h = 0; h < HEIGHT; h++)  {
					for (int w = 0; w < WIDTH; w++) {
						neighbors = 0; //Reset neighbor count
						corner = 0; //Reset corner type
						edge = 0; //Reset edge type
						if (h == 0 && w == WIDTH-1) {
							corner = 1; //TR Corner
						}
						else if (h == HEIGHT-1 && w == WIDTH-1) {
							corner = 2; //BR Corner
						}
						else if (h == HEIGHT-1 && w == 0) {
							corner = 3; //BL Corner
						}
						else if (w == 0 && h == 0) {
							corner = 4; //TL Corner
						}
						//Check if current index is on an edge
						else if (h == 0) {
							edge = 1; //Top edge
						}
						else if (w == WIDTH-1) {
							edge = 2; //Right edge
						}
						else if (h == HEIGHT-1) {
							edge = 3; //Bottom edge
						}
						else if (w == 0) {
							edge = 4; //Left edge
						}
						if (corner > 0) { //If current cell IS a corner
							switch(corner) {
								case 1: //TR Corner
									if (BE_MAT[HEIGHT-1][WIDTH-2] == true) { 
										neighbors++; //TL tile relative to corner cell checks opposite side of matrix
									}
									if (BE_MAT[HEIGHT-1][WIDTH-1] == true) {
										neighbors++; //Top
									}
									if (BE_MAT[HEIGHT-1][0] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[0][WIDTH-2] == true) {
										neighbors++; //Left
									}
									if (BE_MAT[0][0] == true) {
										neighbors++; //Right
									}
									if (BE_MAT[1][WIDTH-2] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[1][WIDTH-1] == true) {
										neighbors++; //Bottom
									}
									if (BE_MAT[1][0] == true) {
										neighbors++; //BR
									}
									break;
								case 2:
									if (BE_MAT[HEIGHT-2][WIDTH-2] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[HEIGHT-2][WIDTH-1] == true) {
										neighbors++; //T
									}
									if (BE_MAT[HEIGHT-2][0] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[HEIGHT-1][WIDTH-2] == true) {
										neighbors++; //L
									}
									if (BE_MAT[HEIGHT-1][0] == true) {
										neighbors++; //R
									}
									if (BE_MAT[0][WIDTH-2] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[0][WIDTH-1] == true) {
										neighbors++; //B
									}
									if (BE_MAT[0][0] == true) {
										neighbors++; //BR
									}
									break;
								case 3:
									if (BE_MAT[HEIGHT-2][WIDTH-1] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[HEIGHT-2][0] == true) {
										neighbors++; //T
									}
									if (BE_MAT[HEIGHT-2][1] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[HEIGHT-1][WIDTH-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[HEIGHT-1][1] == true) {
										neighbors++; //R
									}
									if (BE_MAT[0][WIDTH-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[0][0] == true) {
										neighbors++; //B
									}
									if (BE_MAT[0][1] == true) {
										neighbors++; //BR
									}
									break;
								case 4:
									if (BE_MAT[HEIGHT-1][WIDTH-1] == true) { //Check BR Corner
										neighbors++; //TL
									}
									if (BE_MAT[HEIGHT-1][0] == true) {
										neighbors++; //T
									}
									if (BE_MAT[HEIGHT-1][1] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[0][WIDTH-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[0][1] == true) {
										neighbors++; //R
									}
									if (BE_MAT[1][WIDTH-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[1][0] == true) {
										neighbors++; //B
									}
									if (BE_MAT[h+1][w+1] == true) {
										neighbors++; //BR
									}
									break;
							}
						}
						else if (edge > 0) {
							switch(edge) {
								case 1:
									if (BE_MAT[HEIGHT-1][w-1] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[HEIGHT-1][w] == true) {
										neighbors++; //T
									}
									if (BE_MAT[HEIGHT-1][w+1] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[h][w-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[h][w+1] == true) {
										neighbors++; //R
									}
									if (BE_MAT[h+1][w-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[h+1][w] == true) {
										neighbors++; //B
									}
									if (BE_MAT[h+1][w+1] == true) {
										neighbors++; //BR
									}
									break;
								case 2:
									if (BE_MAT[h-1][w-1] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[h-1][w] == true) {
										neighbors++; //T
									}
									if (BE_MAT[h-1][0] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[h][w-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[h][0] == true) {
										neighbors++; //R
									}
									if (BE_MAT[h+1][w-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[h+1][w] == true) {
										neighbors++; //B
									}
									if (BE_MAT[h+1][0] == true) {
										neighbors++; //BR
									}
									break;
								case 3:
									if (BE_MAT[h-1][w-1] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[h-1][w] == true) {
										neighbors++; //T
									}
									if (BE_MAT[h-1][w+1] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[h][w-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[h][w+1] == true) {
										neighbors++; //R
									}
									if (BE_MAT[0][w-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[0][w] == true) {
										neighbors++; //B
									}
									if (BE_MAT[0][w+1] == true) {
										neighbors++; //BR
									}
									break;
								case 4:
									if (BE_MAT[h-1][WIDTH-1] == true) {
										neighbors++; //TL
									}
									if (BE_MAT[h-1][w] == true) {
										neighbors++; //T
									}
									if (BE_MAT[h-1][w+1] == true) {
										neighbors++; //TR
									}
									if (BE_MAT[h][WIDTH-1] == true) {
										neighbors++; //L
									}
									if (BE_MAT[h][w+1] == true) {
										neighbors++; //R
									}
									if (BE_MAT[h+1][WIDTH-1] == true) {
										neighbors++; //BL
									}
									if (BE_MAT[h+1][w] == true) {
										neighbors++; //B
									}
									if (BE_MAT[h+1][w+1] == true) {
										neighbors++; //BR
									}
									break;
							}
						}
						else {
							if (BE_MAT[h-1][w-1] == true) {
								neighbors++; //TL
							}
							if (BE_MAT[h-1][w] == true) {
								neighbors++; //T
							}
							if (BE_MAT[h-1][w+1] == true) {
								neighbors++; //TR
							}
							if (BE_MAT[h][w-1] == true) {
								neighbors++; //L
							}
							if (BE_MAT[h][w+1] == true) {
								neighbors++; //R
							}
							if (BE_MAT[h+1][w-1] == true) {
								neighbors++; //BL
							}
							if (BE_MAT[h+1][w] == true) {
								neighbors++; //B
							}
							if (BE_MAT[h+1][w+1] == true) {
								neighbors++; //BR
							}
						}
						if (BE_MAT[h][w] == true) {
							if (neighbors < 2) {
								FE_MAT[h][w] = false;
							}
							else if (neighbors > 3) {
								FE_MAT[h][w] = false;
							}
						}
						else {
							if (neighbors == 3) {
								FE_MAT[h][w] = true;
							}
						}
					}
				}
				//Print Front end matrix
				clear; //Clear
				stable = true;
				for (int h = 0; h < HEIGHT; h++)  {
					for (int w = 0; w < WIDTH; w++) {
						if (BE_MAT[h][w] != FE_MAT[h][w]) {
							stable = false;
						}
						if (FE_MAT[h][w] == true) {
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
				cout << "Hold Space to advance" <<endl;
				cout << "Press E to edit" <<endl;
				cout << "Press Tab to quit" <<endl;
				do {
					advance = false;
					system("stty raw"); 
					charIn = getchar();
					system("stty cooked");

					if ((int)charIn == 101) {
						edit = true;
						advance = true;
					}
					else if ((int)charIn == 32 || (int)charIn == 9) {
						advance = true;
					}
				}
				while (advance == false);
			}
			while(edit == false && (int)charIn != 9);
		}
		while((int)charIn != 9);
	}
	return 0;
}
void glider(bool a[][WIDTH], int w, int h) {
	if (w < WIDTH - 1 && w > 0 && h < HEIGHT - 1 && h > 0) {
		a[h-1][w] = true;
		a[h][w-1] = true;
		a[h+1][w-1] = true;
		a[h+1][w] = true;
		a[h+1][w+1] = true;
	}
}
void ship1(bool a[][WIDTH], int w, int h) {
	if (w < WIDTH - 2 && w > 1 && h < HEIGHT - 2 && h > 0) {
		a[h-1][w] = true;
		a[h-1][w+1] = true;
		a[h][w-2] = true;
		a[h][w-1] = true;
		a[h][w+1] = true;
		a[h][w+2] = true;
		a[h+1][w-2] = true;
		a[h+1][w-1] = true;
		a[h+1][w] = true;
		a[h+1][w+1] = true;
		a[h+2][w-1] = true;
		a[h+2][w] = true;
	}
}
void ship2(bool a[][WIDTH], int w, int h) {
	if (w < WIDTH - 2 && w > 2 && h < HEIGHT - 2 && h > 0) {
		a[h-1][w] = true;
		a[h-1][w+1] = true;
		a[h][w-3] = true;
		a[h][w-2] = true;
		a[h][w-1] = true;
		a[h][w+1] = true;
		a[h][w+2] = true;
		a[h+1][w-3] = true;
		a[h+1][w-2] = true;
		a[h+1][w-1] = true;
		a[h+1][w] = true;
		a[h+1][w+1] = true;
		a[h+2][w-2] = true;
		a[h+2][w-1] = true;
		a[h+2][w] = true;
	}
}
void galaxy(bool a[][WIDTH], int w, int h) {
	if (w < WIDTH - 4 && w > 3 && h < HEIGHT - 4 && h > 3) {
		a[h-4][w-4] = true;
		a[h-4][w-3] = true;
		a[h-4][w-2] = true;
		a[h-4][w-1] = true;
		a[h-4][w] = true;
		a[h-4][w+1] = true;
		a[h-4][w+3] = true;
		a[h-4][w+4] = true;
		a[h-3][w-4] = true;
		a[h-3][w-3] = true;
		a[h-3][w-2] = true;
		a[h-3][w-1] = true;
		a[h-3][w] = true;
		a[h-3][w+1] = true;
		a[h-3][w+3] = true;
		a[h-3][w+4] = true;
		a[h-2][w+3] = true;
		a[h-2][w+4] = true;
		a[h-1][w-4] = true;
		a[h-1][w-3] = true;
		a[h-1][w+3] = true;
		a[h-1][w+4] = true;
		a[h][w-4] = true;
		a[h][w-3] = true;
		a[h][w+3] = true;
		a[h][w+4] = true;
		a[h+1][w-4] = true;
		a[h+1][w-3] = true;
		a[h+1][w+3] = true;
		a[h+1][w+4] = true;
		a[h+2][w-4] = true;
		a[h+2][w-3] = true;
		a[h+3][w-4] = true;
		a[h+3][w-3] = true;
		a[h+3][w-1] = true;
		a[h+3][w] = true;
		a[h+3][w+1] = true;
		a[h+3][w+2] = true;
		a[h+3][w+3] = true;
		a[h+3][w+4] = true;
		a[h+4][w-4] = true;
		a[h+4][w-3] = true;
		a[h+4][w-1] = true;
		a[h+4][w] = true;
		a[h+4][w+1] = true;
		a[h+4][w+2] = true;
		a[h+4][w+3] = true;
		a[h+4][w+4] = true;
	}
}
