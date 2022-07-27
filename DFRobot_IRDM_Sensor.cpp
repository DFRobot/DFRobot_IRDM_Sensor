/*!
 * @file DFRobot_IRDM_Sensor.cpp
 * @brief DFRobot's Infrared Sensor
 * @n Distance Measuring Sensor Unit
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 *
 * @author [Zhangjiawei]
 * @version  V1.0
 * @date  2017-6-22
 */

#include <Wire.h>
#include <Arduino.h>
#include <DFRobot_IRDM_Sensor.h>


float DFRobot_IRDM_Sensor::getSensorValue(){
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

float DFRobot_IRDM_Sensor::getDistance(){
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


