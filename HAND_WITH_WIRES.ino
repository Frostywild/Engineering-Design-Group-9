#include "PCA9685.h"
#include <Wire.h>
#include "I2Cdev.h"


//de
ServoDriver servo;
//Servo servo;

#define FlexSensor_1 A0
#define FlexSensor_2 A1
#define FlexSensor_3 A2
#define FlexSensor_4 A3
#define FlexSensor_5 A6

void setup()
{
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  Serial.begin(9600);
  
  servo.init(0x7f);
  
  pinMode(FlexSensor_1, INPUT);
  pinMode(FlexSensor_2, INPUT);
  pinMode(FlexSensor_3, INPUT);
  pinMode(FlexSensor_4, INPUT);
  pinMode(FlexSensor_5, INPUT);

  // uncomment this line if you need to use a special servo
  // servo.setServoPulseRange(600,2400,180);
  Serial.begin(9600);
}

void loop()
{

  int angle[6];
  int sensor_value[6];
  sensor_value[0] = analogRead(FlexSensor_1);
  /*
  sensor_value[1] = analogRead(FlexSensor_2);
  sensor_value[2] = analogRead(FlexSensor_3);
  sensor_value[3] = analogRead(FlexSensor_4);
  sensor_value[4] = analogRead(FlexSensor_5);
*/

  angle[0] = (float)sensor_value[0] * 300 / 1023;
  angle[1] = (float)sensor_value[1] * 300 / 1023;
  angle[2] = (float)sensor_value[2] * 300 / 1023;
  angle[3] = (float)sensor_value[3] * 300 / 1023;
  Serial.println(angle[0]);

  servo.setAngle(12, map(angle[0], 0, 300, 0, 170));
  servo.setAngle(13, map(angle[1], 0, 300, 0, 180));
  servo.setAngle(14, map(angle[2], 0, 300, 20, 180));
  servo.setAngle(15, map(angle[3], 0, 300, 20, 160));
  delay(15);


}
