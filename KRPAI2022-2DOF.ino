//#include "header.h"
////#include "Robot.h"
//
//Robot KSR;
//int state = 0;
//int counterState = 0;
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
////  jalan dari home
//    case 1:
//      if(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI,18);
//          delay(lama);  
//        }
//        KSR.kaki.berdiri();
//        state++;  
//      }
//      break;
////  lewati puing
//    case 2:
//      if(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag(MAJU, -45, 15, cepet);
//        delay(cepet);
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        KSR.kaki.berdiri();
//        delay(lama);
//        KSR.kaki.initPanjat();
//        state++;  
//      }
//      break;
////  panjat bukit
//    case 3:
//      int garis = KSR.IR.belakang.cekGaris();
//      
//      if(garis == 0 && counterState == 0){
//        for(int i = 0 ; i < 5; i ++){
//          KSR.kaki.panjat(1);
//          delay(lamabanget);
//          KSR.kaki.panjat(2);
//          delay(lamabanget);  
//        }  
//        delay(2000);
//      }
//      else if(garis == 1 && counterState >= 0){
//        KSR.kaki.berdiri();  
//        delay(20);
//        KSR.jalanZigZag(MAJU,-45,15, lamabanget);  
//        delay(lamabanget);
//        counterState++;
//      }
//      else if(garis == 0 && counterState > 0){
//        KSR.kaki.berdiri();  
//        delay(sedang);
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        counterState = 0;
//        state++;
//      }
//      else{
//        for(int i = 0; i < 6; i++){
//          KSR.kaki.putar(KANAN, 18);  
//        }
//      }
//      break;  
////  jalan belok ke tikungan ruang 1  
//    case 4:
//      if(KSR.mata.depan.bacaJarak() > 35){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI,18);
//          delay(lama);  
//        }
//        KSR.kaki.berdiri();
//        state++;  
//      }
//      break;  
////  masuk ruang 1
//    case 5:
//      if(KSR.mata.depan.bacaJarak() > 15 ){
//        KSR.jalanZigZag(MAJU);
//        delay(lama);
//      }
//      else if(abs(KSR.mata.kanan.bacaJarak() - KSR.mata.kiri.bacaJarak()) > 5 ){
//        KSR.kaki.jalanSamping(KANAN);
//        delay(sedang);
//      }
//      else if(abs(KSR.mata.kiri.bacaJarak() - KSR.mata.kanan.bacaJarak()) > 5 ){
//        KSR.kaki.jalanSamping(KIRI);
//        delay(sedang);
//      }
//      else{
//        state++;  
//      }
//      break;
////  padam api  
//    case 6:
//      if(KSR.pemadam.cekApi(3)){
//        KSR.pemadam.semprot(HIGH);
//        delay(sedang);  
//        KSR.kaki.putar(KIRI);
//        delay(cepat);  
//        KSR.kaki.putar(KANAN);
//        delay(cepat);  
//        KSR.kaki.putar(KANAN);
//        delay(cepat);  
//        KSR.kaki.putar(KIRI);
//        delay(cepat);  
//      }
//      else{
//        state++;  
//      }
//      break;
////  cari korban  
//    case 7:
//      if(KSR.mata.kiri.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KIRI);
//        delay(sedang);
//      }
//      else if(KSR.capit.mata.bacaJarak() < 10){
//        state++;
//        break;
//      }
//      else if(KSR.mata.kanan.bacaJarak() > 5 ){
//        KSR.kaki.jalanSamping(KANAN);
//        delay(sedang);
//      }
//      else if(KSR.capit.mata.bacaJarak() < 10){
//        state++;
//        break;
//      }
//      break;
////  angkat korban  
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
////  ke safe zone  
//    case 9:
//      if(KSR.mata.belakang.bacaJarak() > 15){
//        KSR.jalanZigZag( MUNDUR, -45, 15, sedang);
//      }
//      else{
//        for(int i = 0; i < 8; i++){
//          KSR.kaki.putar(KANAN);
//          delay(lama);  
//        }  
//        KSR.capit.turun();
//        delay(lama);
//        KSR.capit.taruh();
//        delay(lama);
//        KSR.capit.naik();
//        delay(lama);
//        state++;
//      }
//      break;
////  mundur dari safe zone
//    case 10:
//      if(KSR.mata.depan.bacaJarak() <= 15){
//        KSR.kaki.jalan(MUNDUR);
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        state++;  
//      }
//      break;
////  ke tikungan home  
//    case 11:
//      if(KSR.mata.depan.bacaJarak() > 15){
//        KSR.jalanZigZag(MAJU);
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        state++;  
//      }
//      break;  
////  kembali ke home
//    case 12:
//      if(abs(KSR.mata.depan.bacaJarak() - KSR.mata.belakang.bacaJarak()) > 5 ){
//        KSR.jalanZigZag(MAJU);
//      }
//      else{
//        KSR.kaki.berdiri();
//        state = 0;  
//      }
//      
//      break;
//  }
//}
