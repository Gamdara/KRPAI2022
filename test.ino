#include "header.h"
#include "KakiController.h"

KakiController coba;
void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  coba.berdiri();
  delay(1000);
  coba.initPanjatDua();
  delay(200);
}

void loop(){
  coba.panjatDua();
  delay(100);
//  for(int i = 0; i < 3; i++){
//    coba.jalan(MAJU);
//    delay(200);
//  }
//  
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 3; i++){
//    coba.putar(KANAN);
//    delay(200);
//  }
//  
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 3; i++){
//    coba.jalan(MUNDUR);
//    delay(200);
//  }
//  
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 3; i++){
//    coba.putar(KIRI);
//    delay(200);
//  }

//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MUNDUR);
//    delay(200);
//  }
//
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 5; i++){
//    coba.putar(KANAN);
//    delay(200);
//  }
//
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MUNDUR);
//    delay(200);
//  }
//
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 5; i++){
//    coba.putar(KIRI);
//    delay(200);
//  }
  
  delay(1000);
}
