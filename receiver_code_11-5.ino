
//Receiver Code (Hand) - Mert Arduino and Tech

#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem
#include <nRF24L01.h>
#include "PCA9685.h"
#include <Wire.h>



//define the servo name

RF24 radio(9,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 9 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int msg[5];

void setup(){

   
  //define the servo input pins

  
  Serial.begin(9600);

  radio.begin();                    //it activates the modem.
  radio.setDataRate( RF24_250KBPS );
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();   //enable receiving data via modem
  radio.setPALevel(RF24_PA_MAX);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.setChannel(90);
  
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  }


void loop(){
  while(radio.available()){
  
    
  radio.read(&msg, sizeof(msg));
  //Index Finer
  int x=0;
  for(int i=0; i<10; i+2)
  {

    delay(50);
    pwm.setPWM(i, 0, angleToPulse(msg[x]) );
    pwm.setPWM(i+1, 0, angleToPulse(msg[x]) );
    // see YouTube video for details (robojax)
    x++;
       
  }
  x=0;
     
  
delay(10);
}
   
/*
  //Middle Finger
  
    myServo3.write(msg[4]); //A3
    myServo4.write(msg[4]); //A4
    
    myServo5.write(msg[3]); //A5
    myServo6.write(msg[3]); //A6
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
