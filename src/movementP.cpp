
#include "vex.h"

using namespace vex;

// Movement code!

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// set up movement for both turning and forwards/backwards movement using both a pid function and some without// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //get average of the left front and back motors and right front and back motors and then 1/4 // 

 int avENC1()
 {
  return (LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg) + RightMotorF.position(deg)) / 4;
 }


 /*double avENC1 //find the average encoder value of all for motors then devide them by 4 to find the average 
  = (LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg) + RightMotorF.position(deg))/ 4; 
*/
   

  // resets the encoder value for all drive motors 
  void resetEncoderValue(){
  LeftMotorB.resetPosition();
  LeftMotorF.resetPosition();
  RightMotorB.resetPosition();
  RightMotorF.resetPosition();
  }
  // make the motors stop
  void stop1() {
  LeftMotorB.stop();
  LeftMotorF.stop();
  RightMotorB.stop();
  RightMotorF.stop();
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//set up forward and backwars movement using P 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //moving forwards with P 

  void forwardP (double goal) {
    //define forward kp value at one place 
    double Kp = 0.05;
    //reset encoder value from last 
    resetEncoderValue();
    //define error 
    double error = goal - avENC1(); 
    //create a small deadband for error
    while (error > 2) {
      error = goal - avENC1();
     //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * Kp, pct);
       LeftMotorF.spin(forward,error * Kp, pct);
       RightMotorB.spin(forward,error * Kp, pct);
       RightMotorF.spin(forward,error * Kp, pct);
   }
   stop1();

  }

void backwardP (double goal) {
    //define  kp value at one place 
    double Kp = 0.0175;
    //reset encoder value from last 
    resetEncoderValue();
    //define error 
    double error = goal - avENC1(); 
    //create a small deadband for error
    while (error < 2) {
      error = goal - avENC1();
     //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * Kp, pct);
       LeftMotorF.spin(forward,error * Kp, pct);
       RightMotorB.spin(forward,error * Kp, pct);
       RightMotorF.spin(forward,error * Kp, pct);
   }
   stop1();

  }
