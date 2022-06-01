//#include "header.h"
//#include "Robot.h"

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
//      while(KSR.mata.depan.bacaJarak() > 20){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 2:
//      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 2){
//        KSR.IR.depan.bacaPutih();
//        KSR.IR.belakang.bacaPutih();
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      while(KSR.mata.depan.bacaJarak() > 20 ){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 3:
//      while(KSR.mata.kiri.bacaJarak() < 10 && KSR.mata.kanan.bacaJarak() < 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      while(KSR.mata.depan.bacaJarak() > 40 ){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;  
//    case 4:
//      for(int i = 0; i < 5; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;  
//    case 5:
//      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 1){
//        KSR.IR.depan.bacaPutih();
//        KSR.IR.belakang.bacaPutih();
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      state++;
//      break;
//    case 6:
//      while(KSR.pemadam.cekApi()){
//        KSR.kaki.putar(KIRI);
//        delay(sedang);
//        KSR.pemadam.semprot();
//        KSR.kaki.putar(KANAN);
//        delay(sedang);
//        KSR.kaki.putar(KANAN);
//        delay(lama);
//        KSR.kaki.putar(KIRI);
//        delay(sedang);
//      }
//      state++;
//      break;
//    case 7:
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.putar(KIRI);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      if(KSR.sWarna.adaKorban()){
//        state++;
//        break;
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.putar(KIRI);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 8:
//      KSR.capit.taruh();
//      delay(lama);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }  
//      KSR.capit.ambil();
//      delay(lama);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MUNDUR);
//        delay(lama);  
//      }
//      KSR.capit.naik();
//      delay(lama);
//      state++;
//      break;
//    case 9:
//      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KANAN);
//          delay(lama);  
//        }
//        while(KSR.mata.depan.bacaJarak() > 10){
//          KSR.kaki.jalan(MAJU);
//          delay(lama);
//        }
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KANAN);
//          delay(lama);  
//        }
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        while(KSR.mata.depan.bacaJarak() > 10){
//          KSR.kaki.jalan(MAJU);
//          delay(lama);
//        }
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//      }
//      state++;
//      break;
//    case 10:
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      KSR.capit.turun();
//      delay(lama);
//      KSR.capit.taruh();
//      delay(lama);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MUNDUR);
//        delay(lama);  
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 11:
//      for(int i = 0; i < 15; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 12:
//      while(KSR.mata.depan.bacaJarak() > 30)
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 13:
//      while(KSR.pemadam.cekApi()){
//        KSR.kaki.putar(KIRI);
//        delay(sedang);
//        KSR.pemadam.semprot();
//        KSR.kaki.putar(KANAN);
//        delay(sedang);
//        KSR.kaki.putar(KANAN);
//        delay(lama);
//        KSR.kaki.putar(KIRI);
//        delay(sedang);
//      }
//      state++;
//      break;
//    case 14:
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.putar(KIRI);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      if(KSR.sWarna.adaKorban()){
//        state++;
//        break;
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.putar(KIRI);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 15:
//      KSR.capit.taruh();
//      delay(lama);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }  
//      KSR.capit.ambil();
//      delay(lama);
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MUNDUR);
//        delay(lama);  
//      }
//      KSR.capit.naik();
//      delay(lama);
//      state++;
//      break;
//    case 16:
//      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KANAN);
//          delay(lama);  
//        }
//        while(KSR.mata.depan.bacaJarak() > 10){
//          KSR.kaki.jalan(MAJU);
//          delay(lama);
//        }
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KANAN);
//          delay(lama);  
//        }
//      }
//      else{
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//        while(KSR.mata.depan.bacaJarak() > 10){
//          KSR.kaki.jalan(MAJU);
//          delay(lama);
//        }
//        for(int i = 0; i < 3; i++){
//          KSR.kaki.putar(KIRI);
//          delay(lama);  
//        }
//      }
//      state++;
//      break;
//    case 17:
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      for(int i = 0; i < 5; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KANAN);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 18:
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      KSR.capit.turun();
//      delay(lama);
//      KSR.capit.taruh();
//      delay(lama);
//      while(KSR.mata.depan.bacaJarak() > 40){
//        KSR.kaki.jalan(MUNDUR);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 19:
//      while(KSR.mata.depan.bacaJarak() > 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.putar(KIRI);
//        delay(lama);  
//      }
//      state++;
//      break;
//    case 20:
//      while(KSR.mata.kiri.bacaJarak() > 10){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);
//      }
//      for(int i = 0; i < 3; i++){
//        KSR.kaki.jalan(MAJU);
//        delay(lama);  
//      }
//      state++;
//      break;
//  }
//}
