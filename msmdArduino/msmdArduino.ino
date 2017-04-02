#include <Servo.h> 
#define BAUD 9600

Servo leftArma, leftArmb, leftArmc, rightArma, rightArmb, rightArmc;
int state;
int ctr = 0;
int input[] = {0, 1, 1, 2, 2, 3, 4};

void setup() 
{
  Serial.begin(BAUD);
  leftArma.attach(9);
  leftArmb.attach(8);
  leftArmc.attach(10);
  rightArma.attach(6);
  rightArmb.attach(7);
  rightArmc.attach(5);
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
    input = Serial.readStringUntil('\n');
  }
  //state = input.toInt();
 if (input.equals("ON")){
      Serial.println("Led is on");
    } 
  delay(100);
  if(input == "0"){
    leftArmc.write(90);
    rightArmc.write(90);
    rightArma.write(90);
    rightArmb.write(150); // clockwise
    leftArma.write(90);
    leftArmb.write(30); // clockwise
    delay(250);
  }else if(input == "1"){
    leftArmc.write(90);
    rightArmc.write(90);
    rightArma.write(120);
    rightArmb.write(45); // clockwise
    leftArma.write(145);
    leftArmb.write(90);
    delay(250);
   }else if(input == "2"){
    leftArmc.write(90);
    rightArmc.write(90);    
    rightArma.write(120);
    rightArmb.write(90); // clockwise
    leftArma.write(90);
    leftArmb.write(60);
    delay(250);
   }
   else if(input == "3"){
    leftArmc.write(90);
    rightArmc.write(90);
    rightArma.write(60);
    rightArmb.write(90); // clockwise
    leftArma.write(130);
    leftArmb.write(45); // clockwise
    delay(250);
    }else{}
   delay(100);
}
