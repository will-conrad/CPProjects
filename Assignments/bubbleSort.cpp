<<<<<<< HEAD
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

=======
/*

Sorting Algorithms:

Algorithm: step by step process used to solved a problem or
           accomplish a task
           
Examples:

1) Bubble Sort

2) Selection Sort

3) Insertion Sort

Bubble Sort Pseudocode:

do

  swapped = false

  for i = 1 to indexOfLastUnsortedElement-1

    if leftElement > rightElement

      swap(leftElement, rightElement)

      swapped = true

while swapped


WEBSITE THAT HAD THE SORTING DEMOS:

https://visualgo.net/en/sorting?slide=1

*/

#include<iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	
	const int num = 17;
	
	int grades[num];
	
	bool swapped;
	
	cout << "Unsorted Array: " << endl;
	for(int i = 0; i < num; i++)
	{
		grades[i] = rand() % 101; // input random values
		cout << grades[i] << endl; // output them unsorted
	}
	
	// HERE IS WHERE THE SORTING HAPPENS
	do
	{
  		swapped = false;

  		// for i = 1 to indexOfLastUnsortedElement-1
		for(int i = 0; i < num-1; i++)
		{
    		if(grades[i] > grades[i+1])
    		{
      			swap(grades[i], grades[i+1]);

      			swapped = true;
      		}
      	}
	}
	while(swapped == true);
	
	cout << "Sorted Array: " << endl;
	for(int i = 0; i < num; i++)
	{
		cout << grades[i] << endl; // output them sorted
	}
	

	return 0;
}


>>>>>>> origin/main
