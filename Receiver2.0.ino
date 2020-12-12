//Final Receiver 2.0
#include <Wire.h>
#include <Servo.h>
#include <SPI.h> 
#include "RF24.h"
#include <nRF24L01.h>
//#include "PCA9685.h"
#include <Adafruit_PWMServoDriver.h>

RF24 radio(9,10); 
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

int msg[5]; 

int flexVal1;
int flexVal2;
int flexVal3;
int flexVal4;
int flexVal5;

// our servo # counter
uint8_t servonum = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  radio.begin();                    //it activates the modem.
  radio.setDataRate( RF24_250KBPS );
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();   //enable receiving data via modem
  radio.setPALevel(RF24_PA_MAX);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.setChannel(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  radio.read(&msg, sizeof(msg));

  pwm.setPWM(0, 0, angleToPulse(msg[0]));
  pwm.setPWM(1, 0, angleToPulse(msg[0]));
  //Index Control
  pwm.setPWM(2, 0, angleToPulse(msg[1]));
  pwm.setPWM(3, 0, angleToPulse(msg[1]));
  //Middle Control
  pwm.setPWM(4, 0, angleToPulse(msg[2]));
  pwm.setPWM(5, 0, angleToPulse(msg[2]));
  //Ring Control
  pwm.setPWM(6, 0, angleToPulse(msg[3]));
  pwm.setPWM(7, 0, angleToPulse(msg[3]));
  //Pinky Control
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
