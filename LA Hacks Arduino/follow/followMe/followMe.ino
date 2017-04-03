#include <Servo.h> 
#define BAUD 9600

Servo leftArma, leftArmb, rightArma, rightArmb;
int state;
int ctr = 0;
int input[] = {0, 1, 1, 2, 2, 3, 4};

void setup() 
{ 
  Serial.begin(BAUD);
  leftArma.attach(9);
  leftArmb.attach(8);
  rightArma.attach(6);
  rightArmb.attach(7);
} 

void loop() 
{ 
/*
  state = input[ctr];
  ctr++;
  if(ctr > sizeof(input)){
    ctr = 0; 
  }
*/
  String input;
  //If any input is detected in arduino
  if(Serial.available() > 0){
  input = Serial.readStringUntil('\n');}
  Serial.println(input);
  state = input.toInt();
  if(input == "0"){
    rightArma.writeMicroseconds(1500);
    rightArmb.writeMicroseconds(2100); // clockwise
    leftArma.writeMicroseconds(1500);
    leftArmb.writeMicroseconds(900); // clockwise
  }else if(input == "1"){
    rightArma.writeMicroseconds(1500);
    rightArmb.writeMicroseconds(900); // clockwise
    leftArma.writeMicroseconds(1500);
    leftArmb.writeMicroseconds(900); // clockwise
  }else if(input == "2"){
    rightArma.writeMicroseconds(1200);
    rightArmb.writeMicroseconds(1500); // clockwise
    leftArma.writeMicroseconds(1200);
    leftArmb.writeMicroseconds(900); // clockwise
   }else if(input == "3"){
    rightArma.writeMicroseconds(1500);
    rightArmb.writeMicroseconds(2100); // clockwise
    leftArma.writeMicroseconds(1500);
    leftArmb.writeMicroseconds(2100); // clockwise
   }
   delay(100);
}   
