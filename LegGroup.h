#include "header.h"
#include "Leg.h"

class LegGroup{
  private:
    Leg LF; // kiri depan
    Leg LM; // kiri tengah
    Leg LB; // kiri belakang
    Leg RF; // kanan depan
    Leg RM; // kanan tengah
    Leg RB; // kanan belakang
  public :
    LegGroup(){
      LF = Leg(1,2,3);
      LM = Leg(4,5,6);
      LB = Leg(7,8,9);
      RF = Leg(10,11,12);
      RM = Leg(13,14,15);
      RB = Leg(16,17,18);
    }
    void init(){
      LF.init();
      LM.init();
      LB.init();
      RF.init();
      RM.init();
      RB.init();
    }
    void stand(){
      LF.stand();
      LM.stand();
      LB.stand();
      RF.stand();
      RM.stand();
      RB.stand();
    }
    void walk(int dir){
      LF.walk(dir);
      LM.walk(dir);
      LB.walk(dir);
      RF.walk(dir);
      RM.walk(dir);
      RB.walk(dir);
    }
};
