/*
*	roboticArm.h - Library for controlling robotic arm
*	Created by Ankur Dubey, 18 May, 2017
*/

#define pi 3.14159265

#include "Arduino.h"
#include <math.h>
#include "roboticArm.h"
#include <Servo.h>

double degree(double radian){
	return radian;
	//return 180*radian/pi;
}

roboticArm::roboticArm(
	int phiServoPin,
	int firstServoPin,
	int secServoPin,
	int electroMagnetPin,
	float length1,
	float length2,
	float length3){

	_phiServoPin=phiServoPin;
	_firstServoPin=firstServoPin;
	_secServoPin=secServoPin;
	_electroMagnetPin=electroMagnetPin;

	_length1=length1;
	_length2=length2;
	_length3=length3;

	_phiServo.attach(_phiServoPin);
	_firstServo.attach(_firstServoPin);
	_secServo.attach(_secServoPin);
	pinMode(_electroMagnetPin,OUTPUT);
}
void roboticArm::setArmPosn(double r,double theta,double phi){
	double secServoAngle=acos((_length2*_length2
														+ _length3*_length3
														- _length1*_length1
														- r*r
														+ 2*r*_length1*cos(theta))
														/ (2*_length2*_length3));
	double firstServoAngle=asin((_length3*_length3
															+ r*r
															- _length1*_length1
															- _length2*_length2)
															/ (2*sqrt(_length1*_length1*_length2*_length2
															+ r*r*_length3*_length3
															- 2*r*_length1*_length2*_length3*cos(theta+secServoAngle))))
												+asin((r*_length3*sin(theta+secServoAngle))
															/ (sqrt(_length1*_length1*_length2*_length2
															+ r*r*_length3*_length3
															- 2*r*_length1*_length2*_length3*cos(theta+secServoAngle))));
	_firstServo.write(degree(firstServoAngle));
	_secServo.write(degree(secServoAngle));
	_phiServo.write(degree(phi));
}
void roboticArm::setServoAngle(double theta1,double theta2,double theta3){
  _firstServo.write(degree(theta1));
  _secServo.write(degree(theta2));
  _phiServo.write(degree(theta3));
}
void roboticArm::setElectoMagnetState(bool state){
	digitalWrite(_electroMagnetPin,state);
}
