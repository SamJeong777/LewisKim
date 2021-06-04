#include "vex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v5.h"
#include "v5_vcs.h"
using namespace vex;

// Movement code!

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// set up movement for both turning and forwards/backwards movement using both a pd function and some without// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //get average of the left motors and right motors and then 1/2 // 

double avENC2()
 {
  return (LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg) + RightMotorF.position(deg)) / 4;
 }


/* double avENC2 //find the average encoder value of all for motors then devide them by 4 to find the average 
  = LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg) + RightMotorF.position(deg)/ 4; 
*/
  //define  kp value at one place 
 
  double kP = 0.1; //step 1tune until steady minor issolation 0.0195

  //define Kd value

  double kD = 0.005; //step 2 no issolation 0.01

  //define kp value for turning at one place 
 
  double tkP = 0.125; //step 1tune until steady minor issolation 

  //define Kd value for turning at one place 

  double tkD = 0.1; //step 2 no issolation 

  // resets the encoder value for all drive motors 
  void resetEncoderValue2(){
  LeftMotorB.resetPosition();
  LeftMotorF.resetPosition();
  RightMotorB.resetPosition();
  RightMotorF.resetPosition();
  }

  // make the motors stop
  void stop2() {
  LeftMotorB.stop();
  LeftMotorF.stop();
  RightMotorB.stop();
  RightMotorF.stop();
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//set up forward and backwars movement using Potential and Derivative  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //moving forwards with P 

  void forwardPD (double goal) {
    //reset encoder value from last 
    resetEncoderValue2();
    //define error 
    double error = goal - avENC2(); 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error >10) { 

      //Potential
      error =  goal - avENC2(); 

      //Derivative
      derivative = error - prevError; 

      //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * kP + derivative * kD, voltageUnits::volt);
       LeftMotorF.spin(forward,error * kP + derivative * kD, voltageUnits::volt);
       RightMotorB.spin(forward,error * kP +  derivative * kD, voltageUnits::volt);
       RightMotorF.spin(forward,error * kP + derivative * kD, voltageUnits::volt);

       prevError = error; 
        vex::task::sleep(10); 
   }
   stop2();

  }

  //move backwards using PD drive 

  void backwardPD (double goal) {
    //reset encoder value from last 
    resetEncoderValue2();
    //define error 
    double error = goal - avENC2(); 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error < -10) { 

      //Potential
      error =  goal - avENC2(); 

      //Derivative
      derivative = error - prevError; 

      //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * kP + derivative * kD, pct);
       LeftMotorF.spin(forward,error * kP + derivative * kD, pct);
       RightMotorB.spin(forward,error * kP +  derivative * kD, pct);
       RightMotorF.spin(forward,error * kP + derivative * kD, pct);

       prevError = error; 
        vex::task::sleep(20); 
   }
   stop2();

  }

   //Turn using PD drive 

  void turnPDBAD (double goal) {
    //reset encoder value from last 
    resetEncoderValue2();
    //define error 
    double error = goal - avENC2(); 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error > 3) { 

      //Potential
      error =  goal - avENC2(); 

      //Derivative
      derivative = error - prevError; 

      //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * tkP + derivative * tkD, pct);
       LeftMotorF.spin(forward,error * tkP + derivative * tkD, pct);
       RightMotorB.spin(reverse,error * tkP +  derivative * tkD, pct);
       RightMotorF.spin(reverse,error * tkP + derivative * tkD, pct);

       prevError = error; 
        vex::task::sleep(10); 
   }
   stop2();

  }


  void forwardInPD (double goal) {
    //reset encoder value from last 
    resetEncoderValue2();
    //define error 
    double error = goal - avENC2(); 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error >3) { 

      //Potential
      error =  goal - avENC2(); 

      //Derivative
      derivative = error - prevError; 

      //move the motors depending on the kp, and error
       IntakeR.spin(forward,error * kP + derivative * kD *3, pct);
       IntakeL.spin(forward,error * kP + derivative * kD *3, pct); 
       LeftMotorB.spin(forward,error * kP + derivative * kD, pct);
       LeftMotorF.spin(forward,error * kP + derivative * kD, pct);
       RightMotorB.spin(forward,error * kP +  derivative * kD, pct);
       RightMotorF.spin(forward,error * kP + derivative * kD, pct);

       prevError = error; 
        vex::task::sleep(10); 
   }
   stop2();

  }


  void SlideRight() {
    LeftMotorF.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::rev, 120, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::rev, 120, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    task::sleep(10);
    LeftMotorF.stop(brakeType::brake);
    RightMotorF.stop(brakeType::brake);
    LeftMotorB.stop(brakeType::brake);
    RightMotorB.stop(brakeType::brake);
  }

  void SlideRight1(int time) {
    LeftMotorF.spin(directionType::fwd, 50, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::rev, 50, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::rev, 50, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, 50, vex::velocityUnits::pct);
    task::sleep(time);
    LeftMotorF.stop(brakeType::brake);
    RightMotorF.stop(brakeType::brake);
    LeftMotorB.stop(brakeType::brake);
    RightMotorB.stop(brakeType::brake);
  }
  void SlideLeft() {
    LeftMotorF.spin(directionType::rev, 20, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::fwd, 20, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, 20, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::rev, 20, vex::velocityUnits::pct);
    task::sleep(10);
    LeftMotorF.stop(brakeType::brake);
    RightMotorF.stop(brakeType::brake);
    LeftMotorB.stop(brakeType::brake);
    RightMotorB.stop(brakeType::brake);
  }
  void SlideLeft1(int time) {
    LeftMotorF.spin(directionType::rev, 20, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::fwd, 20, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, 20, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::rev, 20, vex::velocityUnits::pct);
    task::sleep(time);
    LeftMotorF.stop(brakeType::brake);
    RightMotorF.stop(brakeType::brake);
    LeftMotorB.stop(brakeType::brake);
    RightMotorB.stop(brakeType::brake);
  }
  void slide(double _pct_, float displacement, bool bl){ //Mecanum wheel normal slide function ***** set right as positive unit: cm
  LeftMotorF.setVelocity(_pct_,percent);
  LeftMotorB.setVelocity(_pct_,percent);
  RightMotorF.setVelocity(_pct_,percent);
  RightMotorB.setVelocity(_pct_,percent);

  float PERIMETER = 53;
  float RequestedValue = displacement / PERIMETER * 360;

  LeftMotorF.spinFor(RequestedValue,degrees,false);
  LeftMotorB.spinFor(-RequestedValue,degrees,false);
  RightMotorF.spinFor(-RequestedValue ,degrees,false);
  RightMotorB.spinFor(RequestedValue,degrees, bl);
}

 void my_Move(int _pct_, int displacement){ // convert inch to cm unit: cm  USING: normal moving without PID
  LeftMotorF.setVelocity(_pct_,percent);
  LeftMotorB.setVelocity(_pct_,percent);
  RightMotorF.setVelocity(_pct_,percent);
  RightMotorB.setVelocity(_pct_,percent);

  float PERIMETER = 53;
  float RequestedValue = displacement / PERIMETER * 360;

  LeftMotorF.spinFor(RequestedValue,degrees,false);
  LeftMotorB.spinFor(RequestedValue,degrees,false);
  RightMotorF.spinFor(RequestedValue,degrees,false);
  RightMotorB.spinFor(RequestedValue,degrees);
}
  void moving(int direction, int time, int takeType, int roller) {
  if (direction == 1) {
    // Forward
    LeftMotorF.spin(directionType::fwd, 70, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::fwd, 70, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, 70, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, 70, vex::velocityUnits::pct);
    
  } else if (direction == 2) {
    // Right
    LeftMotorF.spin(directionType::rev, 120, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::rev, 120, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    
  } else if (direction == 3) {
    // Backward
    LeftMotorF.spin(directionType::rev, 50, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::rev, 50, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::rev, 50, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::rev, 50, vex::velocityUnits::pct);
    
  } else if (direction == 4) {
    // Left
    LeftMotorF.spin(directionType::rev, 120, vex::velocityUnits::pct);
    RightMotorF.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, 120, vex::velocityUnits::pct);
    RightMotorB.spin(directionType::rev, 120, vex::velocityUnits::pct);
    
  } else if (direction == 5) {
    // Not moving
    LeftMotorB.stop(brakeType::brake);
    LeftMotorF.stop(brakeType::brake);
    RightMotorB.stop(brakeType::brake);
    RightMotorF.stop(brakeType::brake);
    }else {
    return;
  }

  if (takeType == 1) {
    // Intake
    IntakeR.spin(directionType::fwd,120, vex::velocityUnits::pct);
    IntakeL.spin(directionType::fwd,120, vex::velocityUnits::pct);
  } else if (takeType == 2) {
    // Outtake
    IntakeR.spin(directionType::rev,120, vex::velocityUnits::pct);
    IntakeL.spin(directionType::rev,120, vex::velocityUnits::pct);
  } else if (takeType == 3) {
    // Nothing
  } else {
    return;
  }

  // Move ball all the way up
  if (roller == 1) {
   TopIndexer.spin(directionType::rev, 140, vex::velocityUnits::pct);
   BottomIndexer.spin(directionType::fwd, 140, vex::velocityUnits::pct);
  }

  //bottom roller only for collecting the ball 
  if (roller == 2) {
    BottomIndexer.spin(directionType::fwd, 140, vex::velocityUnits::pct);
  }
  //TopMotor spins up
  if (roller == 3) {
    TopIndexer.spin(directionType::rev, 140, vex::velocityUnits::pct);
  }
  //Balls out from the front bottom
  if (roller == 4) {
    TopIndexer.spin(directionType::fwd, 140, vex::velocityUnits::pct);
    BottomIndexer.spin(directionType::rev, 140, vex::velocityUnits::pct);
  }
  //Stop 
  if (roller == 5) {
    //RollerTopMotor.stop(brakeType::brake);
    //RollerBottomMotor.stop(brakeType::brake);
  }
  if (roller == 6) {
    TopIndexer.spin(directionType::fwd, 140, vex::velocityUnits::pct);
    BottomIndexer.spin(directionType::fwd, 140, vex::velocityUnits::pct);
  }
  if (roller == 7) { //Bottom rollers only for the removing ball with the front bottom
    BottomIndexer.spin(directionType::rev, 140, vex::velocityUnits::pct);
  }
  task::sleep(time); //2400
  TopIndexer.stop();
  BottomIndexer.stop();
  LeftMotorB.stop(brakeType::brake);
  LeftMotorF.stop(brakeType::brake);
  RightMotorB.stop(brakeType::brake);
  RightMotorF.stop(brakeType::brake);

  // stop intake/outtake if running
  if (takeType == 1 || takeType == 2) {
   IntakeR.stop();
   IntakeL.stop();
  
  }
}

void MoveF () {
  LeftMotorF.spin(directionType::fwd, 20, vex::velocityUnits::pct);
  RightMotorF.spin(directionType::fwd, 20, vex::velocityUnits::pct);
  LeftMotorB.spin(directionType::fwd, 20, vex::velocityUnits::pct);
  RightMotorB.spin(directionType::fwd, 20, vex::velocityUnits::pct);
}