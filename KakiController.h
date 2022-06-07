#include "Kaki.h"

class KakiController{
  private:
    Kaki LF; // kiri depan
    Kaki LM; // kiri tengah
    Kaki LB; // kiri belakang
    Kaki RF; // kanan depan
    Kaki RM; // kanan tengah
    Kaki RB; // kanan belakang
    vec3_t standPoint;
    
  public :
    KakiController(){

      RF = Kaki(1,2, 1,1,1);
      RM = Kaki(3,4, 1,-1,2);
      RB = Kaki(6,5, 1,1,3);
      
      LF = Kaki(11,12, -1,-1,1);
      LM = Kaki(9,10, -1,1,2);
      LB = Kaki(7,8, -1,-1,3);
      this->standPoint = {0, 0, -90};  
    }
    
    void init(){
      LF.init();
      LM.init();
      LB.init();
      RF.init();
      RM.init();
      RB.init();
    }

    void initPiramid(){
      LF.moveDeg({-45 ,0,-60});
      LM.moveDeg({0 ,0,-85});
      LB.moveDeg({30 ,0,-60});
      RF.moveDeg({-45 ,0,-60});
      RM.moveDeg({0,0,-85});
      RB.moveDeg({30 ,0,-60});
    }

    void naikPiramid(int dir){
      LF.moveDeg({-45 * dir,0,-40});
      delay(lama);
      LF.moveDeg({-30 * dir,0,-40});
      delay(lama);
      LF.moveDeg({-30 * dir,0,-60});
      delay(lamabanget);

      RF.moveDeg({-45 * dir,0,-40});
      delay(lama);
      RF.moveDeg({-30 * dir,0,-40});
      delay(lama);
      RF.moveDeg({-30 * dir,0,-60});
      delay(lamabanget);

      LB.moveDeg({30 * dir,0,-40});
      delay(lama);
      LB.moveDeg({45 * dir,0,-40});
      delay(lama);
      LB.moveDeg({45 * dir,0,-60});
      delay(lamabanget);

      RB.moveDeg({30 * dir,0,-40});
      delay(lama);
      RB.moveDeg({45 * dir,0,-40});
      delay(lama);
      RB.moveDeg({45 * dir,0,-60});
      delay(lamabanget);

      initPiramid();
    }

    void initPrePiramid(){
      LF.moveDeg({-45 ,0,-90});
      LM.moveDeg({0 ,0,-90});
      LB.moveDeg({30 ,0,-90});
      RF.moveDeg({-45 ,0,-90});
      RM.moveDeg({0,0,-90});
      RB.moveDeg({30 ,0,-90});
    }

    void naikPrePiramid(int dir){
      LF.moveDeg({-15  * dir,0,-90});
      RM.moveDeg({0  * dir,0,-90});
      LB.moveDeg({45  * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-45  * dir,0,-45});
      LM.moveDeg({0  * dir,0,-45});
      RB.moveDeg({30  * dir,0,-45});
      delay(sedang);

      LF.moveDeg({-45  * dir,0,-90});
      RM.moveDeg({0  * dir,0,-90});
      LB.moveDeg({30  * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-15  * dir,0,-45});
      LM.moveDeg({0  * dir,0,-45});
      RB.moveDeg({45  * dir,0,-45});
      delay(sedang);

      RF.moveDeg({-15  * dir,0,-90});
      LM.moveDeg({0  * dir,0,-90});
      RB.moveDeg({45  * dir,0,-90});
      delay(sedang);
      LF.moveDeg({-45  * dir,0,-45});
      RM.moveDeg({0  * dir,0,-45});
      LB.moveDeg({30  * dir,0,-45});
      delay(sedang);
      
      RF.moveDeg({-45  * dir,0,-90});
      LM.moveDeg({0  * dir,0,-90});
      RB.moveDeg({30  * dir,0,-90});
      delay(sedang);
      LF.moveDeg({-15  * dir,0,-45});
      RM.moveDeg({0  * dir,0,-45});
      LB.moveDeg({45  * dir,0,-45});
      delay(sedang);
    }

    void initSamping(){
      LF.berdiri();
      LM.moveDeg({0,0,-65});
      LB.berdiri();
      RF.berdiri();
      RM.moveDeg({0,0,-65});
      RB.berdiri();  
    }

    void jalanSamping(int dir, int SUDUTJALAN = 15){
      LF.moveDeg({-1 * SUDUTJALAN * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN * dir,0,-90});
      delay(sedang);
      RF.moveDeg({SUDUTJALAN * dir * -1,0,-65});
      LB.moveDeg({SUDUTJALAN * dir * -1,0,-65});
      delay(sedang);

      RF.moveDeg({SUDUTJALAN * dir * -1,0,-90});
      LB.moveDeg({SUDUTJALAN * dir * -1,0,-90});
      delay(sedang);
      LF.moveDeg({-1 * SUDUTJALAN * dir,0,-65});
      RB.moveDeg({-1 * SUDUTJALAN * dir,0,-65});
      delay(sedang);
      
      RF.moveDeg({-1 * SUDUTJALAN * dir * -1,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN * dir * -1,0,-90});
      delay(sedang);
      LF.moveDeg({SUDUTJALAN * dir,0,-65});
      RB.moveDeg({SUDUTJALAN * dir,0,-65});
      delay(sedang);
      
      LF.moveDeg({SUDUTJALAN * dir,0,-90});
      RB.moveDeg({SUDUTJALAN * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-1 * SUDUTJALAN * dir * -1,0,-65});
      LB.moveDeg({-1 * SUDUTJALAN * dir * -1,0,-65});
      delay(sedang);  
    }
    
    void berdiri(){
      LF.berdiri();
      LM.berdiri();
      LB.berdiri();
      RF.berdiri();
      RM.berdiri();
      RB.berdiri();
    }

    void putar(int dir, int SUDUTPUTAR = SUDUTPUTAR30, int SUDUTNAIK = -65, int dile = cepet){
      LF.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      RM.moveDeg({SUDUTPUTAR  * dir,0,-90});
      LB.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      delay(dile);
      RF.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      LM.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      RB.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      delay(dile);

      LF.moveDeg({SUDUTPUTAR  * dir,0,-90});
      RM.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      LB.moveDeg({SUDUTPUTAR  * dir,0,-90});
      delay(dile);
      RF.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      LM.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      RB.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      delay(dile);
      
      RF.moveDeg({SUDUTPUTAR  * dir,0,-90});
      LM.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      RB.moveDeg({SUDUTPUTAR  * dir,0,-90});
      delay(dile);
      LF.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      RM.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      LB.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      delay(dile); 
      
      RF.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      LM.moveDeg({SUDUTPUTAR  * dir,0,-90});
      RB.moveDeg({-1 * SUDUTPUTAR  * dir,0,-90});
      delay(dile);
      LF.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      RM.moveDeg({SUDUTPUTAR  * dir,0,SUDUTNAIK});
      LB.moveDeg({-1 * SUDUTPUTAR  * dir,0,SUDUTNAIK});
      delay(dile);
    }

    void initTurun(){
      RF.moveDeg({45 ,0,-80});
      LF.moveDeg({45 ,0,-80});
      delay(sedang);

      RB.moveDeg({-45,0,-70});
      LB.moveDeg({-45,0,-70});
      delay(sedang);

      RM.moveDeg({30,0,-60});
      LM.moveDeg({30,0,-60});
      delay(sedang);
    }

    void turun(int urut){
      RM.moveDeg({-30,0,-60});
      LM.moveDeg({-30,0,-60});
      delay(lama);

      RB.moveDeg({-45,0,-60});
      LB.moveDeg({-45,0,-60});
      delay(lama);

      if(urut ==1){
        RM.moveDeg({-15  ,0,0});
        delay(lamabanget);
        RM.moveDeg({15  ,0,0});
        delay(lamabanget);
        RM.moveDeg({15  ,0,-60});
        delay(lamabanget);
  
        LM.moveDeg({-15  ,0,0});
        delay(lamabanget);
        LM.moveDeg({15  ,0,0});
        delay(lamabanget);
        LM.moveDeg({15  ,0,-60});
        delay(lamabanget);
      }
      else{
        LM.moveDeg({-15  ,0,0});
        delay(lamabanget);
        LM.moveDeg({15  ,0,0});
        delay(lamabanget);
        LM.moveDeg({15  ,0,-60});
        delay(lamabanget);
      
        RM.moveDeg({-15  ,0,0});
        delay(lamabanget);
        RM.moveDeg({15  ,0,0});
        delay(lamabanget);
        RM.moveDeg({15  ,0,-60});
        delay(lamabanget);
      }
      
      RB.moveDeg({-45  ,0,-40});
      LB.moveDeg({-45  ,0,-40});
      delay(lama);  
    }

    void initPanjat(){
      RB.moveDeg({-45 ,0,-45});
      LB.moveDeg({-45 ,0,-45});
      delay(lamabanget);

      RF.moveDeg({45,0,-25});
      LF.moveDeg({45,0,-25});
      delay(lamabanget);

      RM.moveDeg({30,0,-80});
      LM.moveDeg({30,0,-80});
      delay(lamabanget);
    }

    void panjat(int urut, bool ubah = false){
      RM.moveDeg({-30,0,-80});
      LM.moveDeg({-30,0,-80});
      delay(sedang);

      if(!ubah){
        RF.moveDeg({45,0,-45});
        LF.moveDeg({45,0,-45});
        delay(sedang);  
      }
      else{
        RF.moveDeg({45,0,-80});
        LF.moveDeg({45,0,-80});
        delay(sedang);  
      }
      

      if(urut ==1){
        RM.moveDeg({-30  ,0,0});
        delay(lamabanget);
        RM.moveDeg({30  ,0,0});
        delay(lamabanget);
        RM.moveDeg({30  ,0,-60});
        delay(lamabanget);
  
        LM.moveDeg({-30  ,0,0});
        delay(lamabanget);
        LM.moveDeg({30  ,0,0});
        delay(lamabanget);
        LM.moveDeg({30  ,0,-60});
        delay(lamabanget);
      }
      else{
        LM.moveDeg({-30  ,0,0});
        delay(lamabanget);
        LM.moveDeg({30  ,0,0});
        delay(lamabanget);
        LM.moveDeg({30  ,0,-60});
        delay(lamabanget);
      
        RM.moveDeg({-30  ,0,0});
        delay(lamabanget);
        RM.moveDeg({30  ,0,0});
        delay(lamabanget);
        RM.moveDeg({30  ,0,-60});
        delay(lamabanget);
      }
      
      RF.moveDeg({45  ,0,-25});
      LF.moveDeg({45  ,0,-25});
      delay(cepet);  
    }

    void jalan(int dir, int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF, int dile = sedang){
      LF.moveDeg({SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      RF.moveDeg({SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
      
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
    }

    void jalanKiri(int dir, int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF, int dile = sedang){
      RF.moveDeg({SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      LF.moveDeg({SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
      
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
    }

    void jalanPelan(int dir, int dile = sedang, int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF){
      LF.moveDeg({SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      RF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);

      RF.moveDeg({SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
      
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(dile);
      LF.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      RM.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      LB.moveDeg({SUDUTJALAN  * dir,0,SUDUTNAIK});
      delay(dile);
    }

};
