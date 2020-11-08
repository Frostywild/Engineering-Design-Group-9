
//Receiver Code (Hand) - Mert Arduino and Tech

#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem
#include <nRF24L01.h>
#include "PCA9685.h"
#include <Wire.h>



#define LED 3
//define the servo name
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;
Servo myServo6;

RF24 radio(9,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 9 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int msg[5];

void setup(){

   
  //define the servo input pins
  myServo1.attach(15); //A1
  myServo2.attach(16); //A2
  myServo3.attach(17); //A3
  myServo4.attach(18); //A4
  myServo5.attach(19); //A5
  myServo6.attach(20); //

  //servo.init(0x7f);

  
  Serial.begin(9600);

  radio.begin();                    //it activates the modem.
  radio.setDataRate( RF24_250KBPS );
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();   //enable receiving data via modem
  radio.setPALevel(RF24_PA_MAX);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.setChannel(90);
  
  }


void loop(){
        while(radio.available()){
        radio.read(&msg, sizeof(msg));
  //Index Finer
        myServo1.write(msg[0]); //A1
        myServo2.write(msg[0]); //A2
        }
  //delay(10);

}
   
/*
  //Middle Finger
  
    myServo3.write(msg[4]); //A3
    myServo4.write(msg[4]); //A4
    
    myServo5.write(msg[3]); //A5
    myServo6.write(msg[3]); //A6
 */
