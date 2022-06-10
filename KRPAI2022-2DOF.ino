#include "header.h"

Robot KSR;
int state = 0;
int counterState = 0;
int langkah = 0;

void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  KSR.init();
  delay(cepet);
  delay(1000);
  state = 1;
}

void loop(){
  switch(state){
//  jalan dari home
    case 1:
      if(KSR.mata.depan.bacaJarak() > 23){
        if(KSR.mata.depan.bacaJarak() < 24 &&  KSR.mata.belakang.bacaJarak() < 12){
          for(int i = 0; i < 3; i++){
            KSR.kaki.putar(KANAN,18);
            delay(cepet);
          }
        }
        else if(KSR.mata.kanan.bacaJarak() > 35){
          for(int i = 0; i < 6; i++){
            KSR.kaki.putar(KANAN,18);
            delay(cepet);
          }
        }
        else{
          KSR.jalanZigZag(MAJU,-65, 15, cepet);
          delay(cepet);  
        }
      }
      else{
        int depan = KSR.mata.depan.bacaJarak();
        while(abs(KSR.mata.kanan.bacaJarak() - depan) < 5){
          KSR.kaki.putar(KIRI,18);
          delay(lama);  
        }
        KSR.kaki.berdiri();
        state++;  
      }
      break;
//  lewati puing
    case 2:
      if(KSR.mata.depan.bacaJarak() > 23){
        KSR.jalanZigZag(MAJU, -45, 15, lama);
        delay(lama);
      }
      else{
        int depan = KSR.mata.depan.bacaJarak();
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI,18);
          delay(cepet);
        }
        KSR.kaki.berdiri();
        delay(lama);
        KSR.kaki.initPanjat();
        state++;  
      }
      break;
//  panjat bukit
    case 3:
      if(counterState == 0){
        for(int i = 0 ; i < 5; i ++){
          KSR.kaki.panjat(1);
          delay(lamabanget);
          KSR.kaki.panjat(2);
          delay(lamabanget);  
        }
        counterState++;   
      }
      else if(counterState >= 0){
        KSR.kaki.berdiri();  
        delay(20);
        KSR.jalanZigZag(MAJU,-45,15, lamabanget);  
        delay(lamabanget);
        counterState++;
      }
      else if(KSR.mata.belakang.bacaJarak() < 30){
        KSR.kaki.berdiri();  
        delay(sedang);
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI,18);
          delay(cepet);
        }
        counterState = 0;
        state++;
      }
      else{
        for(int i = 0; i < 6; i++){
          KSR.kaki.putar(KANAN, 18);  
        }
      }
      break;  
//  jalan belok ke tikungan ruang 1  
    case 4:
      if(KSR.mata.depan.bacaJarak() > 35){
        KSR.jalanZigZag(MAJU, -65, 15, cepet);
        delay(cepet);
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI,18);
          delay(cepet);
        }
        KSR.kaki.berdiri();
        state++;  
      }
      break;  
//  masuk ruang 1
    case 5:
      if(KSR.mata.depan.bacaJarak() > 35){
        KSR.jalanZigZag(MAJU, -45, 15, lama);
        delay(lama);
      }
      else if(abs(KSR.mata.kanan.bacaJarak() - KSR.mata.kiri.bacaJarak()) > 5 ){
        KSR.kaki.jalanSamping(KANAN);
        delay(sedang);
      }
      else if(abs(KSR.mata.kiri.bacaJarak() - KSR.mata.kanan.bacaJarak()) > 5 ){
        KSR.kaki.jalanSamping(KIRI);
        delay(sedang);
      }
      else{
        if(KSR.pemadam.cekApi(1) > KSR.pemadam.cekApi(5)){
          KSR.kaki.putar(KIRI,18);  
          delay(cepet);
        }
        else if(KSR.pemadam.cekApi(5) > KSR.pemadam.cekApi(1)){
          KSR.kaki.putar(KANAN,18);  
          delay(cepet);
        }
        else{
          state++;    
        }
      }
      break;
//  padam api  
    case 6:
      if(KSR.pemadam.cekApi(3)){
        KSR.pemadam.semprot(HIGH);
        delay(cepet);  
        KSR.kaki.putar(KIRI);
        delay(cepet);  
        KSR.kaki.putar(KANAN);
        delay(cepet);  
        KSR.kaki.putar(KANAN);
        delay(cepet);  
        KSR.kaki.putar(KIRI);
        delay(cepet);  
      }
      else{
        KSR.capit.taruh();
        delay(cepet);
        KSR.capit.turun();
        delay(cepet);
        state++;  
      }
      break;
//  cari korban  
    case 7:
      if(KSR.mata.kiri.bacaJarak() > 25 ){
        KSR.kaki.jalanSamping(KIRI);
        delay(sedang);
      }
      else if(KSR.capit.mata.bacaJarak() < 10){
        state++;
        break;
      }
      else if(KSR.mata.kanan.bacaJarak() > 25 ){
        KSR.kaki.jalanSamping(KANAN);
        delay(sedang);
      }
      else if(KSR.capit.mata.bacaJarak() < 10){
        state++;
        break;
      }
      break;
//  angkat korban  
    case 8:
      KSR.capit.turun();
      delay(cepet);
      KSR.capit.taruh();
      delay(cepet);
      KSR.kaki.jalan(MAJU, -65, 15, cepet );
      delay(cepet);
      KSR.kaki.jalan(MAJU, -65, 15, cepet );
      delay(cepet);
      KSR.capit.ambil();
      delay(sedang);
      KSR.capit.naik();
      delay(sedang);
      state++;
      break;
//  ke safe zone  
    case 9:
      if(KSR.mata.belakang.bacaJarak() > 35){
        KSR.jalanZigZag( MUNDUR, -45, 15, sedang);
      }
      else{
        for(int i = 0; i < 6; i++){
          KSR.kaki.putar(KANAN);
          delay(cepet);  
        }  
        KSR.capit.turun();
        delay(sedang);
        KSR.capit.taruh();
        delay(sedang);
        KSR.capit.naik();
        delay(sedang);
        state++;
      }
      break;
//  mundur dari safe zone
    case 10:
      if(KSR.mata.depan.bacaJarak() <= 35){
        KSR.kaki.jalan(MUNDUR, -65, 15, cepet);
        delay(cepet);
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(cepet);  
        }
        state++;  
      }
      break;
//  ke tikungan home  
    case 11:
      if(KSR.mata.depan.bacaJarak() > 23){
        KSR.jalanZigZag(MAJU, -65, 15, cepet);
        delay(cepet);
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        state++;  
      }
      break;  
//  kembali ke home
    case 12:
      if(abs(KSR.mata.depan.bacaJarak() - KSR.mata.belakang.bacaJarak()) > 5 ){
        KSR.jalanZigZag(MAJU, -65, 15, cepet);
        delay(cepet);
      }
      else{
        KSR.kaki.berdiri();
        state = 0;  
      }
      
      break;
  }
}

void loopAA(){
  switch(state){
//  jalan dari home
    case 1:
      if(langkah < 20 || KSR.mata.depan.bacaJarak() > 23){
        KSR.jalanZigZag(MAJU, -65, 15, cepet);
        langkah++;
        delay(cepet);
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI,14);
          delay(lama);  
        }
        KSR.kaki.berdiri();
        state++;  
        langkah = 0;
        counterState=0;
      }
      break;
//  lewati puing
    case 2:
      if(langkah < 20 || KSR.mata.depan.bacaJarak() > 23){
        KSR.jalanZigZag(MAJU, -35, 15, cepet);
        langkah++;
        delay(cepet);
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        KSR.kaki.berdiri();
        delay(lama);
        KSR.kaki.initPanjat();
        state++;  
        langkah = 0;
        counterState=0;
      }
      break;
//  panjat bukit
    case 3:
      if(counterState == 0 ){
//        for(int i = 0 ; i < 5; i ++){
        KSR.kaki.panjat(1);
        delay(lamabanget);
        KSR.kaki.panjat(2);
        delay(lamabanget);  
//        }  
        langkah++;
        if(langkah > 5){
          langkah = 0;
          counterState = 1;
          KSR.kaki.berdiri();
        }
      }
      else if(counterState == 1 && langkah < 20){
        KSR.jalanZigZag(MAJU, -45, 15, lama);
        delay(lama);
        
        langkah++;
        if(langkah >= 20) counterState++;
      }
      else {
        KSR.kaki.berdiri();  
        delay(sedang);
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        counterState = 0;
        langkah=0;
        state++;
      }
      break;  
//  jalan belok ke tikungan ruang 1  
    case 4:
      if(langkah < 10 || KSR.mata.depan.bacaJarak() > 65){
        KSR.jalanZigZag(MAJU,-65, 15, cepet);
        delay(cepet);
        langkah++;
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI,18);
          delay(cepet);  
        }
        KSR.kaki.berdiri();
        state++;  
        langkah = 0;
        counterState=0;
      }
      break;  
//  masuk ruang 1
    case 5:
      if((langkah < 15 && counterState == 0) || (KSR.mata.depan.bacaJarak() > 28 && counterState == 0)){
        KSR.jalanZigZag(MAJU,-45,15,cepet);
        delay(cepet);
        langkah++;
        if(langkah >= 30){
          counterState++;
          langkah = 0;  
        }
      }
      else if(counterState == 1 && KSR.pemadam.cekApi(1) > KSR.pemadam.cekApi(5)){
        KSR.kaki.jalanSamping(KANAN);
        delay(sedang);
        counterState++;
      }
      else if(counterState == 1 && KSR.pemadam.cekApi(1) < KSR.pemadam.cekApi(5)){
        KSR.kaki.jalanSamping(KIRI);
        delay(sedang);
        counterState++;
      }
      else{
        state++;  
        langkah = 0;
        counterState=0;
      }
      break;
//  padam api  
    case 6:
      if(KSR.pemadam.cekApi(3)){
        KSR.pemadam.semprot(HIGH);
        delay(cepet);  
        KSR.kaki.putar(KIRI);
        delay(cepet);  
        KSR.kaki.putar(KANAN);
        delay(cepet);  
        KSR.kaki.putar(KANAN);
        delay(cepet);  
        KSR.kaki.putar(KIRI);
        delay(cepet);  
        KSR.pemadam.semprot(LOW);
      }
      else{
        state++;  
        langkah = 0;
        counterState=0;
      }
      break;
//  cari korban  
    case 7:
      KSR.kaki.jalanSamping(KANAN);
      delay(sedang);
      state++;
//      if(langkah < 1 && counterState == 0){
//        KSR.kaki.jalanSamping(KANAN);
//        delay(sedang);
//        langkah++;
//        if(langkah >= 1) counterState ++;
//      }
//      else{
//        state++;
//        langkah = 0;
//        counterState=0;
//      }
      break;
//  angkat korban  
    case 8:
      KSR.capit.turun();
      KSR.capit.taruh();
      delay(sedang);
      KSR.jalanLangkah(2);
      delay(sedang);
      KSR.capit.ambil();
      delay(sedang);
      KSR.capit.naik();
      delay(sedang);
      state++;
      langkah = 0;
      counterState=0;
      break;
//  ke safe zone  
    case 9:
      if(langkah < 30 && counterState == 0 ){
        KSR.jalanZigZag( MUNDUR, -45, 15, cepet);
        delay(cepet);
        langkah++;
        if(langkah >= 65) counterState++;
      }
      else{
        for(int i = 0; i < 8; i++){
          KSR.kaki.putar(KANAN);
          delay(lama);  
        }  
        KSR.capit.turun();
        delay(lama);
        KSR.capit.taruh();
        delay(lama);
        KSR.capit.naik();
        delay(lama);
        state++;
        langkah = 0;
        counterState=0;
      }
      break;
//  mundur dari safe zone
    case 10:
      if(langkah < 2 && counterState == 0){
        KSR.jalanZigZag(MUNDUR);
        delay(cepet);
        if(langkah > 2) counterState++;
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(cepet);  
        }
        state++;  
        langkah=0;
        counterState = 0;
      }
      break;
//  ke tikungan home  
    case 11:
      if(langkah < 10 && counterState == 0){
        KSR.jalanZigZag(MAJU);
        delay(cepet);
        langkah++;
        if(langkah >= 10 ) counterState++;
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        state++;  
        langkah=0;
        counterState = 0;
      }
      break;  
//  kembali ke home
    case 12:
      if(langkah < 10 && counterState == 0){
        KSR.jalanZigZag(MAJU);
        langkah++;
        if(langkah >= 10)counterState++; 
      }
      else{
        KSR.kaki.berdiri();
        langkah = 0;
        counterState=0;
      }
      
      break;
  }
}
