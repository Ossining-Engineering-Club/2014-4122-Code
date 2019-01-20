#include "TankDriveThrottle.h"	//Includes header file where all methods are declared
#include "WPILib.h"	//includes WPI library for jaguars
#include "Constants.h"
#include <math.h>
//constructor method, sets jaguar channels
TankDriveThrottle::TankDriveThrottle(UINT32 rightchannel1, UINT32 rightchannel2, UINT32 leftchannel1, UINT32 leftchannel2):
	right1(rightchannel1),
	right2(rightchannel2),
	left1(leftchannel1),
	left2(leftchannel2)
	{
		inverted=false;
		conthrottle=0;		//sets converted throttle to 0 (so robot won't move accidentally)
	}
//This method drives the robot (sets motor speeds to values given, multiplied by throttle value]
//Takes two inputs -1 to 1 (Hint: just send it the joystick y axis values)
void TankDriveThrottle::Drive(float rightstick, float leftstick)
{
	if(leftstick>1.0) leftstick=1.0;
	else if(leftstick<-1.0) leftstick=-1.0;
	if(rightstick>1.0) rightstick=1.0;
	else if(rightstick<-1.0) rightstick=1.0;
	
	if(fabs(leftstick)<JOYSTICK_DEAD_ZONE)leftstick=0.0;
	if(fabs(rightstick)<JOYSTICK_DEAD_ZONE)rightstick=0.0;
	
	if(!inverted)
	{
		// multiply by converted throttle to limit speed
		left1.Set(leftstick*conthrottle); 		//left motor is set to the parameter specified
		left2.Set(leftstick*conthrottle); 		//left motor is set to the parameter specified
		right1.Set(-1.0 * rightstick*conthrottle);	//Right motor is set to parameter specified 
		right2.Set(-1.0 * rightstick*conthrottle);	//Right motor is set to parameter specified 
	}
	else
	{
		left1.Set(-1.0 * leftstick*conthrottle); 		//left motor is set to the parameter specified
		left2.Set(-1.0 * leftstick*conthrottle); 		//left motor is set to the parameter specified
		right1.Set(rightstick*conthrottle);	//Right motor is set to parameter specified 
		right2.Set(rightstick*conthrottle);	//Right motor is set to parameter specified 
	}
}
//this method is the throttle method (sets the max speed/control sensitivity
//you must call this method with a parameter less than 1 for the robot to move
void TankDriveThrottle::Throttle(float othrottle)
{
	conthrottle=(1.0 - othrottle)/2.0; //converts throttle from a value between -1 and 1 to a value between 0 and 1
}
void TankDriveThrottle::Reverse(bool reverse)
{
	inverted=reverse;		
}
