/*A very basic tank drive class for FRC robots
 * 
 * 
 */
#ifndef ArmMotors_H_	//Checks to see whether this header is defined
#define ArmMotors_H_	//Defines header file
#include "WPILib.h"	//Includes WPI Library for Joysticks, Jaguars
class ArmMotors	//Declaring class
{
	public:	//Stuff in here can be accessed from other classes
		ArmMotors(UINT32 armchannel);//Constructor takes pwm channel
		void ArmUp();
		void ArmDown();
		void ArmStop();
		void ArmSpeed(float);
		typedef enum {kickFwd, kickRev, kickStop} KickState;
	private:	//Stuff accessible only to this class
		Jaguar arm;
		float speed;
		KickState kickstate;
		double sysTime;
		Timer timer;
};
#endif//ends header file definition
