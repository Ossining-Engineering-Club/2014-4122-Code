#include "AnalogUltrasonic.h"
#include "WPILib.h"
#include "Constants.h"

#define USSCALE 8.503 // US Sensor scale is 8.503 Feet per Volt

//Constructor initializes range at 0
AnalogUltrasonic::AnalogUltrasonic(UINT32 chan):
Ultra1(chan)
{
	range=0;           
}

// Returns Range in Feet
float AnalogUltrasonic :: GetFeet()
{
	return (USSCALE*Ultra1.GetVoltage());
}

//returns an averaged distance in feet (as this method is run, previous readings have less of an impact
//run this method often in order to get an accurate idea of the actual distance
float AnalogUltrasonic :: GetAveragedFeet()
{
	range=USFILTER*range+(1.0-USFILTER)*(USSCALE*Ultra1.GetVoltage());
	return (range);
}
