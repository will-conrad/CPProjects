#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	// Create a text string, which is used to output the text file
	string text;
	int x = 0;
	// Read from the text file
	ifstream list("perms.txt");

	// Use a while loop together with the getline() function to read the file line by line
	/*while (getline (list, text)) {
	  // Output the text from the file
	  cout << text <<endl;
	  x++;
	}
	*/
	for (int i = 1; i <= 3; i++) {
        getline(list, text);
        
	}
	cout << text;
	cout << x <<endl;
	// Close the file
	list.close();
	
	return 0;
}
