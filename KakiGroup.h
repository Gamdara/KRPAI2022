#include "Kaki.h"

class KakiGroup{
  private:
    Kaki LF; // kiri depan
    Kaki LM; // kiri tengah
    Kaki LB; // kiri belakang
    Kaki RF; // kanan depan
    Kaki RM; // kanan tengah
    Kaki RB; // kanan belakang
    vec3_t standPoint;
    
  public :
    KakiGroup(){

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
    
    void berdiri(){
      LF.berdiri();
      LM.berdiri();
      LB.berdiri();
      RF.berdiri();
      RM.berdiri();
      RB.berdiri();
    }
    
    void jalan(int dir){
      RF.moveDeg({-30 * RF.pos * dir,0,-45});
      LM.moveDeg({-30 * LM.pos * dir,0,-45});
      RB.moveDeg({-30 * RB.pos * dir,0,-45});
      LF.moveDeg({30 * LF.pos * dir,0,-90});
      RM.moveDeg({30 * RM.pos * dir,0,-90});
      LB.moveDeg({30 * RB.pos * dir,0,-90});
      delay(100);
      RF.moveDeg({30 * RF.pos * dir,0,-45});
      LM.moveDeg({30 * LM.pos * dir,0,-45});
      RB.moveDeg({30 * RB.pos * dir,0,-45});
      LF.moveDeg({-30 * LF.pos * dir,0,-90});
      RM.moveDeg({-30 * RM.pos * dir,0,-90});
      LB.moveDeg({-30 * RB.pos * dir,0,-90});
      delay(100);
      RF.moveDeg({30 * RF.pos * dir,0,-90});
      LM.moveDeg({30 * LM.pos * dir,0,-90});
      RB.moveDeg({30 * RB.pos * dir,0,-90});
      LF.moveDeg({-30 * LF.pos * dir,0,-45});
      RM.moveDeg({-30 * RM.pos * dir,0,-45});
      LB.moveDeg({-30 * RB.pos * dir,0,-45});
      delay(100);
      RF.moveDeg({-30 * RF.pos * dir,0,-90});
      LM.moveDeg({-30 * LM.pos * dir,0,-90});
      RB.moveDeg({-30 * RB.pos * dir,0,-90});
      LF.moveDeg({30 * LF.pos * dir,0,-45});
      RM.moveDeg({30 * RM.pos * dir,0,-45});
      LB.moveDeg({30 * RB.pos * dir,0,-45});
      delay(100);
    }

    void putar(int dir){
      RF.moveDeg({-30 * RF.pos * dir,0,-45});
      LM.moveDeg({-30 * LM.pos * dir,0,-45});
      RB.moveDeg({-30 * RB.pos * dir,0,-45});
      LF.moveDeg({30 * LF.pos * dir,0,-90});
      RM.moveDeg({30 * RM.pos * dir,0,-90});
      LB.moveDeg({30 * RB.pos * dir,0,-90});
      delay(100);
      RF.moveDeg({30 * RF.pos * dir,0,-45});
      LM.moveDeg({30 * LM.pos * dir,0,-45});
      RB.moveDeg({30 * RB.pos * dir,0,-45});
      LF.moveDeg({-30 * LF.pos * dir,0,-90});
      RM.moveDeg({-30 * RM.pos * dir,0,-90});
      LB.moveDeg({-30 * RB.pos * dir,0,-90});
      delay(100);
      RF.moveDeg({30 * RF.pos * dir,0,-90});
      LM.moveDeg({30 * LM.pos * dir,0,-90});
      RB.moveDeg({30 * RB.pos * dir,0,-90});
      LF.moveDeg({-30 * LF.pos * dir,0,-45});
      RM.moveDeg({-30 * RM.pos * dir,0,-45});
      LB.moveDeg({-30 * RB.pos * dir,0,-45});
      delay(100);
      RF.moveDeg({-30 * RF.pos * dir,0,-90});
      LM.moveDeg({-30 * LM.pos * dir,0,-90});
      RB.moveDeg({-30 * RB.pos * dir,0,-90});
      LF.moveDeg({30 * LF.pos * dir,0,-45});
      RM.moveDeg({30 * RM.pos * dir,0,-45});
      LB.moveDeg({30 * RB.pos * dir,0,-45});
      delay(100);
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
          delay(100);
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
          delay(100);
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
