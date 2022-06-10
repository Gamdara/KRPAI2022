#include "SensorJarak.h"

class SensorJarakController{
    public:
    SensorJarak depan;
    SensorJarak belakang;
    SensorJarak kiri;
    SensorJarak kanan;
    
    SensorJarakController(){
        depan = SensorJarak(4,8);
        belakang = SensorJarak(6,10);
        kiri = SensorJarak(7,11);
        kanan  = SensorJarak(5,9);
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

    float bacaDiagonal(int dir){
      int de = depan.bacaJarak();
      int k = 0;
      if(dir == KANAN)
      k = kanan.bacaJarak();
      else
      k = kiri.bacaJarak();
      
      float a = sqrt(pow(de,2) + pow(k,2) );
      float m = k / (k + de) * a;
      float n = de / (k + de) * a;
      
      float d = sqrt((de*k) - (m*n));
      return d;
    }
};
