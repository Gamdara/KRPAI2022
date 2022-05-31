#include "header.h"
#include "Robot.h"

Robot KSR;
int state = 0;

void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  KSR.kaki.init();
  delay(1000);
  state = 1;
}

void loop(){
  switch(state){
    case 1:
      while(KSR.mata.depan.bacaJarak() > 20){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 2:
      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 2){
        KSR.IR.depan.bacaPutih();
        KSR.IR.belakang.bacaPutih();
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      while(KSR.mata.depan.bacaJarak() > 20 ){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 3:
      while(KSR.mata.kiri.bacaJarak() < 10 && KSR.mata.kanan.bacaJarak() < 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      while(KSR.mata.depan.bacaJarak() > 40 ){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;  
    case 4:
      for(int i = 0; i < 5; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;  
    case 5:
      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 1){
        KSR.IR.depan.bacaPutih();
        KSR.IR.belakang.bacaPutih();
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      state++;
      break;
    case 6:
      while(KSR.pemadam.cekApi()){
        KSR.kaki.putar(KIRI);
        delay(50);
        KSR.pemadam.semprot();
        KSR.kaki.putar(KANAN);
        delay(50);
        KSR.kaki.putar(KANAN);
        delay(100);
        KSR.kaki.putar(KIRI);
        delay(50);
      }
      state++;
      break;
    case 7:
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      if(KSR.sWarna.adaKorban()){
        state++;
        break;
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 8:
      KSR.capit.taruh();
      delay(100);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }  
      KSR.capit.ambil();
      delay(100);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(100);  
      }
      KSR.capit.naik();
      delay(100);
      state++;
      break;
    case 9:
      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(100);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(100);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(100);  
        }
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(100);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(100);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(100);  
        }
      }
      state++;
      break;
    case 10:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      KSR.capit.turun();
      delay(100);
      KSR.capit.taruh();
      delay(100);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(100);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      state++;
      break;
    case 11:
      for(int i = 0; i < 15; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      state++;
      break;
    case 12:
      while(KSR.mata.depan.bacaJarak() > 30)
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      state++;
      break;
    case 13:
      while(KSR.pemadam.cekApi()){
        KSR.kaki.putar(KIRI);
        delay(50);
        KSR.pemadam.semprot();
        KSR.kaki.putar(KANAN);
        delay(50);
        KSR.kaki.putar(KANAN);
        delay(100);
        KSR.kaki.putar(KIRI);
        delay(50);
      }
      state++;
      break;
    case 14:
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      if(KSR.sWarna.adaKorban()){
        state++;
        break;
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 15:
      KSR.capit.taruh();
      delay(100);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }  
      KSR.capit.ambil();
      delay(100);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(100);  
      }
      KSR.capit.naik();
      delay(100);
      state++;
      break;
    case 16:
      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(100);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(100);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(100);  
        }
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(100);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(100);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(100);  
        }
      }
      state++;
      break;
    case 17:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      for(int i = 0; i < 5; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(100);  
      }
      state++;
      break;
    case 18:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      KSR.capit.turun();
      delay(100);
      KSR.capit.taruh();
      delay(100);
      while(KSR.mata.depan.bacaJarak() > 40){
        KSR.kaki.jalan(MUNDUR);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 19:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(100);  
      }
      state++;
      break;
    case 20:
      while(KSR.mata.kiri.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(100);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(100);  
      }
      state++;
      break;
  }
}
