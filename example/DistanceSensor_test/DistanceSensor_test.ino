/*!
 * @file testDistanceSensor.ino
 * @brief DFRobot's Infrared Sensor
 * @n This example can print the test distance in serial port
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 *
 * @author [Zhangjiawei]
 * @version  V1.0
 * @date  2017-6-22
 * @https://github.com/DFRobot/DFRobot_IRDM_Sensor
 */
 
#include <Wire.h>
#include "DFRobot_IRDM_Sensor.h"

DFRobot_IRDM_Sensor DIS(A0);      //change the parameter selection pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  float Distance;
  Distance = DIS.getDistance();  //  get Distance
  Serial.print("The distance is: ");
  Serial.print(Distance);
  Serial.println("cm");
  delay(500);
}