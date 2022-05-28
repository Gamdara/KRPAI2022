

class SensorJarak{
  private:
    int coxaID;
    int fermurID;
    int thibiaID;
    int pos;
    int grup;
    int letak;
    
    vec3_t standPoint;
    vec3_t standPointSpread;
    
  public:
    Leg(){}
    
    Leg(int coxaID,int fermurID, int thibiaID, int pos, int grup, int letak){
      this->coxaID = coxaID;
      this->fermurID = fermurID;
      this->thibiaID = thibiaID; 
      this->pos = pos;
      this->grup = grup;
      this->letak = letak;
      
      this->standPoint = {0,-8,10};
      
      if(letak == 1)
          this->standPointSpread = rotateMatrix(this->standPoint, -45 * this->pos);
      else if(letak == 3)
          this->standPointSpread = rotateMatrix(this->standPoint, 45 * this->pos);
      else 
          this->standPointSpread = this->standPoint;
      
    }

    void langkah(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
        ArduinoQueue<vec3_t> steps = trajectory(P1,P2,P3,P4,t);
        while(!steps.isEmpty()){
            vec3_t temp = steps.dequeue();
            temp.x *= this->pos;
            moveToPoint(temp);
            delay(150);
        }
    }
    
    void jalan(int dir){
        vec3_t P1 = {-4,0,0};
        vec3_t tinggi = {0,4,0};
        vec3_t P4 = {4,0,0};

        if(this->side == 1){
            langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.1);
            delay(500);
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.1);
        }
        else{
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.1);
            delay(500);
            langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.1);
        }
    }

    void jalanSpread(int dir){
        vec3_t P1 = {-4,0,0};
        vec3_t tinggi = {0,4,0};
        vec3_t P4 = {4,0,0};
        
        if(this->side == 1){
            langkah(standPointSpread + P1 * dir,standPointSpread + tinggi + P1 * dir,standPointSpread + tinggi + P4 * dir,standPointSpread + P4 * dir,0.1);
            delay(500);
            langkah(standPointSpread + P4 * dir,standPointSpread + P4 * dir,standPointSpread +  P1 * dir,standPointSpread + P1 * dir,0.1);
        }
        else{
            langkah(standPointSpread + P4 * dir,standPointSpread + P4 * dir,standPointSpread +  P1 * dir,standPointSpread + P1 * dir,0.1);
            delay(500);
            langkah(standPointSpread + P1 * dir,standPointSpread + tinggi + P1 * dir,standPointSpread + tinggi + P4 * dir,standPointSpread + P4 * dir,0.1);
        }
    }

    void putar(float deg, int dir){
        vec3_t target = this->stepPointSpread;
        vec3_t fw = rotateMatrix(target, deg * dir);
        vec3_t bw = rotateMatrix(target, deg *-1 * dir);
        vec3_t titikBantu = {0,4,target.z-target.z};
        

        if(this->side == 1){
            langkah(fw,fw + titikBantu,bw+ titikBantu,bw,0.1);
            delay(500);
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.1);
        }
        else{
            langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.1);
            delay(500);
            langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.1);
        }
    }

    void moveToPoint(vec3_t target){
        vec3_t deggs = InversKinematik(target);
        ax12a.move(coxaID,deggs.x);
        ax12a.move(fermurID,deggs.y);
        ax12a.move(thibiaID,deggs.z);
    }
    
    void init(){
        ax12a.move(coxaID,0);
        ax12a.move(fermurID,0);
        ax12a.move(thibiaID,0);
    }
    
    void berdiri(){
        moveToPoint(standPoint);
    }

    void berdiriSpread(){
        moveToPoint(standPointSpread);
    }
};
