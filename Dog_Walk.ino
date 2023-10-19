
#include<Servo.h>

float leg_length = 15;

int del = 3;
float stepSize = 0.05;

Servo servo[4][3];
//    servo[leg#][servo number]
//               [knee = 0, F_B = 1, L_R = 2]

//Index of motors in array
int knee = 0, F_B = 1, L_R = 2;

//Index of legs in array
int BL = 0, BR = 1, FR = 2, FL = 3;

//max/min x/z values when walking
float xMin = -10.0, xMax = -2.0, zMin = 16.0, zMax = 20.0;

float pos[4][2];
//             [leg#][x, z]

//Index of X and Z coordinates in array
int xPos = 0,  zPos = 1;


//###################################### Set Up ######################################
void setup() 
{
 
  //=========================================
  //Assigns pins to servos
  //Sets leg positions to squat position
  int pin = 1;
  for(int leg = 0; leg < 4; leg++)
  {
    pos[leg][xPos] = xMax;
    pos[leg][zPos] = zMin;
    for(int motor = 0; motor < 3; motor++)
      {
        servo[leg][motor].attach(pin);
        pin++;
      }
  }
   //========================================


   //========================================
   //Moves legs to squat position
    for(int legNum = 0; legNum < 4; legNum++)
      update_leg(legNum);
   //========================================


  //=========================================
  //Stand Up
  for(float z = zMin; z <= zMax; z += stepSize)
    for (int leg = 0; leg < 4; leg++)
     {
       pos[leg][zPos] = z;
       update_leg(leg); 
       delay(del);
     }
   //=========================================

   delay(5000);
}
//####################################################################################



//*****************************Angle Calculations**************************************
//Calculates Shoulder servo angle based on foot x and z coordinates
float shoulder_ang(float x, float z)
{return 90 + to_degrees(atan(abs(x)/z)) * (x>0?1:-1) - ((180 - knee_ang(x,z))/2);}

//Calculates Knee servo angle based on foot x and z coordinates
float knee_ang(float dist, float z)
{return to_degrees(acos(1 - ((dist*dist + z*z)/(2*leg_length*leg_length))));}

//Converts radians to degrees
float to_degrees(float rads)
{return (180 * rads / PI);}
//*************************************************************************************

void loop() 
{
  walk_forward();
}

void leg_step_forward(int legNum)
{
  int ZMin, ZMax;
  //lift leg up
  if(legNum < 2) //Rear Legs extend more for balance --> servos aren't strong enough to balance otherwise
  {
    ZMin = 19;
    ZMax = 22;
  }
  else
  {
    ZMin = 16;
    ZMax = 19;
  }
  while (pos[legNum][zPos] >= ZMin)
    {
      pos[legNum][zPos]-=stepSize;
      update_leg(legNum);
      delay(del);
    }
  //move leg forward
  while (pos[legNum][xPos] <= xMax)
    {
      pos[legNum][xPos]+=stepSize;
      update_leg(legNum);
      delay(del);
    }
  //move leg back down
  while (pos[legNum][zPos] <= ZMax)
    {
      pos[legNum][zPos]+=stepSize;
      update_leg(legNum);
      delay(del);
    }
}

void walk_forward()
{  
  while (!reachedMin())
  {
    for(int legNum = 0; legNum < 4; legNum++)
    {
      pos[legNum][xPos] -= stepSize;
      update_leg(legNum);
    }
    delay(del);
  }
  delay(1000);
  
  leg_step_forward(BL);
  delay(50);
  leg_step_forward(BR);
  delay(50);
  leg_step_forward(FL);
  delay(50);
  leg_step_forward(FR);
}

bool reachedMin()
{
  return (pos[BL][xPos] <= xMin && pos[BR][xPos] <= xMin && pos[FR][xPos] <= xMin && pos[FL][xPos] <= xMin);
}

//************************Updagtes Leg Based on coordinates in pos[][]*******************
void update_leg(int legNum)
{
    servo[legNum][F_B].write(shoulder_ang(pos[legNum][xPos], pos[legNum][zPos]));
    servo[legNum][knee].write(knee_ang(pos[legNum][xPos], pos[legNum][zPos]));
}
//****************************************************************************************
