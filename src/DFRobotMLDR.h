#include <Arduino.h>

#ifndef __DFRobotMLDR_H__
#define __DFRobotMLDR_H__

/* Default device address */
#define DEFAULT_ADDRESS 0x74

/* Action Registry Address */
#define ACTION_REGISTRY 0x10

/* Grab reading command byte */
#define TAKEREADINGCOMMAND 0xB0

/* Read registry address */
#define READ_REGISTRY 0x02

/* Class allows the reading from a DFRobot Mini Laser Distance Range Sensor Module*/
class DFRobotMLDR
{
  private:

    /* Read buffer */
    uint8_t readBuffer[2] = { 0, 0 };

    /* Write to the device registry */
    bool StartRangeReading();

    /* Write to the device registry */
    bool WriteRequestRangeCommand();
    
    /* Read the range*/
    bool ReadRange();
    
  public:
    DFRobotMLDR();
    
    /* Get a range reading */
    int GetRangeInMM();
};

#endif