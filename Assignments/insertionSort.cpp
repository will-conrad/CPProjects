#include<iostream>
using namespace std;

void insertion(int a[]);

const int size = 20; //Global!! 

int main() {
	srand(time(NULL));
	int nums[size];
	
	cout << "Unsorted Array: " << endl;
	for(int i = 0; i < size; i++) {
		nums[i] = rand() % 101; // input random values
		cout << nums[i] << endl; // output them unsorted
	}

	insertion(nums);

	cout << "Sorted Array: " << endl;
	for(int i = 0; i < size; i++) {
		// output them sorted
		cout << nums[i] << endl;
	}
	

	return 0;
}

void insertion(int a[]) {
	int j = 0;
	for(int i = 1; i < size; i++) {
		j = i;
		while (j > 0 && a[j-1] > a[j]) {
			swap(a[j], a[j-1]);
			j--;
		}
	}
}
