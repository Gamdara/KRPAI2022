#include "header.h"
#include "Robot.h"

Robot KSR;

void setup()
{
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
 
  KSR = Robot();
  KSR.init();
  delay(2000);
  KSR.stand();
  delay(2000);
}

void loop()
{
  KSR.stand();   
  for(int i = 0; i< 3; i++)
    KSR.walk(MAJU);
  delay(1000);
  for(int i = 0; i< 3; i++)
    KSR.walk(MUNDUR);
  delay(1000);
}
