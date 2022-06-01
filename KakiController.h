#include "Kaki.h"

#define SUDUTJALAN 20
#define SUDUTPUTAR 18


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

    void initPanjat(){
      LF.berdiri();
      LM.moveDeg({15 * LM.pos ,0,-90});
      LB.berdiri();
      RF.berdiri();
      RM.moveDeg({15 * RM.pos ,0,-90});
      RB.berdiri();
    }
    
    void berdiri(){
      LF.berdiri();
      LM.berdiri();
      LB.berdiri();
      RF.berdiri();
      RM.berdiri();
      RB.berdiri();
    }

    void putar(int dir){
      LF.moveDeg({-1 * SUDUTPUTAR * LF.pos * dir,0,-90});
      RM.moveDeg({SUDUTPUTAR * RM.pos * dir,0,-90});
      LB.moveDeg({-1 * SUDUTPUTAR * LB.pos * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-1 * SUDUTPUTAR * RF.pos * dir,0,-45});
      LM.moveDeg({SUDUTPUTAR * LM.pos * dir,0,-45});
      RB.moveDeg({-1 * SUDUTPUTAR * RB.pos * dir,0,-45});
      delay(sedang);

      LF.moveDeg({SUDUTPUTAR * LF.pos * dir,0,-90});
      RM.moveDeg({-1 * SUDUTPUTAR * RM.pos * dir,0,-90});
      LB.moveDeg({SUDUTPUTAR * LB.pos * dir,0,-90});
      delay(sedang);
      RF.moveDeg({SUDUTPUTAR * RF.pos * dir,0,-45});
      LM.moveDeg({-1 * SUDUTPUTAR * LM.pos * dir,0,-45});
      RB.moveDeg({SUDUTPUTAR * RB.pos * dir,0,-45});
      delay(sedang);
      
      RF.moveDeg({SUDUTPUTAR * RF.pos * dir,0,-90});
      LM.moveDeg({-1 * SUDUTPUTAR * LM.pos * dir,0,-90});
      RB.moveDeg({SUDUTPUTAR * RB.pos * dir,0,-90});
      delay(sedang);
      LF.moveDeg({SUDUTPUTAR * LF.pos * dir,0,-45});
      RM.moveDeg({-1 * SUDUTPUTAR * RM.pos * dir,0,-45});
      LB.moveDeg({SUDUTPUTAR * LB.pos * dir,0,-45});
      delay(sedang); 
      
      RF.moveDeg({-1 * SUDUTPUTAR * RF.pos * dir,0,-90});
      LM.moveDeg({SUDUTPUTAR * LM.pos * dir,0,-90});
      RB.moveDeg({-1 * SUDUTPUTAR * RB.pos * dir,0,-90});
      delay(sedang);
      LF.moveDeg({-1 * SUDUTPUTAR * LF.pos * dir,0,-45});
      RM.moveDeg({SUDUTPUTAR * RM.pos * dir,0,-45});
      LB.moveDeg({-1 * SUDUTPUTAR * LB.pos * dir,0,-45});
      delay(sedang);
    }

    void initPanjatDua(){
      RB.moveDeg({-45 * RB.pos ,0,-60});
      LB.moveDeg({-45 * LB.pos ,0,-60});
      delay(sedang);

      RF.moveDeg({45 * RF.pos ,0,-30});
      LF.moveDeg({45 * LF.pos ,0,-30});
      delay(sedang);

      RM.moveDeg({30 * RM.pos ,0,-90});
      LM.moveDeg({30 * LM.pos ,0,-90});
      delay(sedang);

    }

    void panjatDua(int urut){
      RM.moveDeg({-30 * RM.pos ,0,-90});
      LM.moveDeg({-30 * LM.pos ,0,-90});
      delay(lama);

      RF.moveDeg({45 * RF.pos ,0,-60});
      LF.moveDeg({45 * LF.pos ,0,-60});
      delay(lama);

      if(urut ==1){
        RM.moveDeg({-30 * RM.pos ,0,0});
        delay(lamabanget);
        RM.moveDeg({30 * RM.pos ,0,0});
        delay(lamabanget);
        RM.moveDeg({30 * RM.pos ,0,-90});
        delay(lamabanget);
  
        LM.moveDeg({-30 * LM.pos ,0,0});
        delay(lamabanget);
        LM.moveDeg({30 * LM.pos ,0,0});
        delay(lamabanget);
        LM.moveDeg({30 * LM.pos ,0,-90});
        delay(lamabanget);
      }
      else{
        LM.moveDeg({-30 * LM.pos ,0,0});
        delay(lamabanget);
        LM.moveDeg({30 * LM.pos ,0,0});
        delay(lamabanget);
        LM.moveDeg({30 * LM.pos ,0,-90});
        delay(lamabanget);
      
        RM.moveDeg({-30 * RM.pos ,0,0});
        delay(lamabanget);
        RM.moveDeg({30 * RM.pos ,0,0});
        delay(lamabanget);
        RM.moveDeg({30 * RM.pos ,0,-90});
        delay(lamabanget);
      }
      
      RF.moveDeg({45 * RF.pos ,0,-30});
      LF.moveDeg({45 * LF.pos ,0,-30});
      delay(lama);  
    }

    void jalan(int dir){
      LF.moveDeg({SUDUTJALAN * LF.pos * dir,0,-90});
      RM.moveDeg({SUDUTJALAN * RM.pos * dir,0,-90});
      LB.moveDeg({SUDUTJALAN * LB.pos * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-1 * SUDUTJALAN * RF.pos * dir,0,-45});
      LM.moveDeg({-1 * SUDUTJALAN * LM.pos * dir,0,-45});
      RB.moveDeg({-1 * SUDUTJALAN * RB.pos * dir,0,-45});
      delay(sedang);

      LF.moveDeg({-1 * SUDUTJALAN * LF.pos * dir,0,-90});
      RM.moveDeg({-1 * SUDUTJALAN * RM.pos * dir,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN * LB.pos * dir,0,-90});
      delay(sedang);
      RF.moveDeg({SUDUTJALAN * RF.pos * dir,0,-45});
      LM.moveDeg({SUDUTJALAN * LM.pos * dir,0,-45});
      RB.moveDeg({SUDUTJALAN * RB.pos * dir,0,-45});
      delay(sedang);

      RF.moveDeg({SUDUTJALAN * RF.pos * dir,0,-90});
      LM.moveDeg({SUDUTJALAN * LM.pos * dir,0,-90});
      RB.moveDeg({SUDUTJALAN * RB.pos * dir,0,-90});
      delay(sedang);
      LF.moveDeg({-1 * SUDUTJALAN * LF.pos * dir,0,-45});
      RM.moveDeg({-1 * SUDUTJALAN * RM.pos * dir,0,-45});
      LB.moveDeg({-1 * SUDUTJALAN * LB.pos * dir,0,-45});
      delay(sedang);
      
      RF.moveDeg({-1 * SUDUTJALAN * RF.pos * dir,0,-90});
      LM.moveDeg({-1 * SUDUTJALAN * LM.pos * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN * RB.pos * dir,0,-90});
      delay(sedang);
      LF.moveDeg({SUDUTJALAN * LF.pos * dir,0,-45});
      RM.moveDeg({SUDUTJALAN * RM.pos * dir,0,-45});
      LB.moveDeg({SUDUTJALAN * LB.pos * dir,0,-45});
      delay(sedang);
    }
    
    void panjatInit(int dir){
      LF.moveDeg({0 * LF.pos * dir,0,0});
      RF.moveDeg({0 * RF.pos * dir,0,0});
      delay(sedang);
      LF.moveDeg({30 * LF.pos * dir,0,0});
      RF.moveDeg({30 * RF.pos * dir,0,0});
      delay(lama);
      LF.moveDeg({30 * LF.pos * dir,0,-45});
      RF.moveDeg({30 * RF.pos * dir,0,-45});
      delay(sedang);
      
      LM.moveDeg({0 * LM.pos * dir,0,-90});
      RM.moveDeg({0 * RM.pos * dir,0,-90});
      LF.moveDeg({30 * LF.pos * dir,0,-90});
      RF.moveDeg({30 * RF.pos * dir,0,-90});
      delay(sedang);

      RM.moveDeg({0 * RM.pos * dir,0,-45});
      delay(sedang);
      LM.moveDeg({0 * LM.pos * dir,0,-45});
      delay(sedang);
    }

    void panjat(int dir){
      RF.moveDeg({0 * RF.pos * dir,0,-90});
      delay(sedang);
      RB.moveDeg({-45 * RB.pos * dir,0,-90});
      delay(sedang);

      LF.moveDeg({0 * LF.pos * dir,0,-90});
      delay(sedang);
      LB.moveDeg({-45 * LB.pos * dir,0,-90});
      delay(sedang);

      RF.moveDeg({0 * RF.pos * dir,0,0});
      delay(sedang);
      RF.moveDeg({45 * RF.pos * dir,0,0});
      delay(lama);
      RF.moveDeg({45 * RF.pos * dir,0,-90});
      delay(sedang);

      LF.moveDeg({0 * LF.pos * dir,0,0});
      delay(sedang);
      LF.moveDeg({45 * LF.pos * dir,0,0});
      delay(lama);
      LF.moveDeg({45 * LF.pos * dir,0,-90});
      delay(sedang);
      
//      RM.moveDeg({0 * RM.pos * dir,0,0});
//      delay(sedang);
//      RM.moveDeg({15 * RM.pos * dir,0,0});
//      delay(lama);
//      RM.moveDeg({15 * RM.pos * dir,0,-90});
//      delay(sedang);
//      RM.moveDeg({0 * RM.pos * dir,0,-90});
//      delay(sedang);
//
//      LM.moveDeg({0 * LM.pos * dir,0,0});
//      delay(sedang);
//      LM.moveDeg({15 * LM.pos * dir,0,0});
//      delay(lama);
//      LM.moveDeg({15 * LM.pos * dir,0,-90});
//      delay(sedang);
//      LM.moveDeg({0 * LM.pos * dir,0,-90});
//      delay(sedang);
      RM.moveDeg({0 * RM.pos * dir,0,-70});
      delay(sedang);
      RB.moveDeg({-45 * RB.pos * dir,0,-45});
      delay(sedang);
      RB.moveDeg({0 * RB.pos * dir,0,-45});
      delay(lama);
      RB.moveDeg({0 * RB.pos * dir,0,-90});
      delay(sedang);
      RM.moveDeg({0 * RM.pos * dir,0,-45});
      delay(sedang);

      LM.moveDeg({0 * LM.pos * dir,0,-70});
      delay(sedang);
      LB.moveDeg({-45 * LB.pos * dir,0,-45});
      delay(sedang);
      LB.moveDeg({0 * LB.pos * dir,0,-45});
      delay(lama);
      LB.moveDeg({0 * LB.pos * dir,0,-90});
      delay(sedang);
      LM.moveDeg({0 * LM.pos * dir,0,-45});
      delay(sedang);

      RF.moveDeg({0 * RF.pos * dir,0,-90});
      delay(sedang);
      LF.moveDeg({0 * LF.pos * dir,0,-90});
      delay(sedang);
      
      RB.moveDeg({-45 * RB.pos * dir,0,-90});
      delay(sedang);
      LB.moveDeg({-45 * LB.pos * dir,0,-90});
      delay(sedang);
    }

    void initKuda(){
      RF.moveDeg({45 * RF.pos ,0,-90});
      LF.moveDeg({45 * LF.pos ,0,-90});
      delay(sedang);  

      RB.moveDeg({-45 * RB.pos ,0,-90});
      LB.moveDeg({-45 * LB.pos ,0,-90});
      delay(sedang);  

      RM.moveDeg({0 * RM.pos ,0,-60});
      LM.moveDeg({0 * LM.pos ,0,-60});
      delay(sedang);  
    }
  
    void panjatKuda(int sudut){
      LF.moveDeg({sudut * LF.pos ,0,-90});
      RB.moveDeg({0 * RB.pos ,0,-45});
      delay(lama);
      RF.moveDeg({0 * RF.pos ,0,-15});
      LB.moveDeg({-1 * sudut * LB.pos ,0,0});
      delay(lama);

      LF.moveDeg({0 * LF.pos ,0,-90});
      RB.moveDeg({-1 * sudut * RB.pos ,0,-45});
      delay(lama);
      RF.moveDeg({sudut * RF.pos ,0,-15});
      LB.moveDeg({0 * LB.pos ,0,0});
      delay(lama);

      RF.moveDeg({sudut * RF.pos ,0,-90});
      LB.moveDeg({0 * LB.pos ,0,-45});
      delay(lama);
      LF.moveDeg({0 * LF.pos ,0,-15});
      RB.moveDeg({-1 * sudut * RB.pos ,0,0});
      delay(lama);
      
      RF.moveDeg({0 * RF.pos ,0,-90});
      LB.moveDeg({-1 * sudut * LB.pos ,0,-45});
      delay(lama);
      LF.moveDeg({sudut * LF.pos ,0,-15});
      RB.moveDeg({0 * RB.pos ,0,0});
      delay(lama);
    }

    void initPenyu(){
      RF.moveDeg({0 * RF.pos ,0,-90});
      LF.moveDeg({0 * LF.pos ,0,-90});
      RM.moveDeg({0 * RM.pos ,0,-45});
      LM.moveDeg({0 * LM.pos ,0,-45});
      RB.moveDeg({-45 * RB.pos ,0,-0});
      LB.moveDeg({-45 * LB.pos ,0,-0});
    }

    void panjatPenyu(){
      RF.moveDeg({0 * RF.pos ,0,0});
      delay(lama);
      RF.moveDeg({45 * RF.pos ,0,0});
      delay(lama);
      RF.moveDeg({45 * RF.pos ,0,-90});
      delay(lama);
      LF.moveDeg({0 * LF.pos ,0,0});
      delay(lama);
      LF.moveDeg({45 * LF.pos ,0,0});
      delay(lama);
      LF.moveDeg({45 * LF.pos ,0,-90});
      delay(lama);
     
      RM.moveDeg({-30 * RM.pos ,0,0});
      LM.moveDeg({-30 * LM.pos ,0,0});
      delay(lama);
      RM.moveDeg({30 * RM.pos ,0,0});
      LM.moveDeg({30 * LM.pos ,0,0});
      delay(lama);
      RM.moveDeg({30 * RM.pos ,0,-45});
      LM.moveDeg({30 * LM.pos ,0,-45});
      delay(lama);
      RM.moveDeg({30 * RM.pos ,0,-90});
      LM.moveDeg({30 * LM.pos ,0,-90});
      delay(lama);
      RM.moveDeg({-30 * RM.pos ,0,-90});
      LM.moveDeg({-30 * LM.pos ,0,-90});
      delay(lama);
      RM.moveDeg({-30 * RM.pos ,0,-45});
      LM.moveDeg({-30 * LM.pos ,0,-45});
      delay(lama);
      delay(500);

      RF.moveDeg({0 * RF.pos ,0,-90});
      LF.moveDeg({0 * LF.pos ,0,-90});
      delay(lama);
    }

    void jalanTest(int dir){
      vec3_t P1 = {-30,0,0};
      vec3_t tinggi = {0,0,60};
      vec3_t P4 = {30,0,0};

      ArduinoQueue<vec3_t> steps = trajectory(
          standPoint + P1 * dir,
          standPoint + tinggi + P1 * dir,
          standPoint + tinggi + P4 * dir,
          standPoint + P4 * dir,0.5
      );
      ArduinoQueue<vec3_t> backSteps = trajectory(
          standPoint + P4 * dir,
          standPoint + P4 * dir,
          standPoint + P1 * dir,
          standPoint + P1 * dir,0.5
      );
      
      while(!steps.isEmpty() && !backSteps.isEmpty()){
          
          vec3_t sTemp = steps.dequeue();
          vec3_t bTemp = backSteps.dequeue();

          RF.moveDeg({sTemp.x * RF.pos, sTemp.y,sTemp.z });
          delay(20);
          LM.moveDeg({sTemp.x * LM.pos, sTemp.y,sTemp.z });
          delay(20);
          RB.moveDeg({sTemp.x * RB.pos, sTemp.y,sTemp.z });
          delay(20);
          LF.moveDeg({bTemp.x * LF.pos, bTemp.y,bTemp.z });
          delay(20);
          RM.moveDeg({bTemp.x * RM.pos, bTemp.y,bTemp.z });
          delay(20);
          LB.moveDeg({bTemp.x * LB.pos, bTemp.y,bTemp.z });
          delay(20);
          delay(lama);
      }

      backSteps = trajectory(
          standPoint + P1 * dir,
          standPoint + tinggi + P1 * dir,
          standPoint + tinggi + P4 * dir,
          standPoint + P4 * dir,0.5
      );
      steps = trajectory(
          standPoint + P4 * dir,
          standPoint + P4 * dir,
          standPoint +  P1 * dir,
          standPoint + P1 * dir,0.5
      );
      
      while(!steps.isEmpty() && !backSteps.isEmpty()){
          vec3_t sTemp = steps.dequeue();
          vec3_t bTemp = backSteps.dequeue();
       
          RF.moveDeg({sTemp.x * RF.pos, sTemp.y,sTemp.z });
          delay(20);
          LM.moveDeg({sTemp.x * LM.pos, sTemp.y,sTemp.z });
          delay(20);
          RB.moveDeg({sTemp.x * RB.pos, sTemp.y,sTemp.z });
          delay(20);
          LF.moveDeg({bTemp.x * LF.pos, bTemp.y,bTemp.z });
          delay(20);
          RM.moveDeg({bTemp.x * RM.pos, bTemp.y,bTemp.z });
          delay(20);
          LB.moveDeg({bTemp.x * LB.pos, bTemp.y,bTemp.z });
          delay(20);
          delay(lama);
      }
      
    }

    ArduinoQueue<vec3_t> trajectory(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
        ArduinoQueue<vec3_t> result(1/t + 3);
        float mult = t;
        result.enqueue(P1);
        while(t<1){
            vec3_t Pt = pow(1-t,3) * P1 + 3*t*pow(1-t,2) * P2 + 3*t*t*(1-t) * P3 + pow(t,3) * P4;
            result.enqueue(Pt);
            t += mult;
        }
        result.enqueue(P4);
        return result;
    }
};
