#include "header.h"
#include "Robot.h"

Robot KSR;
Kaki coba;


void setup()
{
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  coba = Kaki(5,2,6, 1,1,2);
//  KSR = Robot();
//  KSR.kaki.init();
//  delay(2000);
//  KSR.kaki.stand();
//  delay(2000);
}

//void testJalan(){
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalan(MAJU);
//  delay(1000);
//  KSR.stand();
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.putar(KANAN);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalan(MAJU);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.putar(KIRI);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalan(MUNDUR);
//  delay(1000);
//}
//
//void testJalanSpread(){
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalanSpread(MAJU);
//  delay(1000);
//  KSR.kaki.stand();
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.putar(KANAN);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalanSpread(MAJU);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.putar(KIRI);
//  delay(1000);
//  for(int i = 0; i< 3; i++)
//    KSR.kaki.jalanSpread(MUNDUR);
//  delay(1000);
//}

void loop()
{ 
//  testJalan();
//  KSR.kaki.berdiriSpread();
//  testJalanSpread();
//    coba.jalan(MAJU);
//    delay(2000);
    
    Serial.println("Init");
    coba.init();
    delay(2000);
    Serial.println("berdidi");
    coba.berdiriSpread();
    delay(2000);
//    Serial.println("maju");
//    for(int i = 0; i < 10; i++)
//    coba.jalan(MAJU);
//    delay(2000);
//    Serial.println("mundur");
//    for(int i = 0; i < 10; i++)
//    coba.putar(90,KANAN);
//    delay(2000);
}

//void setup(){
//    ax12a.begin(BaudRate, DirectionPin, &Serial);
//    Serial.begin(1000000);
////    ax12a.setEndless(5, OFF);
////    ax12a.turn(5, RIGHT, 100);    
//    ax12a.move(5, 0);
//    ax12a.move(6, 1000);
//    int deg = map(-0, 0, 150, 512, 0);
//    ax12a.move(2, deg);
//}

//void loop(){
//    int deg = map(0, 0, 180, 512, 1024);
//    ax12a.move(2, deg);
//    delay(2000);
//    deg = map(90, 0, 180, 512, 1024);
//    ax12a.move(2, deg);
//    delay(2000);
//    deg = map(-90, 0, 180, 512, 1024);
//    ax12a.move(2, deg);
//    delay(2000);
    
//}
