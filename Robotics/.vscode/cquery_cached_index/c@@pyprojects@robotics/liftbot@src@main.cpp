/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       willconrad                                                */
/*    Created:      Fri Jan 21 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// liftL                motor         1               
// liftR                motor         2               
// left_front           motor         3               
// left_middle          motor         11              
// left_rear            motor         12              
// right_front          motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
float myVariable, liftSpeed, forwardSpeed, turnSpeed, leftWheels, rightWheels;
float leftV, rightV, liftV;
float stickScale = 0.85;

float lerp(float a, float b, float t) {
  return a + t * (b - a);
}

float scaleInput(float x)
{
  x = lerp(0, 100, x);
  return stickScale * pow(x, 3) + (x * (1 - stickScale));
}
void spinMotors() {
  // Spin wheels to preset velocity
  liftL.spin(forward);
  liftR.spin(forward);
  left_front.spin(forward);
  left_middle.spin(forward);
  left_rear.spin(forward);
  right_front.spin(forward);
  right_middle.spin(forward);
  right_rear.spin(forward);
}
void updateVelocity() {
  //Calculate correct wheel speeds
  int driveMode = 0; //0 = original 1 = new
  if (driveMode == 0)
  {
    leftV = Controller1.Axis3.position() + Controller1.Axis4.position();
    rightV = Controller1.Axis3.position() - Controller1.Axis4.position();
    liftV = Controller1.Axis1.position();
  }
  else
  {
    leftV = Controller1.Axis3.position();
    rightV = Controller1.Axis2.position();
    if (Controller1.ButtonUp.pressing())
    {
      liftV = 127;
    }
    else
    {
      liftV = -127;
    }
  }
  //Set velocity
  liftL.setVelocity(lerp(0, 100, liftV), percent);
  liftR.setVelocity(lerp(0, 100, liftV), percent);
  left_front.setVelocity(scaleInput(leftV), percent);
  left_middle.setVelocity(scaleInput(leftV), percent);
  left_rear.setVelocity(scaleInput(leftV), percent);
  right_front.setVelocity(scaleInput(rightV), percent);
  right_middle.setVelocity(scaleInput(rightV), percent);
  right_rear.setVelocity(scaleInput(rightV), percent);
}

// "when started" hat block
int drive() {
  liftL.setStopping(hold);
  liftR.setStopping(hold);
  
  left_front.setStopping(brake);
  left_middle.setStopping(brake);
  left_rear.setStopping(brake);
  right_front.setStopping(brake);
  right_middle.setStopping(brake);
  right_rear.setStopping(brake);

  
  while (true) {
    rightWheels = Controller1.Axis3.position() - Controller1.Axis4.position();
    leftWheels = Controller1.Axis3.position() + Controller1.Axis4.position();
    liftSpeed = Controller1.Axis1.position();
    liftL.setVelocity(liftSpeed, percent);
    liftR.setVelocity(liftSpeed, percent);
    left_front.setVelocity(leftWheels, percent);
    left_middle.setVelocity(leftWheels, percent);
    left_rear.setVelocity(leftWheels, percent);
    right_front.setVelocity(rightWheels, percent);
    right_middle.setVelocity(rightWheels, percent);
    right_rear.setVelocity(rightWheels, percent);
    liftL.spin(forward);
    liftR.spin(forward);
    left_front.spin(forward);
    left_middle.spin(forward);
    left_rear.spin(forward);
    right_front.spin(forward);
    right_middle.spin(forward);
    right_rear.spin(forward);
  
    wait(5, msec);
  }
  return 0;
}


int main() {
  vexcodeInit();
  drive();
}