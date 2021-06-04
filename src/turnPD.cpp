#include "vex.h"
#include <math.h>

    
void turnPD(int degree) {
  inertial1.setHeading(0, deg);

    double TkP = 0.3;
    double TkD = 0.04;
    double error = (inertial1.heading() - degree);
    double prevError = error;
    double derivative = error - prevError;
    double lateralMotorPower = (error * TkP + derivative + TkD); 
    int range = 4;
    while (fabs(error)  > range) {
      error = (inertial1.heading() - degree);
      //spin leftMotor reverse by error * kP;
      LeftMotorF.spin(reverse, lateralMotorPower, pct);
      RightMotorF.spin(forward, lateralMotorPower, pct);
      LeftMotorB.spin(reverse, lateralMotorPower, pct);
      RightMotorB.spin(forward, lateralMotorPower, pct);

      prevError = error;
      wait(20,msec);
    }

      LeftMotorF.stop();
      RightMotorF.stop();
      LeftMotorB.stop();
      RightMotorB.stop();
    
}

void Turn(double degree, float kP) {
inertial1.setRotation(0, deg);

double error = (inertial1.rotation() - degree);

int range = 4;
while (fabs(error) > range) {
error = (fabs(inertial1.rotation() - (degree)));
//spin leftMotor reverse by error * kP;
LeftMotorF.spin(reverse, error * kP, pct);
RightMotorF.spin(forward, error * kP, pct);
LeftMotorB.spin(reverse, error * kP, pct);
RightMotorB.spin(forward, error * kP, pct);

wait(10, msec);
}
      LeftMotorF.stop();
      RightMotorF.stop();
      LeftMotorB.stop();
      RightMotorB.stop();

}


int avENC6()
 {
  return (LeftMotorB.position(deg)/-1 + LeftMotorF.position(deg)/-1 + RightMotorB.position(deg) + RightMotorF.position(deg)) / 4;
 }

int avENC7()
 {
  return (LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg)/-1 + RightMotorF.position(deg)/-1) / 4;
 }

 /*double avENC1 //find the average encoder value of all for motors then devide them by 4 to find the average 
  = (LeftMotorB.position(deg) + LeftMotorF.position(deg) + RightMotorB.position(deg) + RightMotorF.position(deg))/ 4; 
*/
   

  // resets the encoder value for all drive motors 
  void resetEncoderValue9(){
  LeftMotorB.resetPosition();
  LeftMotorF.resetPosition();
  RightMotorB.resetPosition();
  RightMotorF.resetPosition();
  }
  // make the motors stop
  void stop9() {
  LeftMotorB.stop();
  LeftMotorF.stop();
  RightMotorB.stop();
  RightMotorF.stop();
  }
//90 degrees is 250
void TurnPL(double goal, double Kp) {
    //define  kp value at one place 
    
    //reset encoder value from last 
    resetEncoderValue9();
    //define error 
    double error = goal - avENC6(); 
    //create a small deadband for error
    while (error > 10) {
      error = goal - avENC6();
     //move the motors depending on the kp, and error 
       LeftMotorB.spin(reverse,error * Kp, pct);
       LeftMotorF.spin(reverse,error * Kp, pct);
       RightMotorB.spin(forward,error * Kp, pct);
       RightMotorF.spin(forward,error * Kp, pct);
   }
   stop9();

  }


  void TurnPR(double goal, double Kp) {
    //define  kp value at one place 
    
    //reset encoder value from last 
    resetEncoderValue9();
    //define error 
    double error = goal - avENC7(); 
    //create a small deadband for error
    while (error > 2) {
      error = goal - avENC7();
     //move the motors depending on the kp, and error 
       LeftMotorB.spin(forward,error * Kp, pct);
       LeftMotorF.spin(forward,error * Kp, pct);
       RightMotorB.spin(reverse,error * Kp, pct);
       RightMotorF.spin(reverse,error * Kp, pct);
   }
   stop9();

  }

