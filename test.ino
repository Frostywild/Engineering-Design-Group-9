#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem
#include <nRF24L01.h>

//define the servo name
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;
Servo myServo6;

void setup(){

  //define the servo input pins
  myServo1.attach(15); //A1
  myServo2.attach(16); //A2
  
  }


void loop(){
  //Index Finer
  for(int i = 10;i<170;i++)
  {
        myServo1.write(i); //A1
        myServo2.write(i); //A2
        delay(1000);
  }
  for(int k = 170;k>10;k--)
  {
        myServo1.write(k); //A1
        myServo2.write(k); //A2
        delay(1000);
  }
         
}
