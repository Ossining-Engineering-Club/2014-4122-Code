#include "MotorTest.h"	//Includes header file where all methods are declared
#include "WPILib.h"	//includes WPI library for jaguars
//constructor method, sets jaguar channels
MotorTest::MotorTest(UINT32 channel):
	motor(channel)
	{
	speed=0;//sets converted throttle to 0 (so robot won't move accidentally)
	on=false;
	}
//This method drives the robot (sets motor speeds to values given, multiplied by throttle value]
//Takes two inputs -1 to 1 (Hint: just send it the joystick y axis values)

void MotorTest::SetSpeed(float speedIn)
{
	speed=speedIn;
}
void MotorTest::SetOn(bool isOn)
{
	on=isOn;
	if(on)
		motor.Set(speed);
	else
		motor.Set(0);//turn motor off
}
