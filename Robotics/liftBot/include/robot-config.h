using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor liftL;
extern motor liftR;
extern motor left_front;
extern motor left_middle;
extern motor left_rear;
extern motor right_front;
extern motor right_middle;
extern motor right_rear;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );