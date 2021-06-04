#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotorB = motor(PORT4, ratio6_1, true);
motor LeftMotorF = motor(PORT2, ratio6_1, true);
motor RightMotorB = motor(PORT3, ratio6_1, false);
motor RightMotorF = motor(PORT1, ratio6_1, false);
inertial inertial1 = inertial(PORT12);
motor IntakeL = motor(PORT11, ratio6_1, false);
motor IntakeR = motor(PORT15, ratio6_1, true);
motor TopIndexer = motor(PORT10, ratio6_1, false);
motor BottomIndexer = motor(PORT5, ratio6_1, false);
distance DistanceLeft = distance(PORT13);
distance DistanceRight = distance(PORT19);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
optical Optical1 = optical(PORT18);
sonar RangeBack = sonar(Brain.ThreeWirePort.A);
sonar RangeRight = sonar(Brain.ThreeWirePort.G);

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