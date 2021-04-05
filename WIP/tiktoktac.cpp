#include<iostream>
using namespace std;
void printGrid();
void clearGrid();
void pickX(int c);
char a = ' ', b = ' ', c = ' ';
char d = ' ', e = ' ', f = ' ';
char g = ' ', h = ' ', i = ' ';
char defA = ' ';
char defB = ' ';
char defC = ' ';
char defD = ' ';
char defE = ' ';
char defF = ' ';
char defG = ' ';
char defH = ' ';
char defI = ' ';
//char sel = '▒';
char sel = '0';
int current = 1;
char in;
int x, y;
bool going = true;
char pick;




int main() {
	system("clear");
	a = sel;
	while (going) {
		printGrid();
		cin >> in;
		switch (in) {
			case 'a':
				if (current != 1) {
					current--;
				}
				break;
			case 'd':
				if (current != 9) {
					current++;
				}
				break;
			case 'X':
				pick = 'X';
				pickX(current);
				break;
			case 'O':
				pick = 'X';
				break;
		}
		switch(current) {
			case 1:
				clearGrid();
				if (defA != 'X') {
					a = sel;
				}
				break;
			case 2:
				clearGrid();
				b = sel;
				break;
			case 3:
				clearGrid();
				c = sel;
				break;
			case 4:
				clearGrid();
				d = sel;
				break;
			case 5:
				clearGrid();
				e = sel;
				break;
			case 6:
				clearGrid();
				f = sel;
				break;
			case 7:
				clearGrid();
				g = sel;
				break;
			case 8:
				clearGrid();
				h = sel;
				break;
			case 9:
				clearGrid();
				i = sel;
				break;
			
		}

		cout <<current <<endl;
		system("clear");

	}

	return 0;
}

void pickX(int c) {
	switch(c) {
		case 1:
			defA = 'X';
			break;
		case 2:
			clearGrid();
			b = sel;
			break;
		case 3:
			clearGrid();
			c = sel;
			break;
		case 4:
			clearGrid();
			d = sel;
			break;
		case 5:
			clearGrid();
			e = sel;
			break;
		case 6:
			clearGrid();
			f = sel;
			break;
		case 7:
			clearGrid();
			g = sel;
			break;
		case 8:
			clearGrid();
			h = sel;
			break;
		case 9:
			clearGrid();
			i = sel;
			break;
	}
}
void printGrid() {
	/* 
	   ┏━━━┳━━━┳━━━┓
	   ┃ a ┃ b ┃ c ┃
	   ┣━━━╋━━━╋━━━┫
	   ┃ d ┃ e ┃ f ┃
	   ┣━━━╋━━━╋━━━┫
	   ┃ g ┃ h ┃ i ┃
	   ┗━━━┻━━━┻━━━┛
	*/
	cout << "┏━━━┳━━━┳━━━┓" <<endl;
	cout << "┃ "<<a<<" ┃ "<<b<<" ┃ "<<c<<" ┃" <<endl;
	cout << "┣━━━╋━━━╋━━━┫" <<endl;
	cout << "┃ "<<d<<" ┃ "<<e<<" ┃ "<<f<<" ┃" <<endl;
	cout << "┣━━━╋━━━╋━━━┫" <<endl;
	cout << "┃ "<<g<<" ┃ "<<h<<" ┃ "<<i<<" ┃" <<endl;
	cout << "┗━━━┻━━━┻━━━┛" <<endl;
}

void clearGrid() {
	a = defA;
	b = defB;
	c = defC;
	d = defD;
	e = defE;
	f = defF;
	g = defG;
	h = defH;
	i = defI;
}












/*{
	f
	void box(bool top, bool bottom, bool left, bool right, char i) {
	if (left) {
		if (top) {
			cout <<"┏━━━┳"<<endl;
			cout <<"┃ "<<i<<" ┃"<<endl;
			cout <<"┣━━━╋";
		}
		else if (bottom) {
			cout <<"┃ "<<i<<" ┃"<<endl;
	   		cout <<"┗━━━┻";
		}
		else {
			cout <<"┃ "<<i<<" ┃"<<endl;
	   		cout <<"┣━━━╋";
		}
	}
	else if (right) {
		if (top) {
			cout <<"━━━┓"<<endl;
			cout <<" "<<i<<" ┃"<<endl;
			cout <<"━━━┫";
		}
		else if (bottom) {
			cout <<"┃ "<<i<<" ┃"<<endl;
	   		cout <<"┗━━━┻";
		}
		else {
			cout <<"┃ "<<i<<" ┃"<<endl;
	   		cout <<"┣━━━╋";
		}
	}}*/