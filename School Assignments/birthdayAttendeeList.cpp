#include<iostream>
using namespace std;

int main() {
	int attendee = 1;
	string name;

	bool cont = true;

	cout <<endl;
	while (cont == true) {
		cout << "Enter birthday party attendee #" << attendee << ": ";
		cin >> name;
		
		if (name == "Done" || name == "done") {
			cont = false;
			cout <<endl;

		}
		else {
			attendee++;
		}
	}


	return 0;
}