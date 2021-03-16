#include<iostream>
using namespace std;
void updateConsole() {
  using namespace std;
  cout  << "\033[2J\n"<<endl;
  cout << "Braking: "<<endl;
  cout << "Autonomous: "<<endl;
  cout << "At line: "<<endl;
  cout << "At object: "<<endl;

}
int thing() {
	while(true) {
		updateConsole();
	}
}

int main()  {
	thing();
	

}