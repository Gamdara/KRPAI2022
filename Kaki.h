class Kaki{
  private:
    int coxaID;
    int fermurID;
    int thibiaID;
    int pos; //KIRI / KANAN
    int grup; //GRUP1/2
    int letak; //DEPAN/TENGAH/BELAKANG
    
    vec3_t standPoint; //titik berdiri semut
    vec3_t standPointSpread; //titik berdiri laba laba
    
  public:
    Kaki(){}
    
    Kaki(int coxaID,int fermurID, int thibiaID, int pos, int grup, int letak){
      this->coxaID = coxaID;
      this->fermurID = fermurID;
      this->thibiaID = thibiaID; 
      this->pos = pos;
      this->grup = grup;
      this->letak = letak;
      
      this->standPoint = {0,-10,4};
      if(letak == DEPAN)
        this->standPoint = rotateMatrix(this->standPoint, 15 * KIRI * this->pos);
      else if(letak == BELAKANG)
        this->standPoint = rotateMatrix(this->standPoint, 15 * KANAN * this->pos);
    }

    void langkahSpread(vec3_t pointMaju, vec3_t pointMundur){
        if(this->grup == GRUP1){
          pointMaju.x *= this->pos;
          moveToPoint(pointMaju);
        }
        else{
          pointMundur.x *= this->pos;
          moveToPoint(pointMundur);
        }
        delay(20);
    }

    void langkah(vec3_t pointMaju, vec3_t pointMundur){
        if(letak == DEPAN){
          pointMaju = rotateMatrix(pointMaju, 15 * KIRI * this->pos);
          pointMundur = rotateMatrix(pointMundur, 15 * KIRI * this->pos);
        }
        else if(letak == BELAKANG){
          pointMaju = rotateMatrix(pointMaju, 15 * KANAN * this->pos);
          pointMundur = rotateMatrix(pointMundur, 15 * KANAN * this->pos);
        }

        if(this->grup == GRUP1){
          pointMaju.x *= this->pos;
          moveToPoint(pointMaju);
        }
        else{
          pointMundur.x *= this->pos;
          moveToPoint(pointMundur);
        }
        delay(20);
    }

    void moveToPoint(vec3_t target){
        vec3_t deggs = InversKinematik(target);
        ax12a.move(coxaID,mapServo(deggs.x) );
        ax12a.move(fermurID,mapServo(deggs.y));
        ax12a.move(thibiaID,mapServo(deggs.z));
    }
    
    void init(){
        ax12a.move(coxaID,mapServo(0));
        ax12a.move(fermurID,mapServo(0));
        ax12a.move(thibiaID,mapServo(0));
    }
    
    void berdiri(){
        moveToPoint(standPoint);
    }

    void berdiriSpread(){
        moveToPoint(standPointSpread);
    }
};
