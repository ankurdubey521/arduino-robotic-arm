#include "roboticArm.h"

#define pi 3.14159265

roboticArm prototypeArm(2,3,4,5,10,10,10);

void setup(){
}
void loop(){
  for(int i=0;i<180;++i){
    prototypeArm.setServoAngle(i,i,i);
    delay(1000);
  }
}

