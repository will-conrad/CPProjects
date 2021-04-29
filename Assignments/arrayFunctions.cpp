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


