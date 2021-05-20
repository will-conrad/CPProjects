#include<iostream>
#include<iomanip>
#include<unistd.h>
using namespace std;

#define enter cout << endl;
#define clear system("clear");

const int WIDTH = 50;
const int HEIGHT = 50;


void fillArray(string a[][WIDTH]);
void printArray(string a[][WIDTH]);

int main() {
	int neighbors = 0;
	bool alive = false;

	string FE_MAT[HEIGHT][WIDTH]; //Front End Matrix
	string BE_MAT[HEIGHT + 2][WIDTH + 2]; //Back End Matrix

	for (int h = 0; h < HEIGHT + 2; h++) {
		for (int w = 0; w < WIDTH + 2; w++) {
			BE_MAT[h][w] = "  ";
		}
	}
	//FILL WITH RANDOM
	srand(time(NULL));
	for (int h = 0; h < HEIGHT; h++)  {
		for (int w = 0; w < WIDTH; w++) {
			if (rand()%2 == 1) {
				FE_MAT[h][w] = "██";
			}
			else {
				FE_MAT[h][w] = "  ";
			}
		}
	}
	
	while(true) {
		//SET BACKEND TO SAME AS FRONT END
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				BE_MAT[h+1][w+1] = FE_MAT[h][w];
			}
		}
		enter;
		usleep(100000);
		clear;
		//PRINT MAT
		enter;
		for (int h = 0; h < HEIGHT; h++)  {
			for (int w = 0; w < WIDTH; w++) {
				cout << FE_MAT[h][w];
			}
			enter;
		}
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
				if (h < HEIGHT && w < WIDTH) {
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
				else {
					if (alive) {
						if (neighbors < 2) {
							FE_MAT[h-1][w-1] = "  ";
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

			}
		}
	}
	/*for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			if (rand()%5 == 1) {
				cout << setw(2) << "██";
			}
			else {
				cout << setw(2) << "  ";
			}
		}
		cout << endl;
	}*/
	
	return 0;
}

void fillArray(string a[][WIDTH]) {
	srand(time(NULL));
	for (int h = 0; h < HEIGHT; h++)  {
		for (int w = 0; w < WIDTH; w++) {
			if (rand()%10 == 1) {
				a[h][w] = "██";
			}
			else {
				a[h][w] = "  ";
			}
		}
	}
}
void printArray(string a[][WIDTH]) {
	for (int h = 0; h < HEIGHT; h++)  {
		for (int w = 0; w < WIDTH; w++) {
			cout << a[h][w];
		}
		enter;
	}
}
