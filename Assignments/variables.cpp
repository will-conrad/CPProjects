#include<iostream>
using namespace std;

int main() {
	int bradyWins;
	int buccaneers;
	int chiefs;
	// int buccaneers, chiefs, bradyWins;
	
	buccaneers = 31;
	chiefs = 9;
	bradyWins = 6;

    cout << "Final Score: " << buccaneers << " - " << chiefs <<endl;

    if (buccaneers > chiefs) { //If Buccaneers win, add 1 to bradyWins
    	cout << "Brady has " << bradyWins + 1 << " rings"<<endl;
    }
	
	return 0;
}
//./a.out

