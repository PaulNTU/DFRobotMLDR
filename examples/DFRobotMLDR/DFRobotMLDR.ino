#include "DFRobotMLDR.h"

DFRobotMLDR ranger = DFRobotMLDR();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int range = ranger.GetRangeInMM();
  
  // Text Output (Uncomment for text output).
  // Serial.print("Range: ");
  // Serial.print(range);
  // Serial.println("mm");

  // Plotter Output (Comment out to remove from text output).

  // We are creating three lines to 'bracket' the reading and 
  // to prevent the plotter from autoscaling. We can create labels
  // for each line with the : e.g. {Label}:{Value}
  Serial.print("Min:30,Max:4000,Range:");

  // Write the range reading (in mm's)
  Serial.println(range);

  // Minor delay. The library has an inbuilt 50ms delay to wait for the readings 
  // to respond on the sensor.
  delay(10);
}
