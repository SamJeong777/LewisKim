using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftMotorB;
extern motor LeftMotorF;
extern motor RightMotorB;
extern motor RightMotorF;
extern inertial inertial1;
extern motor IntakeL;
extern motor IntakeR;
extern motor TopIndexer;
extern motor BottomIndexer;
extern distance DistanceLeft;
extern distance DistanceRight;
extern controller Controller1;
extern controller Controller2;
extern optical Optical1;
extern sonar RangeBack;
extern sonar RangeRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );