#include<iostream>
using namespace std;

int main() {
	int a[5];
	srand(time(NULL));
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	for(int x = 0; x < 1000; x++) {
		for(int i = 0; i < 5; i++) {
			a[i] = rand() % 6 + 1;
			switch(a[i]) {
				case 1:
					one++;
					break;
				case 2:
					two++;
					break;
				case 3:
					three++;
					break;
				case 4:
					four++;
					break;
				case 5:
					five++;
					break;
				case 6:
					six++;
					break;
			}
			system("clear");
			printf("One: %d, Two: %d, Three: %d, Four: %d, Five: %d, Six: %d\n", one, two, three, four, five, six);
		}
	

	}

	
	return 0;
}
