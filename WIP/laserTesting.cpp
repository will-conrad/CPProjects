#include<iostream>
#include<cmath>
#include<unistd.h>

using namespace std;

float autoTurnSpeed, stickRotate, stickSideways, L, R, distDiff, aDeg, aRad, angleScale, autoAngle, pi = 3.14159;
bool objLeft;

bool laserLDetect();
bool laserRDetect();
void updateDirection();

#define enter cout<<endl;

int main() {
	int x = 1;
	angleScale = 1;
	autoTurnSpeed = 20;
	while(x == 1) {
		cout << "Enter L distance: ";
		cin >> L;
		cout << "Enter R distance: ";
		cin >> R;
		enter;
		cout << L <<endl;
		cout << R <<endl;
		enter;
		while (L != R) {
			enter;
			cout << L <<endl;
			cout << R <<endl;
			enter;
			if (laserLDetect() || laserRDetect()) {
				updateDirection();
				if (objLeft) {
					cout << "Object is Left" <<endl;
				}
				else {
					cout << "Object is Right" <<endl;
				}
				cout << "Rad = " << aRad <<endl;
				cout << "Deg = " << aDeg <<endl;
				cout << "Stick rotate = " << stickRotate <<endl;
				cout << "Stick sideways = " << stickSideways <<endl;
				enter;
			}
			if (L < R) {
				L++;
				R--;
			}
			else if (L > R) {
				L--;
				R++;
			}
			usleep(150000);
			system("clear");
		}
		x = 0;
	}
}

bool laserLDetect() {
	if (L == 0) {
		return false;
	}
	else {
		return true;
	}
}
bool laserRDetect() {
	if (R == 0) {
		return false;
	}
	else {
		return true;
	}
}
void updateDirection() {
	if (laserLDetect() && laserRDetect()) {
		distDiff = R - L;
		aRad = atan(distDiff / 33);
		aDeg = aRad * (180/pi); //Calculate degrees
   		autoAngle = aDeg * angleScale; //Scale result
   		
   		stickRotate = (autoAngle * -1);  //Set rotation to scaled output
    	stickSideways = autoAngle; //Set sideways transform to scaled output
   		if (aDeg < 0) { //-
      		objLeft = false; // Negative = right
    	}
    	else if (aDeg > 0) { //+
        	objLeft = true; //Positive = left
    	}
	}
	else if (laserLDetect()) { //Only LaserL sees object
    	objLeft = true;
    	stickRotate = autoTurnSpeed * -1.0;
    	stickSideways = 0;
    }
  	else if (laserRDetect()) {
    	objLeft = false;
    	stickRotate = autoTurnSpeed;
    	stickSideways = 0;
    }
}

