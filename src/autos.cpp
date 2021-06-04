#include "vex.h"
#include <math.h>
#include <vex_color.h>
using namespace vex;

void checkAndStopRollers(vex::color color) {
  if(color == vex::color::red){
    // STOP ROLLERS
  }
}

void autoTest(){
  Rollers(500);
  moving(1,1000,1,2);

  turnPD(20); 
  SlideRight1(950);
  slide(30,-100,true); //20 before

  smolIntake();
  GG(260,0.0175,0.005);
  smolStop();

  turnPD(76);

  GG(180,0.0175,0.005);

  moving(5,1100,3,3);

  largeIntake();
  moving(3,300,1,2);
  largeStop();

  turnPD(270);

  smolIntake();
  GG(260,0.0175,0.005);
  smolStop();

  turnPD(45);

  GG(50,0.0175,0.005);

  moving(5,1100,3,3);
  
  largeIntake();
  moving(3,300,1,2);
  largeStop();

  turnPD(225);

  while(RangeBack.distance(vex::distanceUnits::cm) > 30){
    //Shift left
  }

  while(RangeBack.distance(vex::distanceUnits::cm) < 30){
    //Shift right
  }

  smolIntake();
  GG(260,0.0175,0.005);
  smolStop();

  turnPD(76);
  GG(60,0.0175,0.005);

  moving(5,1100,3,3);
}

void boardLeft(){
  moving(5,500,3,1);
  moving(1,800,1,2);
  moving(5,500,3,5);
  TurnPL(125, 0.450);
  moving(1,950,1,2);
  moving(5,300,1,1);//200
  moving(5,700,3,1);//3
  moving(5,300,3,4);
  moving(5,1500,2,1);

  moving(1,200,1,1);
  moving(3,400,1,2);

  //First goal
  //moving(5,1400,3,1);

  /*TurnPR(250, 0.231); 
  GG(42,0.0405,0.005);

  //Second goal
  moving(5,1400,3,1);

  ZZ(47,0.0405,0.005);
  TurnPL(250, 0.201);

  //moving(5,500,3,5);

  largeIntake();
  GG(320,0.0175,0.005);
  

  //moving(5,500,3,5);

  TurnPR(160, 0.201);
  largeStop();
  GG(92,0.0425,0.005);

  //Third goal
  moving(5,1600,3,1);

  ZZ(310,0.0175,0.005);
  TurnPL(360, 0.201);

  largeIntake();
  GG(230,0.0175,0.005);
  largeStop();

  TurnPR(280, 0.201);

  largeIntake();
  GG(180,0.0275,0.005);
  largeStop();

  //Forth goal
  moving(5,1500,2,1);

  ZZ(140,0.0175,0.005);

  TurnPL(260, 0.201);

  largeIntake();
  GG(270,0.0175,0.005);
  largeStop();

  TurnPR(150, 0.201);
  GG(160,0.0275,0.005);

  //Fifth goal
  moving(5,1100,3,1); 

  largeIntake();
  ZZ(60,0.0275,0.005);
  largeStop();
  TurnPL(307, 0.201);

  largeIntake();
  GG(260,0.0175,0.005);
  largeStop();

  
  TurnPR(250, 0.201);
  GG(20,0.0175,0.005);

  //six goal
  moving(5,1100,3,1);

  ZZ(30,0.0275,0.005);
  TurnPL(250, 0.201);
  largeIntake();
  GG(260,0.0175,0.005);
  largeStop();
  
  TurnPR(125, 0.201);
  GG(20,0.0175,0.005);

  //seven
  moving(5,1100,3,1);

  ZZ(20,0.0175,0.005);
  TurnPL(307, 0.201);
  largeIntake();
  GG(260,0.0175,0.005);
  largeStop();

  TurnPR(250, 0.201);
  GG(20,0.0175,0.005);

  //eight goal
  moving(5,1100,3,1);

  ZZ(20,0.0175,0.005);
  TurnPL(250, 0.201);

  largeIntake();
  GG(130,0.0175,0.005);
  largeStop();

  slide(30,-10,true); //20 before
  GG(10,0.0175,0.005);
  ZZ(20,0.0175,0.005);
  slide(30,10,true); //20 before
  smolIntake();
  GG(20,0.0175,0.005);
  smolStop();
  //last goal
  moving(5,1100,3,1); */

}

void boardRight(){
  moving(5,500,3,1);
  moving(1,900,1,2);
  moving(5,500,3,5);
  TurnPR(120, 0.450);
  moving(1,950,1,2);
  moving(5,350,1,1);

  moving(5,1000,3,1);
  moving(5,500,3,4);
  moving(5,1200,2,1);

  moving(1,200,1,1);
  moving(3,400,1,2);

  /*Rollers(500);
  moving(1,1000,1,2);

  turnPD(20); 
  SlideRight1(950);
  slide(30,-100,true); //20 before

  smolIntake();
  GG(260,0.0175,0.005);
  smolStop();

  turnPD(76);

  GG(180,0.0175,0.005);

  moving(5,1100,3,3);

  largeIntake();
  moving(3,1000,1,2);
  largeStop();

  slide(25,-90,true);

  largeIntake();
  GG(100,0.0175,0.005);
  largeStop();

  turnPD(270);
  GG(150,0.0175,0.005);
  turnPD(45);
  GG(90,0.0175,0.005);

  moving(5,1500,3,3);

  */



  





  //while(DistanceLeft.objectDistance(vex::distanceUnits::cm) < 40) {
    //moving(1,10,1,20);
  //}
  //while(DistanceLeft.objectDistance(vex::distanceUnits::cm) < 100) {
    //moving(1,10,1,2);
  //}
  //turnPD(90);
  //moving(1,2000,1,2);
  ///while(RangeLeft.distance(vex::distanceUnits::cm) < 76){
   //SlideLeft();
  //}
  //moving(5,2000)
  //moving(1,1000,3,5);
  //moving(5,2000,3,1);
  //GG(150,0.02,0.005);
  //turnPD(84); //Should turn 90
  //checkAndStopRollers(Optical1.color());
  //if(Optical1.color() == vex::color::blue){
    //stopRollers();
  //}
  //GG(150,0.02,0.005);
  /*while(RangeLeft.distance(vex::distanceUnits::cm) < 76){
    SlideRight();
  }*/
  /*while(DistanceLeft.objectDistance(vex::distanceUnits::cm) < 30) {
    MoveF();

  }*/

  
}


void sitRight() {
  moving(5,500,3,1);
  moving(1,900,1,2);
  moving(5,500,3,5);
  TurnPR(120, 0.450);
  moving(1,1000,1,2);
  moving(5,200,1,1);
  moving(5,1000,3,1);
  moving(5,600,3,4);
  moving(5,1200,2,1);

  moving(1,200,1,1);
  moving(3,400,1,2);
}

void sitLeft(){
  moving(5,500,3,1);
  moving(1,800,1,2);
  moving(5,500,3,5);
  TurnPL(120, 0.450);
  moving(1,1000,1,2);
  moving(5,200,1,1);
  moving(5,1000,3,1);
  moving(5,300,3,4);
  moving(5,1000,2,1);

  moving(1,200,1,1);
  moving(3,400,1,2);
  //moving(2,1000,3,5);


  //moving(5,500,3,5);
  //moving(1,1500,1,5);
  //largeIntake();
  //GG(700,0.0105,0.005);
  //largeStop();
  
  //moving(5,1000,3,1);


}

void skillsAutoDiscore() {
   
  moving(5,800,1,1);

  moving(1,2500,1,2);

  TurnPL(300, 0.201); 
  moving(5, 500,3,1);
  GG(1100,0.0105,0.005);
  TurnPR(150,0.150);
  //GG(600,0.0105,0.009);
  moving(1,530,3,5);
  TurnPL(500, 0.150);
  task::sleep(300);
  moving(1,1000,2,5);
  moving(3,800,2,5);
  moving(1,800,2,5);
  moving(3,800,2,5);
  moving(1,800,2,5);
  moving(3,800,2,5);
  moving(1,800,2,5);
  moving(3,800,2,5);
  
  moving(3,2000,2,5);
  GG(2500,0.0105,0.005);
  TurnPR(175, 0.150);
  moving(1,2500,2,5);

  moving(5,4000,1,2);

  moving(3,2000,1,2);

  //POOP(3000);
}

void sitLeftCenterGoalBeta() {
  moving(5,500,3,1);
  moving(1,850,1,2);
  moving(5,500,3,5);
  TurnPL(120, 0.450);
  moving(1,900,1,2); //3,2 //1000
  moving(5,200,3,1);//1,1
  moving(5,1000,3,1);
  moving(5,300,3,4);
  //moving(5,1000,2,1);

  moving(1,300,1,1); //1,200,1,1;
  moving(3,825,1,5); //3,400,1,2;


  //Remove blue ball
  //moving(3,500,2,5);
  
  //New routine
  TurnPR(820, 0.450); //need to be fixed
  moving(5,400,3,5);
  moving(5,300,1,1);
  forwardPD(2200);
  //TurnPL(100, 0.450);
  moving(5,2000,3,1);
  moving(3,1000,3,5);
  /*moving(3,1000,1,2);
  TurnPR(60, 0.450);
  moving(1,1000,1,2);
  moving(5,2000,3,1);
  moving(3,1000,2,5);*/

}

void sitLeftBetaHomeRow() {
  moving(5,500,3,1);
  moving(1,800,1,2);
  moving(5,500,3,5);
  TurnPL(120, 0.450);
  moving(1,1000,1,2);
  moving(5,200,1,1);
  moving(5,1000,3,1);
  moving(5,300,3,4);
  moving(5,1000,2,1); //1000

  moving(1,200,1,1);
  moving(3,1000,1,6); //used to be 400 before change

  TurnPL(600, 0.450); 

  moving(5,400,3,5);

  //Back to the wall for line up
  moving(3,1600,3,5);//1200 //2
  
  moving(5,400,3,5);
  //Forward
  //POOP2();
  GG(2700,0.0175,0.005); //2700
  //forwardPD(6300);//6300 
  //Poopstop ();

  moving(5,400,3,5);
  TurnPR(180, 0.450); //180
  moving(5,400,3,5);
  moving(1,1200,1,1); //1200
  moving(5,300,1,1);
  moving(5,700,3,1); //600 //500 before //800
  moving(5,300,3,4);
  moving(5,500,3,3);
  moving(5,500,3,4); //not existing before
  moving(5,200,1,2); //not existing before
  //moving(1,100,1,2); //150
  //moving(5,800,3,1);
  moving(3,1000,1,5);

}

void sitRightCenterGoalBeta1() {
  moving(5,500,3,1);
  moving(1,900,1,2);
  moving(5,500,3,5);
  TurnPR(120, 0.450);
  moving(1,1000,1,2);
  moving(5,200,1,1);
  moving(5,500,3,1); //5,1000,3,1 before change
  moving(5,600,3,4); 

  moving(5,600,2,5);

  moving(1,200,1,5); //1,200,1,1
  moving(3,700,1,5); //3,700,1,2
  

  //New routine
  TurnPR(500, 0.450);
  moving(3,1000,3,5);

  while(RangeBack.distance(vex::distanceUnits::cm) < 100){
    //Shift left
  }
  //moving(1,1000,1,2);
  //moving(5,3000,1,6);

  
}

void LeftCenterNew1() {
  moving(5,500,3,1);
  moving(1,850,1,2);
  moving(5,500,3,5);
  TurnPL(120, 0.450);
  moving(1,900,1,2); //3,2 //1000
  moving(5,200,3,1);//1,1
  moving(5,1000,3,1);
  moving(5,300,3,4);
  //moving(5,1000,2,1);

  moving(1,300,1,1); //1,200,1,1;
  
  moving(3,1000,1,6); //used to be 400 before change

  TurnPL(600, 0.450); 

  moving(5,400,3,5);

  //Back to the wall for line up
  moving(3,1600,3,5);//1200 //2
  
  moving(5,400,3,5);
  //Forward
  GG(1800,0.0175,0.005); //2700
  //forwardPD(6300);//6300 
  TurnPR(120, 0.450);

  moving(5,2000,3,1);
  moving(3,1000,3,5);
  
}