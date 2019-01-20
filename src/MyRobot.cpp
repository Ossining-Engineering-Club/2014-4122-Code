#include "WPILib.h"
#include "MotorTest.h"
#include "PickupArms.h"
#include "Pneumatics.h"
#include "Constants.h"
#include "TankDriveThrottle.h"
#include "AnalogUltrasonic.h"
#include "LaserRanger.h"
#include "constants.h"
#include "ArmMotors.h"
#include <math.h>
class RobotDemo : public SimpleRobot
{
	Joystick rightstick;
	Joystick leftstick;
	TankDriveThrottle tankdrive;
	ArmMotors pickupsystem;
	Pneumatics pneumatics;
	Encoder leftEncoder;
	AnalogUltrasonic ultra;
	MotorTest pickupspin;
	Timer autoTimer;
	LaserRanger laser;
	
	char* compressorState;
	char* driveMode;
	char* gearMode;
	char* pickUpState;
			
	
public:
	RobotDemo():
		rightstick(1),	
		leftstick(2),
		tankdrive(1,2,3,4),   		//PWMs 1-4  
		pickupsystem(6),			//Solenoid 3
		pneumatics(1,1,1,2,3),		//
		leftEncoder(2, 3, false, Encoder::k4X),	// Set Encoder Digital Outputs, Direction, Encoder Type
		ultra(1),
		pickupspin(7),
		laser()
		
	{
		leftEncoder.SetDistancePerPulse(ENCODER_DIST_PER_PULSE);
		leftEncoder.Start();
	}

	void Autonomous()
	{
		laser.ResetPort();
		compressorState ="Compressor OFF";
		gearMode = "LOW Gear";
		
		DriverStationLCD*Lcd1=DriverStationLCD::GetInstance();
		Lcd1->Clear();
		Lcd1->PrintfLine(DriverStationLCD::kUser_Line1, CODEVERSION);
		Lcd1->PrintfLine(DriverStationLCD::kUser_Line2, "AUTONOMOUS MODE");
		Lcd1->UpdateLCD();
		autoTimer.Reset();			// Reset timer first so time starts at zero
		autoTimer.Start();
		tankdrive.Throttle(-1.0);	// Sets Throttle to Full Speed, since control goes 1 to -1
		tankdrive.Drive(AUTO_FORWARD_SPEED,AUTO_FORWARD_SPEED);
		// pickupsystem.ArmDown();
		// start timer
		// while timer<fwdtime && dist<stopdist
		while(autoTimer.Get()<MAX_FORWARD_TIME && laser.GetRangeFeet()>AUTO_SHOOT_DIST)
		{
			Wait(0.1);		//Wait for Laser Range to be be generated every 0.1 sec
		}
		tankdrive.Drive(0.0,0.0);
		Wait(AUTO_SHOOT_WAIT_TIME);
		pneumatics.Shoot();
		Wait(AUTO_RETRACT_TIME);
		pneumatics.RetractShooter();
		//go
		//shoot
		//wait.5 
		//retract
					
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		compressorState = "Compressor OFF";
		gearMode = "LOW Gear";
		pickUpState="Spinners OFF";
		DriverStationLCD*Lcd1=DriverStationLCD::GetInstance();
		Lcd1->Clear();
		Lcd1->PrintfLine(DriverStationLCD::kUser_Line1, CODEVERSION);			
		Lcd1->UpdateLCD();
		while (IsOperatorControl())
		{
			for(int i=0; i<10; i++)
			{
	
// Drive Code
				tankdrive.Drive(rightstick.GetY(), leftstick.GetY());
// Change to High or Low Gear
				if (rightstick.GetRawButton(2))
					{ pneumatics.ShiftGear(false); gearMode = "LOW Gear"; }	
				else if (rightstick.GetRawButton(3))
					{ pneumatics.ShiftGear(true); gearMode = "HIGH Gear"; }

// Manager Shooter: Shoot or Retract Shooter				
				if(rightstick.GetRawButton(1) && leftstick.GetRawButton(1)) pneumatics.Shoot();
				if(rightstick.GetRawButton(4)) pneumatics.RetractShooter();
					
// Manage Pickup Spinner			
				if(leftstick.GetRawButton(5))
					{pickupspin.SetSpeed(SPIN_SPEED); 
					pickupspin.SetOn(true); pickUpState="Spinners FWD"; }
				else if (leftstick.GetRawButton(4))
					{pickupspin.SetSpeed(-SPIN_SPEED); 
					pickupspin.SetOn(true); pickUpState="Spinners Reverse"; }
				else pickupspin.SetOn(false);

// Manage Pickup Arms
				if(leftstick.GetRawButton(2))  
					pickupsystem.ArmDown();
				else if (leftstick.GetRawButton(3)) 
					pickupsystem.ArmUp();
				else
					pickupsystem.ArmStop();
											
				pickupsystem.ArmSpeed(leftstick.GetThrottle());
				pneumatics.CompressHandle();
				if(rightstick.GetRawButton(5))
				{	
					pneumatics.AllowCompress(true);
					if(pneumatics.GetCompState()) compressorState ="Compressor ON";
					else compressorState ="Compresser OFF";
				}
				else pneumatics.AllowCompress(false);
				
				Wait(0.01);				// wait for a motor update time
			}
			tankdrive.Throttle(rightstick.GetThrottle());
				
			Lcd1->Clear();
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line1, CODEVERSION);
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line2, "%s", compressorState);
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line3, "%s, %s", gearMode, pickUpState);
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line4, "Encoder: %f" ,leftEncoder.GetDistance());
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line5, "US Range: %f" ,ultra.GetAveragedFeet());
			Lcd1->PrintfLine(DriverStationLCD::kUser_Line6, "Laser Range: %f" ,laser.GetRangeFeet());			
			Lcd1->UpdateLCD();
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

