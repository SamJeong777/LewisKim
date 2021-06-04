#include "vex.h"
#include <math.h>

using namespace vex;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions to auto align the left and right drive train imid the PD function 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int LAEV1() //find the average encoder valuse of both left motors 
{
  return (LeftMotorB.position(deg) + LeftMotorF.position(deg))/-2; 
}

int RAEV1() //find the average encoder valuse of both right motors
{
  return (RightMotorB.position(deg) + RightMotorF.position(deg))/-2; 
}

//find the difference between both encoder values 
int RightD1 = 0; // the diff for right 
int LeftD1 = 0; //the diff for left 

void diff1() // simply make a void for the if statements 
{
  while (true) {
 if (LAEV1 > RAEV1) //find if the left encoder value is greater then the right encoder value
 {
     RightD1 = (LAEV1() - RAEV1()); //specify the right Difference (for right motor)
     LeftD1 = RAEV1() - LAEV1(); // find the left difference (for left motor)
 }
  else if (RAEV1 > LAEV1) // find if the right encoder value is greater then the left encoder value 
  {
      RightD1 = RAEV1() - LAEV1(); //specify the right difference (for right motor)
      LeftD1 = LAEV1() - RAEV1(); // specifiy the left difference (for left motor)
  }
  else // simply make Right and Left Difference 0 if they are the same 
  { 
     RightD1 = 0; // make RightD 0
     LeftD1 = 0; // make LeftD 0 

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
 void LE1()
 {
  LeftMotorB.resetPosition();
  LeftMotorF.resetPosition();
 }
//reset right encoders
void RE1()
 {
  RightMotorB.resetPosition();
  RightMotorF.resetPosition();
 }


  // make the motors stop
  void stop5() {
  LeftMotorB.stop(brakeType::hold);
  LeftMotorF.stop(brakeType::hold);
  RightMotorB.stop(brakeType::hold);
  RightMotorF.stop(brakeType::hold);
  }
  void stop6() {
  IntakeL.stop(brakeType::hold);
  IntakeR.stop(brakeType::hold);
  }

  //LEFT PD VALUES
  double LkP1 = 0.015; //step 1 tune until steady minor issolation 0.0195

  //define Kd value

  double LkD1 = 0.006; //step 2 no issolation 0.01

  //RIGHT PD VALUES
  double RkP1 = 0.015; //step 1 tune until steady minor issolation 0.0195

  //define Kd value

  double RkD1 = 0.006; //step 2 no issolation 0.01

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Make the PD functions  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////



  void ZZ(int Ggoal , double KP , double KD){
    //reset encoder value from last 
    int goal = Ggoal * 2.3;
    RE1();
    // add LeftD to LAEV 
    int REV = (RAEV1() + RightD1); 
     //reset encoder value from last 
    LE1();
    // add LeftD to LAEV 
    int LEV = (LAEV1() + LeftD1); 
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


    while ((errorL + errorR)/2 > 20) { 
      REV = (RAEV1() + RightD1);
      LEV = (LAEV1() + LeftD1); 

      //Potential R
      errorR =  goal - REV; 
      //Potential L
      errorL =  goal - LEV; 

      //Derivative R
      derivativeR = errorR - prevErrorR; 
      //Derivative L
      derivativeL = errorL - prevErrorL;

      //move the right motors depending on the kp, error, derivative, and kd
       RightMotorB.spin(reverse,errorR * KP + derivativeR * KD, voltageUnits::volt);
       RightMotorF.spin(reverse,errorR * KP + derivativeR * KD, voltageUnits::volt);
      //move the left motors depending on the kp, error, derivative, and kd 
       LeftMotorB.spin(reverse,errorL * KP + derivativeL * KD, voltageUnits::volt);
       LeftMotorF.spin(reverse,errorL * KP + derivativeL * KD, voltageUnits::volt);

       prevErrorL = errorL; 
       prevErrorR = errorR;  
        vex::task::sleep(20); 
   }
   stop5();


  }
  void ZZ2(int Tgoal){
    int goal = Tgoal *2.30479;
    //reset encoder value from last 
    RE1();
    // add LeftD to LAEV 
    int REV = (RAEV1() + RightD1); 
     //reset encoder value from last 
    LE1();
    // add LeftD to LAEV 
    int LEV = (LAEV1() + LeftD1); 
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
      REV = (RAEV1() + RightD1);
      LEV = (LAEV1() + LeftD1); 

      //Potential R
      errorR =  goal - REV; 
      //Potential L
      errorL =  goal - LEV; 

      //Derivative R
      derivativeR = errorR - prevErrorR; 
      //Derivative L
      derivativeL = errorL - prevErrorL;

      //move the right motors depending on the kp, error, derivative, and kd
       RightMotorB.spin(reverse,errorR * RkP1 + derivativeR * RkD1, voltageUnits::volt);
       RightMotorF.spin(reverse,errorR * RkP1 + derivativeR * RkD1, voltageUnits::volt);
      //move the left motors depending on the kp, error, derivative, and kd 
       LeftMotorB.spin(reverse,errorL * LkP1 + derivativeL * LkD1, voltageUnits::volt);
       LeftMotorF.spin(reverse,errorL * LkP1 + derivativeL * LkD1, voltageUnits::volt);
      //
      IntakeL.spin(reverse, 127, pct);
      IntakeR.spin(reverse, 127, pct);
       prevErrorL = errorL; 
       prevErrorR = errorR;  
        vex::task::sleep(20); 
        
   }
   stop5();
   stop6();
   
  }

   //make a void that adds both LeftPD and RightPD together into one 
void AfPDG (int mGoal)
  {
    double fGoal = (mGoal * 2.30479);
   
    GG(fGoal,0.01,0.005);
    //LPD(fGoal); //makes the leftPD goals goal be mGoal
    //RPD(fGoal); //makes the RightPD goals goal be mGoal

  }