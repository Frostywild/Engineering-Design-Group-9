#include <Adafruit_PWMServoDriver.h>


#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

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
  pwm.begin();
  pwm.setPWMFreq(60);
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

for (int x=0; x<10; x++){
  
}

  angle[0] = map(angle[0], 600, 900, 0, 180)
  //angle[1] = (float)sensor_value[1] * 300 / 1023;
 // angle[2] = (float)sensor_value[2] * 300 / 1023;
//  angle[3] = (float)sensor_value[3] * 300 / 1023;
  Serial.println(angle[0]);

pwm.setPWM(0,0,angelToPulse(angle[0]);
//  servo.setAngle(1, map(angle[0], 600, 900, 0, 180));
//  servo.setAngle(2, map(angle[0], 600, 900, 0, 180));
//  servo.setAngle(3, map(angle[0], 600, 900, 0, 180));
  delay(20);


}

