//Forward motion
#include <Servo.h>
Servo Servo1, Servo2, Servo3,Servo4; // create servo object to control a servo
 int i, time ;
int pos1, pos2, pos3,pos4;
int pos1R, pos2R, pos3R,pos4R;
int phase=100;
int velocity=2000;
int maxDeflexion=25;
const int center1=90;
const int center2=90;
const int center3=90;
const int center4=90;//check
void setup()
{
Servo1.attach(2);
Servo2.attach(3);
Servo3.attach(4);
Servo4.attach(5);
}
 void loop()
{
 time=velocity/800;
for (i=0; i<360; i++) {
 pos1 = i+3*phase;
pos2 = i+2*phase;
pos3 = i+1*phase;
pos4 = i;
 if (pos1>359) pos1-=360;
if (pos2>359) pos2-=360;
if (pos3>359) pos3-=360;
if (pos4>359) pos4-=360;
 if (pos1>179) pos1=360-pos1;
if (pos2>179) pos2=360-pos2;
if (pos3>179) pos3=360-pos3;
if (pos4>179) pos4=360-pos4;
pos1R=map(pos1,0,180,center1-maxDeflexion,center1+maxDeflexion);
pos2R=map(pos2,0,180,center2-maxDeflexion,center2+maxDeflexion);
pos3R=map(pos3,0,180,center3-maxDeflexion,center3+maxDeflexion);
pos4R=map(pos4,0,180,center4-maxDeflexion,center4+maxDeflexion);
 Servo1.write(pos1R);
Servo2.write(pos2R);
Servo3.write(pos3R);
Servo4.write(pos4R);
delay(time);
}
}
