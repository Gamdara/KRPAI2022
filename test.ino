#include "header.h"
#include "KakiGroup.h"

KakiGroup coba;
void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  Serial.begin(1000000);
  coba.init();
  delay(1000);
}

void loop(){
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 5; i++){
    coba.jalan(MAJU);
    delay(200);
  }
  coba.berdiri();
  delay(2000);
  for(int i = 0; i < 5; i++){
    coba.jalan(MUNDUR);
    delay(200);
  }
  delay(1000);
}

//ArduinoQueue<vec3_t> trajectory(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
//        ArduinoQueue<vec3_t> result(1/t + 3);
//        float mult = t;
//        result.enqueue(P1);
//        while(t<1){
//            vec3_t Pt = pow(1-t,3) * P1 + 3*t*pow(1-t,2) * P2 + 3*t*t*(1-t) * P3 + pow(t,3) * P4;
//            result.enqueue(Pt);
//            t += mult;
//            Serial.print(Pt.x);
//            Serial.print(" ");
//            Serial.print(Pt.y);
//            Serial.print(" ");
//            Serial.print(Pt.z);
//            Serial.println(" ");
//        }
//        result.enqueue(P4);
//        return result;
//    }
//
//void test(int dir){
//  vec3_t P1 = {-30,0,0};
//  vec3_t tinggi = {0,0,60};
//  vec3_t P4 = {30,0,0};
//  vec3_t standPoint = {0, 0, -90};  
//
//  ArduinoQueue<vec3_t> steps = trajectory(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.5);
//  ArduinoQueue<vec3_t> backSteps = trajectory(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.5);
//  Serial.println("ini apa?");
//  while(!steps.isEmpty()){
//      vec3_t Pt = steps.dequeue();
//      Serial.print(Pt.x);
//      Serial.print(" ");
//      Serial.print(Pt.z);
//      Serial.println(" ");
//  }
//  Serial.println("apa ini");
//  while(!backSteps.isEmpty()){
//      vec3_t Pts = backSteps.dequeue();
//      Serial.print(Pts.x);
//      Serial.print(" ");
//      
//      Serial.print(Pts.z);
//      Serial.println(" ");
//  }
//  
//}
//
//void setup(){
//  Serial.begin(9600);
//  test(1);
//}
//
//void loop(){  
//  delay(1000);
//}
