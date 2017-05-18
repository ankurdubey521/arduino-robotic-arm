/*
*	roboticArm.h - Library for controlling robotic arm
*	Created by Ankur Dubey, 18 May, 2017
*/

#include "Arduino.h"
#include <math.h>
#include "roboticArm.h"
#include <Servo.h>

roboticArm::roboticArm(	int phiServoPin,
					int firstServoPin,
					int secServoPin,
					int electroMagnetPin,
					float length1,
					float length2,
					float length3){
	
	_phiServoPin=phiServoPin;
	_phiServo.attach(_phiServoPin);
	_firstServoPin=firstServoPin;
	_firstServo.attach(_firstServoPin);
	_secServoPin=secServoPin;
	_secServo.attach(_secServoPin);
	
	_electroMagnetPin=electroMagnetPin;
	
	_length1=length1;
	_length2=length2;
	_length3=length3;
	
}
void roboticArm::setArmPosn(double r,double theta,double phi){
	double secAngle=acos(
							(	_length2*_length2
								+ _length3*_length3
								- _length1*_length1 
								- r*r
								+ 2*r*_length1*cos(theta)
							)
							/
							(2*_length2*_length3)
						);
	double firstAngle=asin(
							(	_length3*_length3
								+ r*r
								- _length1*_length1
								- _length2*_length2
							)
							/
							(	2
								* sqrt(		_length1*_length1*_length2*_length2
											+ r*r*_length3*_length3
											- 2*r*_length1*_length2*_length3*cos(theta+secAngle)												
									   )
							)
						  )
						  +
					asin(
							(	r*_length3*sin(theta+secAngle)
							)
							/
							(	sqrt(		
										_length1*_length1*_length2*_length2
										+ r*r*_length3*_length3
										- 2*r*_length1*_length2*_length3*cos(theta+secAngle)												
									)
							)
						);
	_firstServo.write(firstAngle);
	_secServo.write(secAngle);	
	_phiServo.write(phi);
}
void roboticArm::setElectoMagnetState(bool state){
	digital.write(_electroMagnetPin,state);
}