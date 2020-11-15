#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
// Watch video V1 to understand the two lines below: http://youtu.be/y8X9X10Tn1k
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

int msg[5]; 

// our servo # counter
uint8_t servonum = 0;
//define the Flex Sensor Input pins
int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A6;
//Define Variables for Flex Sensor Values 

int flexVal1;
int flexVal2;
int flexVal3;
int flexVal4;
int flexVal5;

int angleToPulse(int ang);

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() has been updated by Robojax
void loop() {
  //Thumb
  flexVal1 = analogRead(flexPin1);
  flexVal1 = map(flexVal1, 800, 900, 10, 170);
  flexVal1 = constrain(flexVal1, 0, 170);
  //Index
  flexVal2 = analogRead(flexPin2);
  flexVal2 = map(flexVal2, 800, 900, 10, 170);
  flexVal2 = constrain(flexVal2, 0, 170);
  //Middle
  flexVal3 = analogRead(flexPin3);
  flexVal3 = map(flexVal3, 800, 900, 10, 170);
  flexVal3 = constrain(flexVal3, 0, 170);
  //Ring
  flexVal4 = analogRead(flexPin4);
  flexVal4 = map(flexVal4, 800, 900, 10, 170);
  flexVal4 = constrain(flexVal4, 0, 170);
  //Pinky
  flexVal5 = analogRead(flexPin5);
  flexVal5 = map(flexVal5, 800, 900, 10, 170);
  flexVal5 = constrain(flexVal5, 0, 170);


  msg[0] = flexVal1;
  msg[1] = flexVal2;
  msg[2] = flexVal3;
  msg[3] = flexVal4;
  msg[4] = flexVal5;

   //Thumb
  pwm.setPWM(0, 0, angleToPulse(msg[0]));
  pwm.setPWM(1, 0, angleToPulse(msg[0]));
  //Index
  pwm.setPWM(2, 0, angleToPulse(msg[1]));
  pwm.setPWM(3, 0, angleToPulse(msg[1]));
  //Middle
  pwm.setPWM(4, 0, angleToPulse(msg[2]));
  pwm.setPWM(5, 0, angleToPulse(msg[2]));
  //Ring
  pwm.setPWM(6, 0, angleToPulse(msg[3]));
  pwm.setPWM(7, 0, angleToPulse(msg[3]));
  //Pinky
  pwm.setPWM(8, 0, angleToPulse(msg[4]));
  pwm.setPWM(9, 0, angleToPulse(msg[4]));

  //Thumb Movement 
  //pwm.setPWM(10, 0, angleToPulse(msg[5]));
  delay(10);
}

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
  
 
