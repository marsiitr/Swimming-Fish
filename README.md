# Swimming-Fish
                                      SWIMMING FISH
                            (project done in srishti 2017)

Abstract :-
Our Project Swimming fish is aimed for copy the motion of a fish as natural as possible.  Similar to a fish it moves by motion of the 4 sections of the fish.  Different sections of the fish are provided with motion using servo motors instructed using an preprogrammed arduino.  Due to its natural motion it can be used for survey without noticed.

Team members :-
1.      PIYUSH BINDAL(EE 2nd year)
2.      AMAN KUMAR CHOUDHARY(EE 2nd year)
3.      GAURAV KUMAR SINGH(EE 2nd year)
4.      APURV PANDIT (ME 3rd year)
5.      Piyush Tekchandani(ME 3rd year)
6.      Raghav Mohta(ME 3rd year)
7.      Sarang Nagwanshi(ME 3rd year)
8. Prashant kumar (ME 3rd year)
 
Hardware :-
1.      Dual shaft Servo motors - 4
2.      7.4V battery – 1
3.      Arduino nano

Application :-
Swimming fish is designed to be look as natural as possible for avoid detection. Every section of fish moves in a way to provide the motion to the fish in the desired direction. It can be used as decorations because of its motion it looks real and don’t need any food only needs charging. By using a bluetooth device it can also be controlled by phones and can be used for surveys in less amount of water


Mechanical design :-
Swimming fish follows a motion of a fish hence we make 4 sections which moves in a way the body of a fish moves. All the section are connected to each other using hinges. Every section contains a dual shaft servo motor connected to hinge. 4 section of the fish is then connected to fin of the fish made of plastic sheet . Each servo moves in such a way that it applies a net force in either forward direction or in the direction we want to turn the fish.



Electrical design :-
It contains arduino which provide instruction to all the servo motors to rotate by which fish moves in desired direction. Arduino code are preinstalled in it. A battery is connected through switch to the breadboard . arduino and servo +5V and 0V pins are connected to the battery using breadboard. Control pins of servo are connected to the arduino directly.





Code :-
Forward motion
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

