#include "header.h"
#include "KakiController.h"

KakiController coba;
void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  coba.berdiri();
  delay(1000);
}

void testPanjat(){
//  coba.initPanjatDua();
//  delay(lamabanget);

  coba.panjatDua(1);
  delay(lamabanget);
  coba.panjatDua(2);
  delay(lamabanget);  
}

void testPanjatKuda(){
  coba.initKuda();
  delay(lamabanget);

  for(int i = 0; i < 5; i++){
    coba.panjatKuda(45);
    delay(lamabanget);   
  }
}

void testPanjatPenyu(){
  coba.initPenyu();
  delay(lamabanget);

  for(int i = 0; i < 5; i++){
    coba.panjatPenyu(); 
    delay(lamabanget);   
  }
}

void testJalanLurus(){
  coba.berdiri();
  delay(2000);
  coba.putar(KANAN,5);
  delay(2000);
  for(int i = 0; i < 5; i++){
    coba.jalan(MAJU);
    delay(sedang);
  }
  
  coba.berdiri();
  delay(2000);
  coba.putar(KIRI,10);
  delay(2000);
  for(int i = 0; i < 5; i++){
    coba.jalanDua(MAJU);
    delay(sedang);
  }
  
}

void testJalan(){
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 10; i++){
    coba.jalan(MAJU);
    delay(sedang);
  }
  
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 10  ; i++){
    coba.jalan(MUNDUR);
    delay(sedang);
  }
}

void testPUTAR(){
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KANAN, SUDUTPUTAR30);
    delay(sedang);
  }
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KIRI, SUDUTPUTAR30);
    delay(sedang);
  }
}

void testJalur(){
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.jalan(MAJU);
    delay(sedang);
  }
  
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KANAN,18);
    delay(sedang);
  }
  
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.jalan(MAJU);
    delay(sedang);
  }
  
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KIRI,18);
    delay(sedang);
  }

  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.jalan(MUNDUR);
    delay(sedang);
  }

  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KANAN,18);
    delay(sedang);
  }

  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.jalan(MUNDUR);
    delay(sedang);
  }

  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 3; i++){
    coba.putar(KIRI,18);
    delay(sedang);
  }  
}
//
void loop(){
//  testPUTAR();
 //  delay(2000);
//  testJalan();
//  delay(2000);
  
  testJalan();
//  testPanjatPenyu();
//  testJalan();
}
