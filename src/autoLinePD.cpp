#include "vex.h"
#include <math.h>

using namespace vex;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions to auto align the left and right drive train imid the PD function 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int LAEV() //find the average encoder valuse of both left motors 
{
  return (LeftMotorB.position(deg) + LeftMotorF.position(deg))/2; 
}

int RAEV() //find the average encoder valuse of both right motors
{
  return (RightMotorB.position(deg) + RightMotorF.position(deg))/2; 
}

//find the difference between both encoder values 
int RightD = 0; // the diff for right 
int LeftD = 0; //the diff for left 

void diff() // simply make a void for the if statements 
{
  while (true) {
 if (LAEV > RAEV) //find if the left encoder value is greater then the right encoder value
 {
     RightD = (LAEV() - RAEV()); //specify the right Difference (for right motor)
     LeftD = RAEV() - LAEV(); // find the left difference (for left motor)
 }
  else if (RAEV > LAEV) // find if the right encoder value is greater then the left encoder value 
  {
      RightD = RAEV() - LAEV(); //specify the right difference (for right motor)
      LeftD = LAEV() - RAEV(); // specifiy the left difference (for left motor)
  }
  else // simply make Right and Left Difference 0 if they are the same 
  { 
     RightD = 0; // make RightD 0
     LeftD = 0; // make LeftD 0 

  }
 }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// set up both PDs for The LEft and Right Motor 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//clarify other functions 

//rest right encoders
 void LE()
 {
  LeftMotorB.resetPosition();
  LeftMotorF.resetPosition();
 }
//reset right encoders
void RE()
 {
  RightMotorB.resetPosition();
  RightMotorF.resetPosition();
 }


  // make the motors stop
  void stop3() {
  LeftMotorB.stop(brakeType::hold);
  LeftMotorF.stop(brakeType::hold);
  RightMotorB.stop(brakeType::hold);
  RightMotorF.stop(brakeType::hold);
  }
  void stop4() {
  IntakeL.stop(brakeType::hold);
  IntakeR.stop(brakeType::hold);
  }

  //LEFT PD VALUES
  double LkP = 0.015; //step 1 tune until steady minor issolation 0.0195

  //define Kd value

  double LkD = 0.006; //step 2 no issolation 0.01

  //RIGHT PD VALUES
  double RkP = 0.015; //step 1 tune until steady minor issolation 0.0195

  //define Kd value

  double RkD = 0.006; //step 2 no issolation 0.01

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Make the PD functions  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//left PD Movement 
void LPD (double goal) {
    //reset encoder value from last 
    LE();
    // add LeftD to LAEV 
    int LEV = (LAEV() + LeftD); 
    //define error 
    double error = goal - LEV; 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error > 10) { 
      LEV = (LAEV() + LeftD);
      //Potential
      error =  goal - LEV; 

      //Derivative
      derivative = error - prevError; 

      //move the left motors depending on the kp, error, derivative, and kd 
       LeftMotorB.spin(forward,error * LkP + derivative * LkD, pct);
       LeftMotorF.spin(forward,error * LkP + derivative * LkD, pct);

       prevError = error; 
        vex::task::sleep(10); 
   }
   stop3();

  }


//left PD Movement 
void RPD (double goal) {
    //reset encoder value from last 
    RE();
    // add LeftD to LAEV 
    int REV = (RAEV() + RightD); 
    //define error 
    double error = goal - REV; 
    //define prevError
    double prevError =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivative; // error - prevError
    //create a small deadband for error
    while (error > 10) { 
      REV = (RAEV() + RightD);

      //Potential
      error =  goal - REV; 

      //Derivative
      derivative = error - prevError; 

      //move the right motors depending on the kp, error, derivative, and kd
       RightMotorB.spin(forward,error * RkP + derivative * RkD, pct);
       RightMotorF.spin(forward,error * RkP + derivative * RkD, pct);

       prevError = error; 
        vex::task::sleep(10); 
   }
   stop3();

  }
 
 


  void GG(int Ggoal , double KP , double KD){
    //reset encoder value from last 
    int goal = Ggoal * 2.3;
    RE();
    // add LeftD to LAEV 
    int REV = (RAEV() + RightD); 
     //reset encoder value from last 
    LE();
    // add LeftD to LAEV 
    int LEV = (LAEV() + LeftD); 
    //define error 
    double errorL = goal - LEV;
    //define error 
    double errorR = goal - REV; 
    //define prevError
    double prevErrorR =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivativeR; // error - prevError
    //create a small deadband for error
     double prevErrorL =0; // position 10 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivativeL; // error - prevError
    //create a small deadband for error


    while ((errorL + errorR)/2 > 25) { 
      REV = (RAEV() + RightD);
      LEV = (LAEV() + LeftD); 

      //Potential R
      errorR =  goal - REV; 
      //Potential L
      errorL =  goal - LEV; 

      //Derivative R
      derivativeR = errorR - prevErrorR; 
      //Derivative L
      derivativeL = errorL - prevErrorL;

      //move the right motors depending on the kp, error, derivative, and kd
       RightMotorB.spin(forward,errorR * KP + derivativeR * KD, voltageUnits::volt);
       RightMotorF.spin(forward,errorR * KP + derivativeR * KD, voltageUnits::volt);
      //move the left motors depending on the kp, error, derivative, and kd 
       LeftMotorB.spin(forward,errorL * KP + derivativeL * KD, voltageUnits::volt);
       LeftMotorF.spin(forward,errorL * KP + derivativeL * KD, voltageUnits::volt);

       prevErrorL = errorL; 
       prevErrorR = errorR;  
        vex::task::sleep(20); 
   }
   stop3();


  }
  void GG2(int Tgoal){
    int goal = Tgoal *2.30479;
    //reset encoder value from last 
    RE();
    // add LeftD to LAEV 
    int REV = (RAEV() + RightD); 
     //reset encoder value from last 
    LE();
    // add LeftD to LAEV 
    int LEV = (LAEV() + LeftD); 
    //define error 
    double errorL = goal - LEV;
    //define error 
    double errorR = goal - REV; 
    //define prevError
    double prevErrorR =0; // position 20 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivativeR; // error - prevError
    //create a small deadband for error
     double prevErrorL =0; // position 20 ms ago
    // the difference between error and prevError (speeds up/slows down robot based on speed) // error - prevError : speed
    double derivativeL; // error - prevError
    //create a small deadband for error


    while (((errorL + LEV) + (errorR + REV))/2 >= 20) { 
      REV = (RAEV() + RightD);
      LEV = (LAEV() + LeftD); 

      //Potential R
      errorR =  goal - REV; 
      //Potential L
      errorL =  goal - LEV; 

      //Derivative R
      derivativeR = errorR - prevErrorR; 
      //Derivative L
      derivativeL = errorL - prevErrorL;

      //move the right motors depending on the kp, error, derivative, and kd
       RightMotorB.spin(forward,errorR * RkP + derivativeR * RkD, voltageUnits::volt);
       RightMotorF.spin(forward,errorR * RkP + derivativeR * RkD, voltageUnits::volt);
      //move the left motors depending on the kp, error, derivative, and kd 
       LeftMotorB.spin(forward,errorL * LkP + derivativeL * LkD, voltageUnits::volt);
       LeftMotorF.spin(forward,errorL * LkP + derivativeL * LkD, voltageUnits::volt);
      //
      IntakeL.spin(forward, 127, pct);
      IntakeR.spin(forward, 127, pct);
       prevErrorL = errorL; 
       prevErrorR = errorR;  
        vex::task::sleep(20); 
        
   }
   stop3();
   stop4();
   
  }

   //make a void that adds both LeftPD and RightPD together into one 
void AfPD (int mGoal)
  {
    double fGoal = (mGoal * 2.30479);
   
    GG(fGoal,0.01,0.005);
    //LPD(fGoal); //makes the leftPD goals goal be mGoal
    //RPD(fGoal); //makes the RightPD goals goal be mGoal

  }