#include "KakiGroup.h"
#include "SensorJarakGroup.h"
#include "SensorWarna.h"
#include "SensorGarisGroup.h"
#include "Capit.h"
#include "Kompas.h"
#include "PemadamApi.h"

class Robot{
  public:
    Capit capit;
    SensorWarna sWarna;
    SensorGarisGroup IR;
    SensorJarakGroup mata;
    PemadamApi pemadam;
    Kompas kompas;
    KakiGroup kaki;
    Robot(){
      
    }
};
