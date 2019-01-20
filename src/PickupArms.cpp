#include "PickupArms.h"	//Includes header file where all methods are declared
#include "WPILib.h"		//includes WPI library for jaguars
#include "Constants.h"
//constructor method, sets solenoid channel
PickupArms::PickupArms(UINT32 armchannel):
	arm(armchannel)
	{

	}
//This method drives the robot (sets motor speeds to values given, multiplied by throttle value]
//Takes two inputs -1 to 1 (Hint: just send it the joystick y axis values)

void PickupArms::ArmUp()
{
	arm.Set(false);
}

void PickupArms::ArmDown()
{
	arm.Set(true);	
}

