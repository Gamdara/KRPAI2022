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
    
    void moveDeg(vec3_t target, int local = 1){
        ax12a.move(coxaID,mapServo(target.x * (this->pos * local)) );
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

};
