#include "vex.h"
#include <math.h>

using namespace vex;


//Set Up a  left and right motor void for expo drive


//set up left drive 
void setLeftDrive (vex::directionType type, int percent) 
{
    if (percent >=0)
    {
      percent = 1.2*pow(1.043,percent) - 1.2 + 0.2*percent; 

    }
    else 
    {
      percent = -percent;
      percent = 1.2*pow(1.043,percent) - 1.2 + 0.2*percent; 
      percent = -percent;
    }

  LeftMotorF.spin (type, percent, vex::velocityUnits::pct);
  LeftMotorB.spin (type, percent, vex::velocityUnits::pct);
}

//set up Right drive 
void setRightDrive (vex::directionType type, int percent) 
{
    if (percent >=0)
    {
      percent = 1.2*pow(1.043,percent) - 1.2 + 0.2*percent; 

    }
    else 
    {
      percent = -percent;
      percent = 1.2*pow(1.043,percent) - 1.2 + 0.2*percent; 
      percent = -percent;
    }

  RightMotorF.spin (type, percent, vex::velocityUnits::pct);
  RightMotorB.spin (type, percent, vex::velocityUnits::pct);
}
void Mecanum(){
  LeftMotorF.spin(directionType::fwd,Controller1.Axis1.value()/2 + Controller1.Axis3.value() + Controller1.Axis4.value() , velocityUnits::pct);
  LeftMotorB.spin(directionType::fwd,Controller1.Axis1.value()/2 + Controller1.Axis3.value() - Controller1.Axis4.value(), velocityUnits::pct);
  RightMotorF.spin(directionType::rev,Controller1.Axis1.value()/2 - Controller1.Axis3.value() + Controller1.Axis4.value() , velocityUnits::pct);
  RightMotorB.spin(directionType::rev,Controller1.Axis1.value()/2 - Controller1.Axis3.value() - Controller1.Axis4.value() , velocityUnits::pct);
}