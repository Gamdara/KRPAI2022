//#include "header.h"
//
//SensorGarisController IR;
//SensorJarakController mata;
////Kompas kompas;
//PemadamApi api;
//Capit capit;
////SensorJarak sj;
//
//void setup(){
//    Serial.begin(9600);
//    pinMode(7, INPUT);
//  
//    mata.init();
//    capit.init();
//    IR.init();
//    api.init();
////  pinMode(34, INPUT);
//    Serial.print("masuk");
////  kompas.init();
////  Serial.print("masuk");
//}
//
////
//void loop(){
////    if(digitalRead(7) == ) return;
//    Serial.print("Button "); 
//    Serial.println(digitalRead(7));
//    Serial.print("Garis ");
////    Serial.print("Garis ");
////    Serial.println(digitalRead(3));
//    Serial.println(IR.belakang.cekGaris());
//    if(IR.belakang.cekGaris()) capit.ambil();
//    else capit.taruh();
////    Serial.print("Hitam ");
////    Serial.println(IR.belakang.jumlahHitam());
////    Serial.print("Putih ");
////    Serial.println(IR.belakang.jumlahPutih());
////    Serial.println(" ");
//    
////  Serial.print("Kompas ");
////  Serial.println(kompas.getDirection());  
////  Serial.print(" ");
//  
//  Serial.print("Depan ");
//  Serial.println(mata.depan.bacaJarak());
//  Serial.print("Kiri ");
//  Serial.println(mata.kiri.bacaJarak());
//  Serial.print("Kanan ");
//  Serial.println(mata.kanan.bacaJarak());
//  Serial.print("Belakang ");
//  Serial.println(mata.belakang.bacaJarak());
//  Serial.print("Capit ");
//  Serial.println(capit.mata.bacaJarak());
//  Serial.println("");
//  
//  delay(1000);
//
//  Serial.print("1 ");
//  Serial.println(api.cekApi(1));
//  Serial.print("2 ");
//  Serial.println(api.cekApi(2));
//  Serial.print("3 ");
//  Serial.println(api.cekApi(3));
//  Serial.print("4 ");
//  Serial.println(api.cekApi(4));
//  Serial.print("5 ");
//  Serial.println(api.cekApi(5));
//  Serial.println("");
////  delay(1000);
//}
