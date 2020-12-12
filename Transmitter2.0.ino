//Final Transmitter 2.0
#include <SPI.h>    //the communication interface with the modem
#include "RF24.h"                     //the library which helps us to control the radio modem
#include <nRF24L01.h>

int msg[5];

int flexPin1 = A1;
int flexPin1 = A2;
int flexPin1 = A3;
int flexPin1 = A4;
int flexPin1 = A5;
//int flexPin1 = A6;

int flexVal1;
int flexVal2;
int flexVal3;
int flexVal4;
int flexVal5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();       //it activates the modem.
  radio.setDataRate( RF24_250KBPS );

  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
  radio.setPALevel(RF24_PA_MAX);      //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.setChannel(90);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  flexVal1 = analogRead(flexPin1);
  flexVal1 = map(flexVal1, 800, 900, 10, 170);
  flexVal1 = constrain(flexVal1, 0, 170);
  
  //Index Value
  flexVal2 = analogRead(flexPin2);
  flexVal2 = map(flexVal2, 800, 900, 10, 170);
  flexVal2 = constrain(flexVal2, 0, 170);
  
  //Middle Value
  flexVal3 = analogRead(flexPin3);
  flexVal3 = map(flexVal3, 800, 900, 10, 170);
  flexVal3 = constrain(flexVal3, 0, 170);
  
  //Ring Value
  flexVal4 = analogRead(flexPin4);
  flexVal4 = map(flexVal4, 800, 900, 10, 170);
  flexVal4 = constrain(flexVal4, 0, 170);
  
  //Pinky Value
  flexVal5 = analogRead(flexPin5);
  flexVal5 = map(flexVal5, 800, 900, 10, 170);
  flexVal5 = constrain(flexVal5, 0, 170);

  //thumb rotate Value
  flexVal6 = analogRead(flexPin6);
  flexVal6 = map(flexVal6, 800, 900, 10, 170);
  flexVal6 = constrain(flexVal6, 0, 170);


  msg[0] = flexVal1;
  msg[1] = flexVal2;
  msg[2] = flexVal3;
  msg[3] = flexVal4;
  msg[4] = flexVal5;

  radio.write(&msg, sizeof(msg));
}
