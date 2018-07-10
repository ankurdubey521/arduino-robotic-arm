/*
*	roboticArm.h - Library for controlling robotic arm
*	Created by Ankur Dubey, 18 May, 2017
*/

#ifndef roboticArm_h
#define roboticArm_h

#include "Arduino.h"
#include <Servo.h>

class roboticArm{
	public:
		roboticArm(
			int phiServoPin,
			int firstServoPin,
			int secServoPin,
			int electroMagnetPin,
			float length1,
			float length2,
			float length3);
		void setArmPosn(double r,double theta,double phi);
    void setServoAngle(double theta1,double theta2,double theta3);
		void setElectoMagnetState(bool state);
	private:
		int _phiServoPin,_firstServoPin,_secServoPin,_electroMagnetPin;
		float _length1,_length2,_length3;
		Servo _phiServo,_firstServo,_secServo;
};

#endif
