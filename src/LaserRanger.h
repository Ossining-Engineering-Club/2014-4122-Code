#ifndef LASERRANGER_H_
#define LASERRANGER_H_
#include "WPILib.h"
class LaserRanger
{
public:
									// Ranger is acquiring a range every 1/10 of a second. 
	LaserRanger();			
	float GetRangeFeet(void);		// Returns the Average Range in Feet, gets latest Range 
	void ResetPort();				// Call to reset the port before using

private:
	SerialPort laserport;			// 
	char buffout[8], buffin[8000];	// Specify input and output buffers
	float range;					// Holds the range in Feet
	float temprange;				// Accumulates the range
	INT32 getrange;					// Set when range is accumumating
	INT32 nrecv, i, nreadact;		// Integer counters
};
#endif
