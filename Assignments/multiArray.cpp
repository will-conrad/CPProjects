#include<iostream>
#include<iomanip>
using namespace std;

const int row = 5, col = 7;
int main() {
	srand(time(NULL));

	int array[row][col];

	for (int r = 0; r < row; r++) {    //Nested
		for (int c = 0; c < col; c++) {//Loop
			array[r][c] = rand()%100;
		}
	}
	for (int r = 0; r < row; r++) {    //Nested
		for (int c = 0; c < col; c++) {//Loop
			cout << setw(3) << array[r][c];
		}
		cout<< endl;
	
	}
	
	return 0;
}
