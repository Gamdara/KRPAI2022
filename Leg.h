#include "header.h"


class Leg{
  private:
    int coxaID;
    int fermurID;
    int thibiaID;
    int pos;
    vec3_t standPoint;
  public:
    Leg(){}
    Leg(int coxaID,int fermurID, int thibiaID, int post){
      this->coxaID = coxaID;
      this->fermurID = fermurID;
      this->thibiaID = thibiaID; 
      this->standPoint = {0,-6,4};
      this->pos = post
    }
    vec3_t InversKinematik(vec3_t target){
        float thetaC = atan2(target.z, target.x) * 180/PI ;
        
        float l = sqrt(target.x * target.x + target.z * target.z);
        float thetaF1 = atan2(target.y, l) ;
        
        float a = sqrt(l * l + target.y * target.y);
        float thetaF2 = acos((pow(fermurLength, 2) + pow(a, 2) - pow(thibiaLength, 2) )/ (2 * a * fermurLength));
        float thetaF = (thetaF1 + thetaF2)* 180/PI;
        float thetaT = (acos((pow(fermurLength, 2) + pow(thibiaLength, 2) - pow(a, 2) )/ (2 * thibiaLength * fermurLength)) * 180/PI - 90);
        
        //normalisasi
        thetaC = 90 - thetaC;
        thetaT = thetaT - 90;
        return {thetaC,thetaF,thetaT};
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
    void stand(){
        ax12a.move(coxaID, standPoint.x);
        ax12a.move(fermurID,standPoint.y);
        ax12a.move(thibiaID,standPoint.z);
    }
    void walk(int dir){
        moveToPoint({-4 * this->pos * dir,0,0});
        delay(10);
        moveToPoint({-2 * this->pos * dir,1,0});
        delay(10);
        moveToPoint({0,2,0});
        delay(10);
        moveToPoint({2 * this->pos * dir,1,0});
        delay(10);
        moveToPoint({4 * this->pos * dir,0,0});
        delay(500);
        moveToPoint({-4 * this->pos * dir,0,0});
        delay(10);
    }
    
};
