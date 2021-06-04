#include "vex.h"


using namespace vex;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// voids set up to make the intakes or rollers function during auto and an auto ball sorting system 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Intake(int time) {
  IntakeR.spin(directionType::rev, 120, vex::velocityUnits::pct);
  IntakeL.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  TopIndexer.spin(directionType::rev, 120, vex::velocityUnits::pct);
  BottomIndexer.spin(directionType::fwd, 110, vex::velocityUnits::pct);
  task::sleep(time);
  IntakeR.stop();
  IntakeL.stop();
  TopIndexer.stop();
  BottomIndexer.stop();
}
void POOP(int time) {
  IntakeR.spin(directionType::rev, 120, vex::velocityUnits::pct);
  IntakeL.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  TopIndexer.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  BottomIndexer.spin(directionType::fwd, 110, vex::velocityUnits::pct);
  task::sleep(time);
  IntakeR.stop();
  IntakeL.stop();
  TopIndexer.stop();
  BottomIndexer.stop();
}

void smolIntake () {
 IntakeR.spin(directionType::rev, 120, vex::velocityUnits::pct);
 IntakeL.spin(directionType::fwd, 120, vex::velocityUnits::pct);
}

void smolStop () {
  IntakeR.stop();
  IntakeL.stop();
}

void smolOuttake () {
  IntakeR.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  IntakeL.spin(directionType::rev, 120, vex::velocityUnits::pct);
}

void largeIntake () {
  IntakeR.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  IntakeL.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  BottomIndexer.spin(directionType::fwd, 120, vex::velocityUnits::pct);
}
void largeStop () {
  IntakeR.stop();
  IntakeL.stop();
  BottomIndexer.stop();
  }

void Rollers(int time) {
  TopIndexer.spin(directionType::rev, 120, vex::velocityUnits::pct);
  BottomIndexer.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  task::sleep(time);
  TopIndexer.stop();
  BottomIndexer.stop();
}
void POOP2() {
  IntakeR.spin(directionType::rev, 120, vex::velocityUnits::pct);
  IntakeL.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  TopIndexer.spin(directionType::fwd, 120, vex::velocityUnits::pct);
  BottomIndexer.spin(directionType::fwd, 110, vex::velocityUnits::pct);
}
void Poopstop () {
  IntakeR.stop();
  IntakeL.stop();
  BottomIndexer.stop();
  TopIndexer.stop();
  }
/*while(1) {
       if( OpticalSensor.color() == vex::red ) {
      TopMotor2.spin(reverse);
      TopMotor.spin(fwd);
      waitUntil(LimitSwitchC.pressing() == false);
      TopMotor.stop();
      TopMotor2.stop();
      TopMotor.spinFor(fwd, 1000, degrees, false);
      TopMotor2.spinFor(reverse, 1000, degrees, false);
      waitUntil(TopMotor2.isDone());
    }
    else
    if( OpticalSensor.color() == vex::blue ) {
  
    }
    else {
      Brain.Screen.printAt( 10, 20, "no color detected");          
    }

    // Allow other tasks to run
    this_thread::sleep_for(10);
} 
}*/

