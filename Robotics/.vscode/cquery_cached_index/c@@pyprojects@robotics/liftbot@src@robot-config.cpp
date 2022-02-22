#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor liftL = motor(PORT1, ratio36_1, false);
motor liftR = motor(PORT2, ratio36_1, true);
motor left_front = motor(PORT3, ratio18_1, false);
motor left_middle = motor(PORT11, ratio18_1, false);
motor left_rear = motor(PORT12, ratio18_1, false);
motor right_front = motor(PORT17, ratio18_1, true);
motor right_middle = motor(PORT18, ratio18_1, true);
motor right_rear = motor(PORT15, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}