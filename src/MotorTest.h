/*
  * Class for testing with a new Motor
 */
#ifndef MotorTest_H_	//Checks to see whether this header is defined
#define MotorTest_H_	//Defines header file
#include "WPILib.h"		//Includes WPI Library for Joysticks, Jaguars

class MotorTest			//Declaring class
{
	public:					//Stuff in here can be accessed from other classes
		MotorTest(UINT32);	//Constructor takes pwm channel
		void SetSpeed(float); //method for setting speed, must call this at least once in order to run
		void SetOn(bool);//Allow motor to turn if true is sent, must call this in order to run
	private:	//Stuff accessible only to this class
		Jaguar motor;
		float speed;
		bool on;
};
#endif//ends header file definition
