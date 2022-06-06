//#include "header.h"
////#include "Robot.h"
//
//Robot KSR;
//int state = 0;
//
//void setup(){
//  ax12a.begin(BaudRate, DirectionPin, &Serial);
//  Serial.begin(1000000);
//  KSR.kaki.init();
//  delay(1000);
//  state = 1;
//}
//
//void loop(){
//  switch(state){
//    case 1:
//      while(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI,18);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 2:
//      while(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 3:
//      KSR.kaki.initPanjat();
//      for(int i = 0 ; i < 5; i ++){
//        KSR.kaki.panjat(1);
//        delay(lamabanget);
//        KSR.kaki.panjat(2);
//        delay(lamabanget);  
//      }
//      delay(2000);
//      KSR.kaki.berdiri();  
//      KSR.jalanLangkah(10,-45,SUDUTJALANDEF, lamabanget);
//      delay(2000);
//      KSR.kaki.berdiri();  
//      KSR.jalanLangkah(10,-45,SUDUTJALANDEF, lamabanget);
//      delay(2000);
//      while(KSR.mata.kiri.bacaJarak() < 10 && KSR.mata.kanan.bacaJarak() < 10){
//        KSR.jalanZigZag();
//        delay(lama);
//      }
//      
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;  
//    case 4:
//      KSR.jalanLangkah(5);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;  
//    case 5:
//      while(KSR.mata.depan.bacaJarak() < 30 ){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      while(KSR.mata.kanan.bacaJarak() - KSR.mata.kiri.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KANAN);
//        delay(sedang);
//      }
//      while(KSR.mata.kiri.bacaJarak() - KSR.mata.kanan.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KIRI);
//        delay(sedang);
//      }
//      state++;
//      break;
//    case 6:
//      while(KSR.pemadam.cekApi(3)){
//        KSR.kaki.putar(KIRI);
//        delay(sedang);  
//        KSR.pemadam.semprot();
//        KSR.kaki.putar(KANAN);
//        delay(sedang);
//        KSR.kaki.putar(KANAN);
//        delay(sedang);
//        KSR.kaki.putar(KIRI);
//      }
//      state++;
//      break;
//    case 7:
//      while(KSR.mata.kiri.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KIRI);
//        delay(sedang);
//      }
//      if(KSR.capit.mata.bacaJarak() < 10){
//        state++;
//        break;
//      }
//      while(KSR.mata.kanan.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KANAN);
//        delay(sedang);
//      }
//      if(KSR.capit.mata.bacaJarak() < 10){
//        state++;
//        break;
//      }
//      state++;
//      break;
//    case 8:
//      KSR.capit.turun();
//      KSR.capit.taruh();
//      delay(sedang);
//      KSR.jalanLangkah(2);
//      delay(sedang);
//      KSR.capit.ambil();
//      delay(sedang);
//      KSR.capit.naik();
//      delay(sedang);
//      state++;
//      break;
//    case 9:
//      while(KSR.mata.belakang.bacaJarak() > 15){
//        KSR.jalanZigZag(MUNDUR);
//      }
//      for(int i = 0; i < 6; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      KSR.capit.turun();
//      delay(lama);
//      KSR.capit.taruh();
//      delay(lama);
//      KSR.capit.naik();
//      delay(lama);
//      state++;
//      break;
//    case 10:
//      while(KSR.mata.depan.bacaJarak() <= 15){
//        KSR.kaki.jalan(MUNDUR);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 11:
//      while(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag();
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;  
//    case 12:
//      while(abs(KSR.mata.depan.bacaJarak() - KSR.mata.belakang.bacaJarak()) > 5){
//        KSR.jalanZigZag();
//      }
//      KSR.kaki.berdiri();
//      break;
//  }
//}
