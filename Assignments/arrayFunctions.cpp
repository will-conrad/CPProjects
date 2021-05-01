/*
--Passing variables: --
void thing(int n) 
void thing(bool x)
void thing(double z)

- Called with just name

--For arrays:--
double average(int n[])

- dont need to specify array size
- arrays default to pass by reference
- called with just name


*/

#include<iostream>
using namespace std;

void bubble(long a[]);

//Numbers of 
const long num = 10000; //Global!! 

int main()
{
	srand(time(NULL));
	long grades[num];
	
	cout << "Unsorted Array: " << endl;
	for(int i = 0; i < num; i++)
	{
		grades[i] = rand() % 101; // input random values
		cout << grades[i] << endl; // output them unsorted
	}

	bubble(grades);

	cout << "Sorted Array: " << endl;
	for(int i = 0; i < num; i++)
	{
		cout << grades[i] << endl; // output them sorted
	}
	

	return 0;
}

void bubble(long a[]) {
	bool swapped;
	do
	{
  		swapped = false;

  		// for i = 1 to indexOfLastUnsortedElement-1
		for(int i = 0; i < num-1; i++)
		{
    		if(a[i] > a[i+1])
    		{
      			swap(a[i], a[i+1]);

      			swapped = true;
      		}
      	}
	}
	while(swapped == true);
}
