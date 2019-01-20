/*
 * ArmMotor Class for controlling Pickup Arms
 */
#ifndef PickupArms_H_	//Checks to see whether this header is defined
#define PickupArms_H_	//Defines header file
#include "WPILib.h"		//Includes WPI Library for Joysticks, Jaguars
class PickupArms		//Declaring class
{
	public:	//Stuff in here can be accessed from other classes
		PickupArms(UINT32 armchannel);	//Constructor takes pwm channel
		void ArmUp();
		void ArmDown();
	private:	//Stuff accessible only to this class
		Solenoid arm;

};
#endif//ends header file definition
