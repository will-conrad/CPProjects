#include<iostream>
using namespace std;

int main() {
	int even = 0;
	int odd = 0;
	srand(time(NULL));
	int numbers[25];
	for (int i = 0; i < 25; i++) {
		numbers[i] = rand() %100 + 1;
		cout << numbers[i] << endl;
		if (numbers[i] %2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}
	cout << even << " even numbers" <<endl;
	cout << odd << " odd numbers" <<endl;
	return 0;
}

