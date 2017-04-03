/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 28 May 20100
 by Michael C. Miller
 modified 8 Nov 2013
 by Scott Fitzgerald

 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo leftArma, leftArmb, rightArma, rightArmb;  // create servo object to control a servo 
                  // twelve servo objects can be created on most boards
int start=0;

void setup() 
{ 
  leftArma.attach(6);  // left shoulder 900-2100
  leftArmb.attach(7);  // left wrist    900-2100
  rightArma.attach(9);  // right shoulder 900-2100
  rightArmb.attach(8);  // right wrist    900-2100  
  //leftLega.attach(4);  // leg 1 // 1000-1500
  //rightLega.attach(11); // right leg 2
} 

 
void loop() 
{ 
  leftArma.writeMicroseconds(1500);
  leftArmb.writeMicroseconds(1500); // clockwise
  rightArma.writeMicroseconds(1500);
  rightArmb.writeMicroseconds(1500); // clockwise
  delay(1000);
  leftArma.writeMicroseconds(2100);
  leftArmb.writeMicroseconds(2100); // clockwise
  rightArma.writeMicroseconds(2100);
  rightArmb.writeMicroseconds(2100); // clockwise
  delay(1000);
  leftArma.writeMicroseconds(1500);
  leftArmb.writeMicroseconds(1500); // clockwise
  rightArma.writeMicroseconds(1500);
  rightArmb.writeMicroseconds(1500); // clockwise
  delay(1000);
  leftArma.writeMicroseconds(900);
  leftArmb.writeMicroseconds(900); // clockwise
  rightArma.writeMicroseconds(900);
  rightArmb.writeMicroseconds(900); // clockwise
  delay(1000);
/*
 leftLega.write(50);
 delay(500);
 leftLega.write(100);
 delay(500);
*/
}


