//#include "header.h"
//
//KakiController coba;
//Capit capit;
////SensorJarakController mata;
////Robot KSR;
//
////Servo c;
////Servo d;
//
//void testCapit(){
//  
//  delay(1000);
//  capit.taruh();
//  delay(1000);
//  capit.turun();
//  delay(1000);
//  capit.ambil();
//  delay(1000);
//  capit.naik();
//
//  Serial.println(capit.mata.bacaJarak());
//}
//
//void setup(){
//  ax12a.begin(BaudRate, DirectionPin, &Serial);
//  Serial.begin(1000000);
////    Serial.begin(9600);
////    capit.init();
////    testCapit();
////    coba.berdiri();  
////  delay(1000);
//}
//
//void testSamping(int dir){
//  coba.berdiri();
//  delay(1000);
//  coba.initSamping();
//  delay(1000);
//  for(int i = 0; i < 5; i++){
//    coba.jalanSamping(dir);
//    delay(1000);  
//  }
//  coba.berdiri();
//  delay(1000);
//}
//
//void testPiramid(int dir){
//  coba.initPiramid();
//  delay(1000);
//  for(int i = 0; i < 5; i++){
//    coba.naikPiramid(dir);
//    delay(1000);  
//  }
//}
//
//void testPrePiramid(int dir){
//  coba.initPrePiramid();
//  delay(1000);
//  for(int i = 0; i < 10; i++){
//    coba.naikPrePiramid(dir);
////    delay(1000);  
//  }
//}
//
//void testPanjat(){
//  coba.panjat(1);
//  delay(lamabanget);
//  coba.panjat(2);
//  delay(lamabanget);  
//}
//
//void testTurun(){
//  coba.turun(1);
//  delay(lamabanget);
//  coba.turun(2);
//  delay(lamabanget);  
//}
//
//
//void testJalanLurus(int dir){
//  coba.berdiri();
//  delay(2000);
//  coba.putar(KANAN,5);
//  delay(2000);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(dir);
//    delay(sedang);
//  }
//}
//
//void testJalan(int dir, int sudut = -65,int sudutJalan = SUDUTJALANDEF, int dile = lamabanget){
//  coba.jalan(dir, sudut,sudutJalan, sedang);
//  delay(sedang);
//}
//
//void testJalanKiri(int dir, int sudut = -65,int sudutJalan = SUDUTJALANDEF, int dile = lamabanget){
//  coba.jalanKiri(dir, sudut,sudutJalan, sedang);
//  delay(sedang);
//}
//
//void testPUTAR(){
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 8; i++){
//    coba.putar(KANAN,18,-65,cepet);
//    delay(cepet);
//  }
//  coba.berdiri();
//  delay(2000);
//  for(int i = 0; i < 8; i++){
//    coba.putar(KIRI,18,-65,cepet);
//    delay(cepet);
//  }
//}
//
//void testJalur(){
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MAJU, -65,15,cepet);
//    delay(cepet);
//  }
//  
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 4; i++){
//    coba.putar(KANAN,18,-65,cepet);
//    delay(cepet);
//  }
//  
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MAJU, -65,15,cepet);
//    delay(cepet);
//  }
//  
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 4; i++){
//    coba.putar(KIRI,18,-65,cepet);
//    delay(cepet);
//  }
//
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MUNDUR, -65,15,cepet);
//    delay(cepet);
//  }
//
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 4; i++){
//    coba.putar(KANAN,18,-65,cepet);
//    delay(cepet);
//  }
//
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 5; i++){
//    coba.jalan(MUNDUR, -65,15,cepet);
//    delay(cepet);
//  }
//
//  coba.berdiri();
//  delay(500);
//  for(int i = 0; i < 4; i++){
//    coba.putar(KIRI,18,-65,cepet);
//    delay(cepet);
//  }  
//}
////
//void naikGunung(){
//  coba.initPanjat();
//  for(int i = 0 ; i < 5; i ++){
//    testPanjat();
//  }
//  delay(2000);
//  coba.berdiri();  
//  for(int i = 0 ; i < 10; i ++){
//    coba.jalanPelan(MAJU, lamabanget, -45);  
//  }
//  delay(2000);
//  coba.berdiri();  
//  for(int i = 0 ; i < 10; i ++){
//    coba.jalanPelan(MAJU, lamabanget, -45);  
//  }
//  delay(2000);
//}
//
//void loop(){
//    testPutar();
////  Serial.println(capit.mata.bacaJarak());
////  delay(200);
////  coba.berdiri();
////  delay(lama);
////  for(int i = 0; i < 5; i++){
////    testJalur();  
////    delay(1000);
////  }
////  coba.berdiri();
////  delay(lama);
////  for(int i = 0; i < 5; i++){
////    testJalanKiri(MAJU, -65, 10, cepet);  
////    delay(cepet);
////  }
//  
//}
