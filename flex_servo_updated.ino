#include <Servo.h> 

Servo Servo1;
Servo Servo2;


const int flexPin = A7; 


void setup() 
{ 
  Servo1.attach(7);
  Servo2.attach(8);
} 

void loop() 
{ 
  int flexValue;
  int servoPosition;
  int servoPosition2;
  
  flexValue = analogRead(flexPin);
  
  servoPosition = map(flexValue, 900, 800, 0, 180); //Servo1
  servoPosition2 = map(flexValue, 900, 800, 0, 180); //Servo2

  servoPosition = constrain(servoPosition, 0, 180);
  servoPosition2 = constrain(servoPosition2, 0, 180);

  Servo1.write(servoPosition);
  Servo2.write(servoPosition);

  delay(20);
} 
