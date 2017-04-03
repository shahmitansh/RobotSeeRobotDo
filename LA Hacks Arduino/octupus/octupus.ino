/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
#include <Servo.h> 
#define  SIZE_ARRAY1 4
#define  SIZE_ARRAY2 4
Servo c;  // create servo object to control a servo 

String write_positions={"80,90,180,70};
Servo servos[SIZE_ARRAY2];

int start=0;
int value;
char input[6];

void setup() 
{ 
  Serial.begin(9600);
  for(int i=0 , i<4 , i++)
  {
  servos.attach(i+6);
  }
} 

void loop() 
{ 
  String rawInput = "090090";// input array
  
/*  //left shoulder
  temp = rawInput.substring(2,3);
  value = getDegree(temp.toInt());
  Serial.println(temp.toInt());
  leftArma.write(temp.toInt());
  delay(50);
  
  temp = rawInput.substring(3, 5);
  value = getDegree(temp.toInt());
  Serial.println(temp.toInt());
  leftArmb.write(temp.toInt()); // clockwise
 /*
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
  delay(100);
}

int getDegree(int stuff){
  return stuff;
  }
