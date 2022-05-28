#include "Kaki.h"

class KakiGroup{
  private:
    Kaki LF; // kiri depan
    Kaki LM; // kiri tengah
    Kaki LB; // kiri belakang
    Kaki RF; // kanan depan
    Kaki RM; // kanan tengah
    Kaki RB; // kanan belakang
  public :
    KakiGroup(){
      LF = Kaki(1,2,3, -1,-1,1);
      LM = Kaki(4,5,6, -1,1,2);
      LB = Kaki(7,8,9, -1,-1,3);
      RF = Kaki(10,11,12, 1,1,1);
      RM = Kaki(13,14,15, 1,-1,2);
      RB = Kaki(16,17,18, 1,1,3);
    }
    
    void init(){
      LF.init();
      LM.init();
      LB.init();
      RF.init();
      RM.init();
      RB.init();
    }
    
    void berdiri(){
      LF.berdiri();
      LM.berdiri();
      LB.berdiri();
      RF.berdiri();
      RM.berdiri();
      RB.berdiri();
    }
    
    void berdiriSpread(){
      LF.berdiriSpread();
      LM.berdiriSpread();
      LB.berdiriSpread();
      RF.berdiriSpread();
      RM.berdiriSpread();
      RB.berdiriSpread();
    }
    
    void jalan(int dir){
      LF.jalan(dir);
      LM.jalan(dir);
      LB.jalan(dir);
      RF.jalan(dir);
      RM.jalan(dir);
      RB.jalan(dir);
    }

    void jalanSpread(int dir){
      LF.jalanSpread(dir);
      LM.jalanSpread(dir);
      LB.jalanSpread(dir);
      RF.jalanSpread(dir);
      RM.jalanSpread(dir);
      RB.jalanSpread(dir);
    }

    void putar(float deg,int dir){
      LF.putar(deg,dir);
      LM.putar(deg,dir);
      LB.putar(deg,dir);
      RF.putar(deg,dir);
      RM.putar(deg,dir);
      RB.putar(deg,dir);
    }
};
