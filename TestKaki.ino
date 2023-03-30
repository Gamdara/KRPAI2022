#include "header.h"
#include "KakiGroup.h"

KakiGroup coba;

void setup()
{
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  coba = KakiGroup();
}
void loop()
{ 
    Serial.println("Init");
    coba.init();
    delay(1000);
    Serial.println("berdidi");
    coba.berdiri();
    
    Serial.println("maju");
    for(int i = 0; i < 3; i++)
    coba.jalan(MAJU);
    delay(1000);
    
    Serial.println("mundur");
    for(int i = 0; i < 3; i++)
    coba.jalan(MUNDUR);
    delay(1000);

    Serial.println("putar kiri 10 derajat 3 kali");
    for(int i = 0; i < 3; i++)
    coba.putar(10,KIRI);
    delay(1000);
    
    Serial.println("putar kanan 10 derajat 3 kali");
    for(int i = 0; i < 3; i++)
    coba.putar(10,KANAN);
    delay(1000);
    
    // Serial.println("samping kiri");
    // for(int i = 0; i < 3; i++)
    // coba.jalanSamping(KIRI);
    // delay(1000);
    
    // Serial.println("samping kanan");
    // for(int i = 0; i < 3; i++)
    // coba.jalanSamping(KANAN);
    // delay(1000);
}