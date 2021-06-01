#include<iostream>
using namespace std;

//prototypes
void helloWorld();
void setStruct(string message, struct s, variable v);
struct student {
	string name;
	int gradYear;
	double GPA;
	bool isPassing;
};

int main() {
	//function calls
	helloWorld();

	//init structs
	student Frosh1;
	student Frosh2;

	printf("Enter name of first student: ");
	cin >> Frosh1.name; //Dot notation
	printf("Enter name of second student: ");
	cin >> Frosh2.name; //Dot notation

	setStruct("Enter GPA of f1", student, GPA);
	return 0;
}
//function definitions
void helloWorld() {
	cout << "Hello World!" << endl;
}

void setStruct(struct n, struct student., variable v) {
	cout << message <<endl;
	cin >> s.v;
}

/* ==================================================
Struct: a way of grouping multiple variable together
-has to be declared, initialized
-after prototypes, but before main
outline:

struct name {
	//variables
	type name1;
	type name2;
	...
};

Accessing vars in func:
-create a struct (using .(dot) notation to get the variable)
*/