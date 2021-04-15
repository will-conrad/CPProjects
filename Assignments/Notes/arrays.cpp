/*
Arrays: data storage device for multiple pieces of data of the same type
- E.x daily pill container/organizer 
[M][T][W][Th][F][Sa][Su]
 0  1  2  3   4  5   6

Syntax:
type name[size];

int grades[5] = {79, 85, 94, 80, 100};

Index: the location of data in an array. (0 indexed: 0, 1, 2, 3, 4)

//Access value from array at index 1 (Second number)
cout << "The second grade is " << grades[1] << endl; 

//returns: "The second grade is 85"
====================

cout << "The grades from the last quarter were " << endl;
for (int i = 0; i < 5; i++) {
	cout << grades[i] << ", ";
}
//Returns: 
The grades from the last quarter were 79, 85, 94, 80, 100, 

====================

int finalGrade





*/
