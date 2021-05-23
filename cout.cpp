#include <iostream> 
//#include <stdio.h>  
using namespace std;  

int main() { 
	//https://stackoverflow.com/a/912184
    system("stty raw");
    int x = 0;
    char input;
	do {
		input = getchar();
		cout << (int)input;
	}
	while (input != 'z');
	


	
	system("stty cooked");
    return 0; 
}
