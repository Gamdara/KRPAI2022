#include "SensorGaris.h"
class SensorGarisController{
  public:
    SensorGaris depan;
    SensorGaris belakang;
    SensorGarisController(){
      depan = SensorGaris(2);
      belakang = SensorGaris(34);
    }
    void init(){
      depan.init();
      belakang.init();
    }
    void resetAll(){
      depan.resetCounter();
      belakang.resetCounter();
    }
};
