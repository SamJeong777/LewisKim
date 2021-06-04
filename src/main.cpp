/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotorB           motor         4               
// LeftMotorF           motor         2               
// RightMotorB          motor         3               
// RightMotorF          motor         1               
// inertial1            inertial      12              
// IntakeL              motor         11              
// IntakeR              motor         15              
// TopIndexer           motor         10              
// BottomIndexer        motor         5               
// DistanceLeft         distance      13              
// DistanceRight        distance      19              
// Controller1          controller                    
// Controller2          controller                    
// Optical1             optical       18              
// RangeBack            sonar         A, B            
// RangeRight           sonar         G, H            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "movementP.h"
#include "intakesAndRollers.h"
#include "movementPD.h"
#include "turnPD.h"
#include "autoLinePD.h"
#include "autoLinePDB.h"
#include "autos.h"
#include "drive.h"
#include "math.h"
#include <vex_color.h>


using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  inertial1.calibrate();
  while(inertial1.isCalibrating()){
  task::sleep(300);
  }
}

void autonomous(void) {
  // one tile is equall to 1405 or 1405 per 24 inches or 58.5 per inch or 2.30479 per mm
  
  //boardRight();
  //boardLeft();
  //sitRight();
  //sitLeft();
  sitLeftCenterGoalBeta();
  //sitLeftBetaHomeRow();
  //sitRightCenterGoalBeta1();
  //LeftCenterNew1();
 
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    int intakes = 127;
    int rollers = 127;
    bool boi;
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    Mecanum();
    if (Controller1.ButtonR2.pressing()) {  // out
        boi = true; 
        IntakeL.spin(fwd, intakes, pct);
        IntakeR.spin(reverse, intakes, pct);
        TopIndexer.spin(reverse, rollers, pct);
        BottomIndexer.spin(fwd, rollers, pct); 
      } else if (Controller1.ButtonR1.pressing()) { // in
         boi = true;
        IntakeL.spin(reverse, intakes, pct); // +10 %
        IntakeR.spin(fwd, intakes, pct);
        TopIndexer.spin(fwd, rollers, pct);
        BottomIndexer.spin(reverse, rollers, pct);
      } // to outtake balls  
        else if (Controller1.ButtonX.pressing()) {
           boi = true;
        TopIndexer.spin(reverse, rollers, pct);
        BottomIndexer.spin(forward, rollers, pct);
      } else if (Controller1.ButtonL2.pressing()) {
         boi = true;
        IntakeL.spin(forward, intakes, pct); 
        IntakeR.spin(forward, intakes, pct);
        
        
        } else{
          boi = false; 
        IntakeL.stop(brakeType::hold);
        IntakeR.stop(brakeType::hold);
        TopIndexer.stop(brakeType::hold);
        BottomIndexer.stop(brakeType::hold);
      } 
        if ((boi = false))  {
          if (Controller2.ButtonL2.pressing()) {
       IntakeL.spin(forward, intakes, pct);
        IntakeR.spin(forward, intakes, pct);
        TopIndexer.spin(forward, rollers, pct);
        BottomIndexer.spin(forward, rollers, pct);
        }
                    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
                  
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
