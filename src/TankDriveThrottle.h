/*
 * A very basic tank drive class for FRC robots
 */
#ifndef TankDriveThrottle_H_	//Checks to see whether this header is defined
#define TankDriveThrottle_H_	//Defines header file
#include "WPILib.h"				//Includes WPI Library for Joysticks, Jaguars

class TankDriveThrottle			//Declaring class
{
	public:						//Stuff in here can be accessed from other classes
		TankDriveThrottle(UINT32,UINT32,UINT32,UINT32);//Constructor (takes 2 right and 2 left Jaguar channels)
		void Drive(float rightstick, float leftstick); 	//Driving (takes right, and left motor commands
		//both arguments should be between -1 and 1 (feed joystick y axes)
		void Throttle(float);//Controls joystick sensitivity/topspeed
		//takes throttle axis -1 to 1, use this or the robot won't move
		//throttle default is 0
		void Reverse(bool);   // When called with bool=1, controls are reversed
	private:				//Stuff accessible only to this class
		Talon right1;		//the right side Jaguar
		Talon right2;
		Talon left1;			//the left side Jaguar
		Talon left2;
		bool inverted;		//Set for driving Robot with reversed controls
		float conthrottle;	//a floating variable for the converted throttle
};
#endif//ends header file definition
