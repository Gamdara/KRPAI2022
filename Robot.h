#include "KakiController.h"
#include "SensorJarakController.h"
#include "SensorWarna.h"
#include "SensorGarisController.h"
#include "Capit.h"
#include "Kompas.h"
#include "PemadamApi.h"

class Robot{
  public:
    Capit capit;
    SensorWarna sWarna;
    SensorGarisController IR;
    SensorJarakController mata;
    PemadamApi pemadam;
    Kompas kompas;
    KakiController kaki;
    Robot(){
      
    }
};
