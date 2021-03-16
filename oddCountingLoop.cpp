#include<iostream>
using namespace std;

int main() {
	int n;
	for(n = 50; n > 0; n--) {
		if (n %2 == 0) {
			cout << n << endl;
		}
	}
	return 0;
}