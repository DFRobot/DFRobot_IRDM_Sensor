/*!
  * @file getDistance.ino
  * @brief 获取障碍物到传感器的距离
  * @n Distance Measuring Sensor Unit 
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license     The MIT License (MIT)
  * @author      [PengKaixing]kaixing.peng@dfrobot.com)
  * @version  V1.0.0
  * @date  2022-9-3
  * @url https://github.com/DFRobot/DFRobot_IRDMSensor
  */
#include "DFRobot_IRDMSensor.h"

//change the parameter selection pin
DFRobot_IRDMSensor DIS(A0);      
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float Distance;
  Distance = DIS.getDistance();  //  get Distance
  Serial.print("The distance is: ");
  Serial.print(Distance);
  Serial.println("cm");
  delay(500);
}