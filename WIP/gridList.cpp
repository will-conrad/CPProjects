#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
#define enter cout << endl;
#define clear system("clear");
#define test cout<<"X"<<endl;
long toNum(string s);
int main() {
	string text;
	ifstream list("perms2.txt");
	char charIn;
	long listArray[200];
	for (int i = 0; i < 200; i++) {
		listArray[i] = 0;
	}
	bool next;
	int listL = 0;
	long code; 
	int size, cursorX = 0, cursorY = 6, index = 0;
	test;
	while (getline(list, text)) {
		listArray[listL] = toNum(text);
		listL++;
	}
	enter;
	test;
	//Sorting
	int j = 0;
	for(int i = 1; i < listL; i++) { 
		j = i; //Pull value out of array
		while (j > 0 && listArray[j-1] > listArray[j]) {
			swap(listArray[j], listArray[j-1]);
			j--;
		}
	}
	list.close();
	test;
	//SORTED CODES ON listArray[]
	bool grid[7][7];
	int codeArr[20];
	long number = 0;
	
	while (true) {
		cursorX = 0;
		cursorY = 6;
		for (int i = 0; i < 20; i++) {
			codeArr[i] = 0; //Wipe codeArr[]
		}
		for (int h = 0; h < 7; h++) {
			for (int w = 0; w < 7; w++) {
				grid[h][w] = false; 
			}
		}
		
		grid[0][6] = true;

		number = listArray[index];
		cout << number<<endl;
		//Print
		//need size, number from listArray to array
		size = trunc(log10(number)) + 1;
		cout << "size" << size << endl;
		
		for (int i = size - 1; i >= 0; i--) {
		    codeArr[i] = number % 10;
		    number /= 10;
		}
		clear;
		cout << "Index:" << index <<endl;
		cout << "Size: " << size <<endl;
		cout << "Code: " << listArray[index] <<endl;
		for (int i = 0; i < size; i++) {
			grid[cursorY][cursorX] = true;
			switch(codeArr[i]) {
				case 1: //Up
					cursorY = cursorY - 2;
					grid[cursorY+1][cursorX] = true;
					break;
				case 2: //Right
					cursorX = cursorX + 2;
					grid[cursorY][cursorX-1] = true;
					break;
				case 3: //Down
					cursorY = cursorY + 2;
					grid[cursorY-1][cursorX] = true;
					break;
				case 4: //Left
					cursorX = cursorX - 2;
					grid[cursorY][cursorX+1] = true;
					break;
			}
			
		}
		for (int h = 0; h < 7; h++) {
			for (int w = 0; w < 7; w++) {
				if (grid[h][w] == true) { //If alive
					cout << "\033[37;47m  \033[0m"; //Print white cell
				}
				else { //Dead
					cout << "  "; //Print blank space
				}
			}
			enter;
		}
		do {
			next = true;
			system("stty raw"); 
			charIn = getchar(); 
			if ((int)charIn == 27) { 
				for (int x = 0; x < 2; x++) { //Get 2 more inputs
					charIn = getchar();
				}
			}
			system("stty cooked");
			switch((int)charIn) { 
				case 68: //LEFT
					if (index > 0) {
						index--;
					}
					break;
				case 67: //RIGHT
					if (index < listL - 1) {
						index++;
					}
					break;
				case 32: //SPACE
					return 0;
					break;
				default:
					next = false;
					break;
			}
		}
		while (next == false);
	}
	return 0;
}

long toNum(string s) {
	long n = 0;
	long num[s.length()];

	for (int i = 0; i < s.length(); i++) {
	    switch(s[i]) {
	    	case 'U':
	    		num[i] = 1;
	    		break;
	    	case 'R':
	    		num[i] = 2;
	    		break;
	    	case 'D':
	    		num[i] = 3;
	    		break;
	    	case 'L':
	    		num[i] = 4;
	    		break;
	    	}
	    n = 10 * n + num[i]; 
	}
	return n;
}