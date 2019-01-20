/* Class for analog input Ultrasonic Sensor
 * Takes 1 analog channel
 * Provides averaged and raw data
 * for best results with averaged data, call the method at least 10 times a second
 */


#ifndef AnalogUltrasonic_H_
#define AnalogUltrasonic_H_
#include "WPILib.h"
class AnalogUltrasonic
{
public:
	AnalogUltrasonic(UINT32 channel);	//Constructor, takes input channel
	float GetFeet();					//returns distance in feet
	float GetAveragedFeet();			//returns an averaged distance in feet

private:
	AnalogChannel Ultra1;			//the analog channel instance for the sensor
	float range;					//feet
	
};
#endif
