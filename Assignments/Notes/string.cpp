#include<iostream>
#include<string> //String is its own header
using namespace std;
/*
String: 
-Array of characters
-Act like variables
-declared as string name = "";
-can have an index + other params
 -size
 -name.length()
 -http://www.cplusplus.com/reference/string/string/

*/
//Substr
string quote = "We think in generalities, but we live in details.";
string excerpt = quote.substr(3,5); //"think"

int main(){
	string name;

	cout << "Enter name: ";
	//cin >> name;
	getline(cin,name);
	cout << "Hi, " << endl;
	for (int i = 0; i < name.length(); i++){
		cout << name[i] <<endl;
	}
	return 0;
}