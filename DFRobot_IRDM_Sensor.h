/*!
 
* @file DFRobot_IRDM_Sensor.h
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

#ifndef DFRobot_IRDM_Sensor_h
#define DFRobot_IRDM_Sensor_h

#include <stdlib.h>
#include <stdint.h>

class DFRobot_IRDM_Sensor {
public:
 /*!
  *  @brief This function will set the PIN to read SensorValue
  */
 DFRobot_IRDM_Sensor(int pin){_pin=pin;}
 ~DFRobot_IRDM_Sensor(){}
 /*!
  *  @brief This function will provide a stable and accurate SensorValue
  */
  float getSensorValue();
 /*!
  *  @brief This is a function that converts SensorValue to distance 
  */	
  float getDistance();
private:
 int _pin; 
};

#endif