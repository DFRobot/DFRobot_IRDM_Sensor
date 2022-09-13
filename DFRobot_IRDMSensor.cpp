/*!
  * @file DFRobot_IRDMSensor.cpp
  * @brief DFRobot's Infrared Sensor
  * @n Distance Measuring Sensor Unit 
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license     The MIT License (MIT)
  * @author      [PengKaixing]kaixing.peng@dfrobot.com)
  * @version  V1.0.0
  * @date  2022-9-3
  * @url https://github.com/DFRobot/DFRobot_IRDMSensor
  */
#include <DFRobot_IRDMSensor.h>


float DFRobot_IRDMSensor::getSensorValue(void)
{
  float  minNum, maxNum, meanN, t;
  static float arr[7] = {0};
  uint16_t i=0,sensorValue, flagMin=0, flagMax=0;
  while(i<7){
    sensorValue = analogRead(_pin);   
    if(sensorValue>=240&&sensorValue<=512){
      arr[i]=sensorValue;
      i++;
    }
  }
  maxNum=arr[0];
  minNum=arr[0];
	for(i=0; i<7; i++){
    if(arr[i]<minNum){
      minNum = arr[i];
      flagMin = i;
    }
    if(arr[i]>maxNum){
      maxNum = arr[i];
      flagMax = i;
    }
  }
  t = arr[0];
  arr[0] = arr[flagMin];
  arr[flagMin] = t;
  t = arr[6];
  arr[6] = arr[flagMax];
  arr[flagMax] = t;
  meanN=(arr[1]+arr[2]+arr[3]+arr[4]+arr[5])/5;
  return meanN;
}

float DFRobot_IRDMSensor::getDistance(void)
{
  uint8_t i;
  float distance=0,SensorValue=0;
  for(i=0;i<40;i++){
    SensorValue=getSensorValue();
    if(SensorValue>313.8){
      distance+=28900/(SensorValue-218.0);
    }
    else{
      distance+=28800/(SensorValue-217.5);
    }
  }
  distance/=40;
  return distance;
}


