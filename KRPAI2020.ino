#include "header.h"

void setup()
{
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
 
  init_bot();
  delay(2000);
}

void loop()
{   
  delay(10);
}
