#define coxaLength 2.5
#define fermurLength 5
#define thibiaLength 8

vec3_t rotateMatrix(vec3_t from, float deg){
    float rad = deg * PI / 180.0;
    float x = (cos(rad) * from.x) - (from.z * sin(rad));
    float z = (cos(rad) * from.z) + (from.x * sin(rad));
    from.x = x;
    from.z = z;
    return from;
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
//    thetaC = 90 - thetaC;
    thetaF = 0 - thetaF - 45;
    thetaT = 0 - (thetaT - 90) - 45;
    return {thetaC,thetaF,thetaT};
}



int mapServo(int deg){
  return map(deg, 0, 150, 512, 0);
}
