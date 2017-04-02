#include <Servo.h> 
#define BAUD 9600

Servo leftArma, leftArmb, leftArmc, rightArma, rightArmb, rightArmc;
//int input[] = {0, 1, 1, 2, 2, 3, 4};

String MODE = "MONKEY_PARTY";

void setup() 
{
  Serial.begin(BAUD);
  if (MODE == "MONKEY_SEE")
  {
    leftArmc.attach(10);
    rightArmc.attach(5);
  }
  else if (MODE == "MONKEY_D0" || MODE == "MONKEY_PARTY")
  {
    leftArmb.attach(8);
    leftArma.attach(9);
    leftArmc.attach(10);
    rightArma.attach(7);    
    rightArmb.attach(6);
    rightArmc.attach(5);
  }
}

void loop() 
{ 
  if (MODE == "MONKEY_SEE")
  {
    String input;
  //If any input is detected in arduino
  if(Serial.available() > 0){
    input = Serial.readStringUntil('\n');
    delay(250);
  }

  String pos = input.substring(0,2);
  String joint = input.substring(0,5);

  if (pos.equals("LS"))
  {
      leftArma.attach(9);
      if(joint.equals("LS030"))
      {
        leftArma.write(30);
        delay(250);
        leftArma.detach();
      }
      if(joint.equals("LS060"))
      {
        leftArma.write(60);
        delay(250);
        leftArma.detach();
      }
      if(joint.equals("LS090"))
      {
        leftArma.write(90);
        delay(250);
        leftArma.detach();
      }
      if(joint.equals("LS120"))
      {
        leftArma.write(120);
        delay(250);
        leftArma.detach();
      }
      if(joint.equals("LS150"))
      {
        leftArma.write(150);
        delay(250);
        leftArma.detach();
      }
  }
    else if (pos.equals("RS"))
  {
      rightArma.attach(6);
      if(joint.equals("RS150"))
      {
        rightArma.write(30);
        delay(250);
        rightArma.detach();
      }
      if(joint.equals("RS120"))
      {
        rightArma.write(60);
        delay(250);
        rightArma.detach();
      }
      if(joint.equals("RS090"))
      {
        rightArma.write(90);
        delay(250);
        rightArma.detach();
      }
      if(joint.equals("RS060"))
      {
        rightArma.write(120);
        delay(250);
        rightArma.detach();
      }
      if(joint.equals("RS030"))
      {
        rightArma.write(150);
        delay(250);
        rightArma.detach();
      }
  }
  else if (pos.equals("LE"))
  {
      leftArmb.attach(8);
      if(joint.equals("LE030"))
      {
        leftArmb.write(30);
        delay(250);
        leftArmb.detach();
      }
      if(joint.equals("LE090"))
      {
        leftArmb.write(90);
        delay(250);
        leftArmb.detach();
      }
      if(joint.equals("LE150"))
      {
        leftArmb.write(150);
        delay(250);
        leftArmb.detach();
      }
  }
  else if (pos.equals("RE"))
  {
      rightArmb.attach(7);
      if(joint.equals("RE030"))
      {
        rightArmb.write(150);
        delay(250);
        rightArmb.detach();
      }
      if(joint.equals("RE090"))
      {
        rightArmb.write(90);
        delay(250);
        rightArmb.detach();
      }
      if(joint.equals("RE150"))
      {
        rightArmb.write(30);
        delay(250);
        rightArmb.detach();
      }
    }
  }
  else if (MODE == "MONKEY_DO")
  {
    String input;
    //If any input is detected in arduino
    if(Serial.available() > 0){
      input = Serial.readStringUntil('\n');
    }
    delay(100);
    if(input == "0")
    {
      leftArmc.write(90);
      rightArmc.write(90);
      rightArma.write(90);
      rightArmb.write(150); // clockwise
      leftArma.write(90);
      leftArmb.write(30); // clockwise
      //Serial.print(leftArma.read());
      delay(250);
     }
     else if(input == "1")
     {
       leftArmc.write(90);
       rightArmc.write(90);
       rightArma.write(120);
       rightArmb.write(45); // clockwise
       leftArma.write(145);
       leftArmb.write(90);
       delay(250);
     }
     else if(input == "2")
     {
       leftArmc.write(90);
       rightArmc.write(90);    
       rightArma.write(120);
       rightArmb.write(90); // clockwise
       leftArma.write(90);
       leftArmb.write(60);
       delay(250);
     }
     else if(input == "3")
     {
       leftArmc.write(90);
       rightArmc.write(90);
       rightArma.write(60);
       rightArmb.write(90); // clockwise
       leftArma.write(130);
       leftArmb.write(45); // clockwise
       delay(250);
     }
     else
     {}
    delay(100); 
  }
  else if (MODE == "MONKEY_PARTY")
  {
    String input;
    //If any input is detected in arduino
    if(Serial.available() > 0){
      input = Serial.readStringUntil('\n');
    }
    int danceNum = input.toInt();
    switch (danceNum)
    {
      case 1:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(90);
        rightArmb.write(120); // clockwise
        leftArma.write(90);
        leftArmb.write(30); // clockwise
        break;
      case 2:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(90);
        rightArmb.write(30); // clockwise
        leftArma.write(90);
        leftArmb.write(120); // clockwise
        break;
      case 3:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(60);
        rightArmb.write(90); // clockwise
        leftArma.write(130);
        leftArmb.write(45); // clockwise
        break;
      case 4:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(150);
        rightArmb.write(90); // clockwise
        leftArma.write(90);
        leftArmb.write(150); // clockwise
        break;
      case 5:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(30);
        rightArmb.write(90); // clockwise
        leftArma.write(90);
        leftArmb.write(0); // clockwise
        break;
      case 6:
        leftArmc.write(90);
        rightArmc.write(90);
        rightArma.write(135);
        rightArmb.write(120); // clockwise
        leftArma.write(120);
        leftArmb.write(90); // clockwise
        break;
      default:
        return;
    }
    delay(1500);
  }
}
