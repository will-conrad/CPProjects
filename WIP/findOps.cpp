#include<iostream>

using namespace std;

int r1, r2, r3, r4, r5; //5 ops

double a, b, c, d, e, f; //6 numbers
void randOps();
int main() {
	srand(time(NULL));
	int z = 0; //Total
	int groups = 0;
	int length = 0;
	int eq[6] = {31, 5, 2, 6, 6, 12};

	while (z != 18) {
		z = 0;
		groups = 0;
		randOps();
		int ops[5] = {r1, r2, r3, r4, r5};
		printf("%i, %i, %i, %i, %i\n", r1, r2, r3, r4, r5);
		for (int i = 0; i < 5; i++) {
			if (ops[i] >= 2) {
				groups++;
			}
		}
		length = 5 - (groups - 1);
		//cout << length <<endl;
		int final[length];
		int c = 0;
		for (int l = 6; l > length; l--) {
			for (int i = 0; i < 5; i++) {
				if (ops[i] == 2) {
					final[c] = eq[i] * eq[i + 1];
				}
				else if (ops[i] == 3) {
					final[c] = eq[i] / eq[i + 1];
				}
				c++;
			}
		}
		
		for (int f = 0; f < length; f++) {
			
			switch(ops[f]) {
				case 0:
					final[0] = final[0] + final[f+1];
					break;
				case 1:
					final[0] = final[0] - final[f+1];
					break;
			}	
			
		}
		//z = final[0];
		

		//cout << z << endl;
	}
	
	//cout << groups << endl;
	return 0;
}
void randOps() {
	srand(time(NULL));
	//0 = plus
	//1 = minus
	//2 = multiply
	//3 = divide
	r1 = rand() % 4;
	r2 = rand() % 4;
	r3 = rand() % 4;
	r4 = rand() % 4;
	r5 = rand() % 4;
}
/*
0 1 2 3
+ - * /

33 + 5 - ((2 / 6) * 6) + 12
2 groups
length 4

//33 + 5 - 2 + 12
01321

(((33 / 5) / 2) / 6) - 6 + 12
x + 12
5 - (groups - 1)



20332

(31 * 5) + (((2 / 6) / 6) * 12)
groups = 4
length = 2


*/