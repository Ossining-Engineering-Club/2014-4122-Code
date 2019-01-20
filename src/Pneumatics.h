/* Control Pneumatics
 * 
 */
#ifndef Pneumatics_H_	//Checks to see whether this header is defined
#define Pneumatics_H_	//Defines header file
#include "WPILib.h"	//Includes WPI Library for Joysticks, Jaguars

class Pneumatics	//Declaring class
{
	public:	//Stuff in here can be accessed from other classes
		Pneumatics(UINT32 compressChan, UINT32 compressSwitchChan,UINT32 gearChan, UINT32 shootChan1, UINT32 shootChan2);//Constructor takes pwm channel
		void AllowCompress(bool);		//call to switch compressor on or off
		void ShiftGear(bool);			//ShiftGear is set to false for Low Gear, true for High Gear
		void CompressHandle();			//call this very often
		void Shoot();
		void RetractShooter();
		bool GetCompState();
	private:	//Stuff accessible only to this class
		void allowCompressHandle();
		Solenoid gearShift;
		Relay compressSpike;
		DigitalInput compressIn;
		Solenoid shoot1;
		Solenoid shoot2;
		bool compressButtonUp;
		bool allowCompress;
		float speed;
		bool compressOn;
		bool gear;
};
#endif//ends header file definition
