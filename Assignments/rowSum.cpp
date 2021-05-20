#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	srand(time(NULL));
	int grid[10][10];
	int rowSum[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int r = 0; r < 10; r++) {    //Nested
		for (int c = 0; c < 10; c++) {//Loop
			grid[r][c] = rand()%100;
			rowSum[r] = rowSum[r] + grid[r][c];
			cout << setw(3) << grid[r][c];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Sums for each row: " <<endl;
	for (int i = 0; i < 10; i++) {
		cout << rowSum[i] <<endl;
	}
	cout << endl;
	return 0;
}
