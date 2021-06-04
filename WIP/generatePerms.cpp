#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int clock = 0;
	char lttrArr[20];
	int up, right;
	int cursorX = 0, cursorY = 6;

	long intList[1000];
	for (int i = 0; i < 1000; i++) {
		intList[i] = 0;
	}
	int grid[7][7];

	long intCode = 0;
	long codeArr[20];
	for (int i = 0; i < 20; i++) {
		codeArr[i] = 0;
	}
	int temp = 0;
	int length = 0;
	int n = 0;
	bool add = true;
	srand(time(NULL));
	ofstream fileOut;
	fileOut.open ("perms2.txt");	
	while (clock < 20000000) {
		clock++;
		for (int h = 0; h < 7; h++) {
			for (int w = 0; w < 7; w++) {
				grid[h][w] = 0; 
			}
		}
		cursorX = 0;
		cursorY = 6;
		up = 0;
		right = 0;
		intCode = 0;
		//Generate number
		for (int i = 0; i < 20; i++) {
			codeArr[i] = 0;
			lttrArr[i] = ' ';
		}
		length = 0;
		
		switch(rand()%6) {
			case 0:
				length = 8;
				break;
			case 1:
				length = 10;
				break;
			case 2:
				length = 12;
				break;
			case 3:
				length = 14;
				break;
			case 4:
				length = 6;
				break;
		}
		for (int i = 0; i < length; i++) {
			codeArr[i] = rand()%4 + 1;
			intCode = 10 * intCode + codeArr[i]; 
		}
		add = true;
		for (int i = 0; i < n + 1; i++) {
			if (intCode == intList[i]) {
				add = false;
			}
		}
		if (add) {
			for (int i = 0; i < length; i++) {
				switch(codeArr[i]) {
					case 1:
						up++;
						break;
					case 2:
						right++;	
						break;
					case 3:
						up--;		
						break;
					case 4:
						right--;
						break;
				}
			}
			add = false;
			if (up == 3 && right == 3) {
				add = true;
			}
			if (add == true) {
				for (int i = 0; i < length; i++) {
					if (add == true) {
						grid[cursorY][cursorX] = grid[cursorY][cursorX] + 1;
						switch(codeArr[i]) {
							case 1: //Up
								cursorY = cursorY - 2;
								grid[cursorY+1][cursorX] = grid[cursorY+1][cursorX] + 1;
								break;
							case 2: //Right
								cursorX = cursorX + 2;
								grid[cursorY][cursorX-1] = grid[cursorY][cursorX-1] + 1;
								break;
							case 3: //Down
								cursorY = cursorY + 2;
								grid[cursorY-1][cursorX] = grid[cursorY-1][cursorX] + 1;
								break;
							case 4: //Left
								cursorX = cursorX - 2;
								grid[cursorY][cursorX+1] = grid[cursorY][cursorX+1] + 1;
								break;
						}
					}
					//cout << cursorX << " " << cursorY <<endl;
					if (cursorX > 6 || cursorY > 6 || cursorX < 0 || cursorY < 0) {
						add = false;
						//cout << "OOB" << endl;
					}
				}
				if (add == true) {
					for (int h = 0; h < 7; h++) {
						for (int w = 0; w < 7; w++) {
							if (grid[h][w] > 1) {
								
								add = false;
							}
						}
					}
				}
				//cout << intCode <<endl;
			}
		}
		if (add == true) {
			clock = 0;
			for (int i = 0; i < length; i++) {
				switch(codeArr[i]) {
					case 1:
						lttrArr[i] = 'U';
						break;
					case 2:
						lttrArr[i] = 'R';						
						break;
					case 3:
						lttrArr[i] = 'D';
						break;
					case 4:
						lttrArr[i] = 'L';
						break;
				}
			}
			intList[n] = intCode;
			cout << intCode <<endl;

			
			for (int i = 0; i < length; i++) {
				fileOut << lttrArr[i];
			}
			fileOut << "\n";
			
			n++;
			
		}
		
	}
	fileOut.close();
	return 0;
}
