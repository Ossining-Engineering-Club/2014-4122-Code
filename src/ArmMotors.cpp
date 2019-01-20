#include "ArmMotors.h"	//Includes header file where all methods are declared
#include "WPILib.h"	//includes WPI library for jaguars
#include "constants.h"
//constructor method, sets jaguar channels
ArmMotors::ArmMotors(UINT32 armchannel):
	arm(armchannel)
	{
	speed=0;//sets converted throttle to 0 (so robot won't move accidentally)
	}
//This method drives the robot (sets motor speeds to values given, multiplied by throttle value]
//Takes two inputs -1 to 1 (Hint: just send it the joystick y axis values)

void ArmMotors::ArmUp()
{
	arm.Set(speed);
}

void ArmMotors::ArmDown()
{
	arm.Set(-speed);
}

void ArmMotors::ArmStop()
{
	arm.Set(0);//arm stop
}

void ArmMotors::ArmSpeed(float throttle)
{
	speed = -(throttle-1)/2;
}
