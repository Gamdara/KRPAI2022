#include "SensorGaris.h"
class SensorGarisController{
  public:
    SensorGaris depan;
    SensorGaris belakang;
    SensorGarisController(){
      depan = SensorGaris(2);
      belakang = SensorGaris(2);
    }
    void resetAll(){
      depan.resetCounter();
      belakang.resetCounter();
    }
};
