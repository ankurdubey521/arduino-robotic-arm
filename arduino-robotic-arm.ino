#include "roboticArm.h"

#define pi 3.14159265

roboticArm prototypeArm(2,3,4,5,0.015,0.15,0.15);

void setup(){
}
void loop(){
    for(float i=0;i<3.14;i=i+pi/6){
    prototypeArm.setServoAngle(i,i,i);
    delay(100);
  }
}

