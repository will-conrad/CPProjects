#include<iostream>
#include<ctime>
using namespace std;

#define newl cout<<endl;


int main() {
	srand(time(NULL));
	const int num = 100;
	bool swapped;

	int grades[num];
	printf("Unsorted Array: ");
	for(int i = 0; i < num; i++) {
		grades[i] = rand() % 101; //Rand nums
		printf("%i,", grades[i]); //Output unsorted
	}
	newl;
	
	do {
		swapped = false;
		for(int i = 0; i < num-1; i++) {
			if (grades[i] > grades[i+1]) {
				swap(grades[i], grades[i+1]);
				swapped = true;
			}
		}
	} while(swapped == true);
	printf("Sorted Array: ");             
	for(int i = 0; i < num; i++) {
		printf("%i,", grades[i]); //Output unsorted
	}

	
	return 0;
}

