#include "Pneumatics.h"	//Includes header file where all methods are declared
#include "WPILib.h"	//includes WPI library for jaguars
//constructor method, sets jaguar channels
Pneumatics::Pneumatics(UINT32 compressChan, UINT32 compressSwitchChan,UINT32 gearChan, UINT32 shootChan1, UINT32 shootChan2):
gearShift(gearChan),	
compressSpike(compressChan),
compressIn(compressSwitchChan),
shoot1(shootChan1),
shoot2(shootChan2)
	
	{
		gear=false;					
		gearShift.Set(false);
		allowCompress=false;
		compressButtonUp=true;    
		compressOn=false;
	}

void Pneumatics::ShiftGear(bool gearPos)//shifts gear to true or false (solenoid)
{
	gearShift.Set(gearPos);
}
void Pneumatics::AllowCompress(bool isPressed)
{
	compressOn=isPressed;
	//allowCompress=isPressed;
}
bool Pneumatics::GetCompState()
{
	return allowCompress;	//Changed in v1.2
}
void Pneumatics::CompressHandle()//turns compressor on or off
{
	if(allowCompress)
	{
		if(!compressIn.Get()) 
			compressSpike.Set(Relay::kOn);
		else
			compressSpike.Set(Relay::kOff);
	}
	else
	{
		compressSpike.Set(Relay::kOff);
	}
	allowCompressHandle();
}
void Pneumatics::allowCompressHandle()//handles the switching of the compressor on or off from the implementing class
{
	if(compressButtonUp&&compressOn)
	{
		if(!allowCompress)allowCompress=true;
		else allowCompress=false;
		compressButtonUp=false;
	}
	else if(!compressOn) compressButtonUp=true;
}
void Pneumatics::Shoot()
{
	shoot1.Set(true);
	shoot2.Set(true);
}
void Pneumatics::RetractShooter()
{
	shoot1.Set(false);
	shoot2.Set(false);
}
