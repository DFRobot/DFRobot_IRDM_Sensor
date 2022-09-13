/*!
  * @file DFRobot_IRDMSensor.h
  * @brief DFRobot's Infrared Sensor
  * @n Distance Measuring Sensor Unit 
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license     The MIT License (MIT)
  * @author      [PengKaixing]kaixing.peng@dfrobot.com)
  * @version  V1.0.0
  * @date  2022-9-3
  * @url https://github.com/DFRobot/DFRobot_IRDMSensor
  */
#ifndef DFRobot_IRDM_Sensor_h
#define DFRobot_IRDM_Sensor_h
#include <Arduino.h>
#include <stdlib.h>
#include <stdint.h>
class DFRobot_IRDMSensor {
public:
  /**
   * @fn DFRobot_IRDMSensor
   * @brief This function will set the PIN to read SensorValue
   * @param pin 传感器接入主控的引脚
   */
  DFRobot_IRDMSensor(int pin){_pin=pin;}
  ~DFRobot_IRDMSensor(){}

  /**
   * @fn getSensorValue
   * @brief 获取传感器返回数据
   * @return float类型，传感器返回数据
   */
  float getSensorValue(void);

  /**
   * @fn getDistance
   * @brief This is a function that converts SensorValue to distance 
   * @return float类型，converts SensorValue to distance 
   */
  float getDistance(void);

private:
 int _pin; 
};

#endif