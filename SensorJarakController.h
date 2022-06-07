#include "SensorJarak.h"

class SensorJarakController{
    public:
    SensorJarak depan;
    SensorJarak belakang;
    SensorJarak kiri;
    SensorJarak kanan;
    
    SensorJarakController(){
        depan = SensorJarak(5,9);
        belakang = SensorJarak(4,10);
        kiri = SensorJarak(6,8);
        kanan  = SensorJarak(3,11);
    }
    void init(){
        depan.init();
        belakang.init();
        kiri.init();
        kanan.init();
    }
    void resetNote(){
      depan.setNote(-1);
      belakang.setNote(-1);
      kanan.setNote(-1);
      kiri.setNote(-1);
    }
    void putar(int dir){
      int bTemp = belakang.note;
      int kaTemp = kanan.note;
      int kiTemp = kiri.note;
      int dTemp = depan.note;
      
      if(dir == KANAN){  
        belakang.setNote(kiri.note);
        depan.setNote(kanan.note);
        kiri.setNote(depan.note);
        kanan.setNote(belakang.note);
      }
      else{
        belakang.setNote(kanan.note);
        depan.setNote(kiri.note);
        kiri.setNote(belakang.note);
        kanan.setNote(depan.note);
      }
    }
};
