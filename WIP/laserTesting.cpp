#include<iostream>
#include<cmath>
#include<unistd.h>

using namespace std;

float inc, autoTurnSpeed, stickRotate, stickSideways, L, R, distDiff, aDeg, aRad, angleScale, scaling, autoAngle, pi = 3.14159;
bool objLeft;

bool laserLDetect();
bool laserRDetect();
float laserAvg();
void updateDirection();


#define enter cout<<endl;

int main() {
	
	angleScale = 10;
	autoTurnSpeed = 20;

	cout << "Enter L distance: ";
	cin >> L;
	cout << "Enter R distance: ";
	cin >> R;
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
	inc = 1.5;
	/*if (L < R) {
		L = L + inc;
		R = R - inc;
	}
	else {
		L = L - inc;
		R = R + inc;
	}
	*/
	//usleep(500000);
	//system("clear");
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
float laserAvg() {
	return (L + R) / 2;
}
void updateDirection() {
	scaling = 9;
	angleScale = 10;
	if (laserLDetect() && laserRDetect()) {
		distDiff = R - L;
		aRad = atan(distDiff / 33);
		aDeg = aRad * (180/pi); //Calculate degrees
   		autoAngle = (aDeg * angleScale) / (laserAvg() / scaling); //Scale result
   		
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

