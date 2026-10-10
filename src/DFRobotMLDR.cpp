
#include "DFRobotMLDR.h"
#include <Wire.h>

/* Initialises a new instance of the DFRobotMLDR. Starts the I2C communications. */
DFRobotMLDR::DFRobotMLDR()
{
  Wire.begin();
}

/* Gets the range from the sensor */
int DFRobotMLDR::GetRangeInMM()
{
  if(StartRangeReading())
  {
    delay(50);
    if(ReadRange())
    {
      int distance = readBuffer[0] * 0x100 + readBuffer[1] + 10;
      return distance;
    }
    else
    {
      return 0;
    }
  }
  return -1;
}

/* Write th request for the sensor to take a reading. */
bool DFRobotMLDR::StartRangeReading()
{
  // Send the package
  Wire.beginTransmission(DEFAULT_ADDRESS);
  uint8_t writeCommand[2] = { ACTION_REGISTRY, TAKEREADINGCOMMAND };
  Wire.write(writeCommand, 2);

  // End and check for success.
  if(Wire.endTransmission() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

/* Write the command for requesting the range from the sensor */
bool DFRobotMLDR::WriteRequestRangeCommand()
{
  // Send the package
  Wire.beginTransmission(DEFAULT_ADDRESS);
  uint8_t readCommand[1] = { 0x02 };
  Wire.write(readCommand ,1);

  // End and check for success.
  if(Wire.endTransmission() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

/* Requests the latest reading from the sensor */
bool DFRobotMLDR::ReadRange()
{
  if(WriteRequestRangeCommand())
  {
    // Get the response
    Wire.requestFrom(DEFAULT_ADDRESS, (uint8_t)2);

    readBuffer[0] = Wire.read();
    readBuffer[1] = Wire.read();

    return true;
  }

  return false;
}