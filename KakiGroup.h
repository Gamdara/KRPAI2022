#include "Kaki.h"

float t = 0.1;

class KakiGroup{
  private:
    Kaki LF; // kiri depan
    Kaki LM; // kiri tengah
    Kaki LB; // kiri belakang
    Kaki RF; // kanan depan
    Kaki RM; // kanan tengah
    Kaki RB; // kanan belakang
    vec3_t standPoint; //titik berdiri semut

  public :
    KakiGroup(){
      LF = Kaki(1,2,3, KIRI, GRUP2, DEPAN);
      LM = Kaki(4,5,6, KIRI, GRUP1, TENGAH);
      LB = Kaki(7,8,9, KIRI, GRUP2, BELAKANG);
      RF = Kaki(10,11,12, KANAN, GRUP1, DEPAN);
      RM = Kaki(13,14,15, KANAN, GRUP2, TENGAH);
      RB = Kaki(16,17,18, KANAN, GRUP1, BELAKANG);
      this->standPoint = {0,-10,4};
      
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

    void langkah(ArduinoQueue<vec3_t> stepsMaju, ArduinoQueue<vec3_t> stepsMundur){
      while(!stepsMaju.isEmpty() || !stepsMundur.isEmpty() ){
        vec3_t tempMaju = stepsMaju.dequeue();
        vec3_t tempMundur = stepsMundur.dequeue();
            
        LF.langkah(tempMaju,tempMundur);
        RM.langkah(tempMaju,tempMundur);
        LB.langkah(tempMaju,tempMundur);
        RF.langkah(tempMaju,tempMundur);
        LM.langkah(tempMaju,tempMundur);
        RB.langkah(tempMaju,tempMundur);
      }
    }

    void jalan(int dir){
      vec3_t tinggi = {0,3,0};

      vec3_t P1 = {-2,0,0};
      vec3_t P4 = {2,0,0};
      P1 = standPoint + P1 * dir;
      P4 = standPoint + P4 * dir;
  
      vec3_t P2 = tinggi + P1;
      vec3_t P3 = tinggi + P4;
      
      ArduinoQueue<vec3_t> stepsMaju = trajectory(P1,P2,P3,P4,t);
      ArduinoQueue<vec3_t> stepsMundur = trajectory(P4,P4,P1,P1,t);
      
      langkah(stepsMaju, stepsMundur);
      delay(200);
      langkah(stepsMundur, stepsMaju);
    }

    void jalanSamping(int dir){
        vec3_t tinggi = {0,1,0};
        vec3_t P1 = {0,0,1};
        vec3_t P4 = {0,0,-1};
        P1 = standPoint + P1 * dir;
        P4 = standPoint + P4 * dir;

        vec3_t P2 = tinggi + P1;
        vec3_t P3 = tinggi + P4;
        
        ArduinoQueue<vec3_t> stepsMaju = trajectory(P1,P2,P3,P4,t);
        ArduinoQueue<vec3_t> stepsMundur = trajectory(P4,P4,P1,P1,t);
        
        langkah(stepsMaju, stepsMundur);
        delay(200);
        langkah(stepsMundur, stepsMaju);
    }

    void putar(float deg,int dir){
      vec3_t target = standPoint;
      vec3_t P1 = rotateMatrix(target, deg * dir);
      vec3_t P4 = rotateMatrix(target, deg *-1 * dir);
      vec3_t tinggi = {0,3,0};
      vec3_t titikBantu = {0,3,target.z-target.z};
      
      ArduinoQueue<vec3_t> stepsMaju = trajectory(P1,P1 + titikBantu + tinggi,P4 + titikBantu + tinggi,P4,t);
      ArduinoQueue<vec3_t> stepsMundur = trajectory(P4,P4 + titikBantu,P1 + titikBantu,P1,t);

      langkah(stepsMaju, stepsMundur);
      delay(200);
      langkah(stepsMundur, stepsMaju);
    }
};
