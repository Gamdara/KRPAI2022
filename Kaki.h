class Kaki{
  private:
    int coxaID;
    int thibiaID;
    

    vec3_t standPoint;
  public:
    int pos;
    int grup;
    int letak;
    
    Kaki(){}
    
    Kaki(int coxaID,int thibiaID, int pos, int grup, int letak){
      this->coxaID = coxaID;
      this->thibiaID = thibiaID; 
      this->pos = pos;
      this->grup = grup;
      this->letak = letak;
      
      if(letak == 1)
          this->standPoint = {0, 0, -90};
      else if(letak == 3)
          this->standPoint = {0, 0, -90};
      else 
          this->standPoint = {0, 0, -90};
      
    }

    void langkah(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
        ArduinoQueue<vec3_t> steps = trajectory(P1,P2,P3,P4,t);
        while(!steps.isEmpty()){
            vec3_t temp = steps.dequeue();
            temp.x *= this->pos;
            moveDeg(temp);
        }
    }
    
    void jalan(int dir){
        vec3_t P1 = {-15,0,0};
        vec3_t tinggi = {0,0,45};
        vec3_t P4 = {15,0,0};

        if(this->grup == 1){
            langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.3);
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.3);
        }
        else{
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.3);
            langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.3);
        }
    }

//    void putar(float deg, int dir){
//        vec3_t target = this->standPoint;
//        vec3_t fw = rotateMatrix(target, deg * dir);
//        vec3_t bw = rotateMatrix(target, deg *-1 * dir);
//        vec3_t tinggi = {0,4,0};
//        vec3_t titikBantu = {0,4,target.z-target.z};
//        
//        if(this->grup == 1){
//            langkah(fw,fw + titikBantu + tinggi,bw+ titikBantu + tinggi,bw,0.3);
//            delay(lamabanget);
//            langkah(bw,bw + titikBantu,fw+ titikBantu ,fw,0.3);
//        }
//        else{
//            langkah(bw,bw + titikBantu,fw+ titikBantu ,fw,0.3);
//            delay(lamabanget);
//            langkah(fw,fw + titikBantu + tinggi,bw+ titikBantu + tinggi,bw,0.3);
//        }
//    }

    void moveDeg(vec3_t target){
        ax12a.move(coxaID,mapServo(target.x) );
        delay(20);
        ax12a.move(thibiaID,mapServo(target.z));
        delay(20);
    }
    
    void init(){
        ax12a.move(coxaID,mapServo(0));
        delay(20);
        ax12a.move(thibiaID,mapServo(0));
        delay(20);
    }
    
    void berdiri(){
        moveDeg(standPoint);
    }

    int mapServo(int deg){
      return map(deg, 0, 150, 512, 0);
    }

    ArduinoQueue<vec3_t> trajectory(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
        ArduinoQueue<vec3_t> result(1/t + 3);
        float mult = t;
        result.enqueue(P1);
        while(t<1){
            vec3_t Pt = pow(1-t,3) * P1 + 3*t*pow(1-t,2) * P2 + 3*t*t*(1-t) * P3 + pow(t,3) * P4;
            result.enqueue(Pt);
            t += mult;
            Serial.print(Pt.x);
            Serial.print(" ");
            Serial.print(Pt.y);
            Serial.print(" ");
            Serial.print(Pt.z);
            Serial.println(" ");
        }
        result.enqueue(P4);
        return result;
    }
};
