#include<iostream>

using namespace std;

int main() {
	//Declare width and height
	double w; 
	double h;
	
	//Decl area and perimeter
	double area;
	double peri;

	cout<<endl;
	
	cout <<"Enter the width: "; //Input width
	cin >> w;
	cout <<"Enter the height: "; //Input height
	cin >> h;

	area = w*h; //Calc area
	peri = (w*2)+(h*2); //Calc perimeter

	cout<<endl;

	//Output calculations
	cout <<"The area is: " << area <<endl;
	cout <<"The perimeter is: " << peri <<endl;

	cout<<endl;

	return 0;
}