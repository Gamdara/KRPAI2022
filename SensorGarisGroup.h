#include "SensorGaris.h"
class SensorGarisGroup{
  public:
    SensorGaris depan;
    SensorGaris belakang;
    SensorGarisGroup(){
      depan = SensorGaris(2);
      belakang = SensorGaris(2);
    }
    void resetAll(){
      depan.resetCounter();
      belakang.resetCounter();
    }
};
