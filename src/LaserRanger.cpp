#include "LaserRanger.h"
#include "WPILib.h"

LaserRanger::LaserRanger():
	laserport(19200,8,SerialPort::kParity_None,SerialPort::kStopBits_One)
{
	laserport.SetFlowControl(SerialPort::kFlowControl_None);
	laserport.SetWriteBufferMode(SerialPort::kFlushOnAccess);
	laserport.SetTimeout(1);
	laserport.Reset();

	range=0;
}
// Method to Acquire Range in Feet
float LaserRanger::GetRangeFeet()
{
	INT32 nrecv, i;
	
	while(nrecv = laserport.GetBytesReceived())				//Process the number of bytes received 
	{
		nreadact=laserport.Read(buffin, nrecv);				//Read nrecv characters from buffin
		for(i=0; i < nreadact; i++)
		{
			if(buffin[i] == 58){temprange=0; getrange=1;} 	// Look for ":" to start Parse
			else if (getrange==1)
			{
				if (buffin[i] == 70)						// Look for an F Character to End
				{ range=temprange; getrange=0;} 				
				else if (buffin[i] == 46){}					// Skip the Period
				else if (buffin[i] >= 48 && buffin[i] <= 57)	//For Number symbols, include in range
					{temprange= 10*temprange + 0.01 * ((float) buffin[i]-48);}
				else getrange=0;								//Erroneous Code received in Parsing					
			}
		}
	}
  return (range);
}
// Method to Reset the Port, Should be called before Ranging starts
void LaserRanger::ResetPort()
{
	laserport.Reset();
}




