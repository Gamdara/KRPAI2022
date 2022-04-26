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
  for(int i = 0; i < 10; i++)
    maju();   
  delay(1000);
  for(int i = 0; i < 10; i++)
    mundur();
  delay(1000);
     
}
