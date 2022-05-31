#include "SensorJarak.h"

class SensorJarakController{
    public:
    SensorJarak depan;
    SensorJarak belakang;
    SensorJarak kiri;
    SensorJarak kanan;
    
    SensorJarakController(){
        depan = SensorJarak(1,2);
        belakang = SensorJarak(1,2);
        kiri = SensorJarak(1,2);
        kanan  = SensorJarak(1,2);
    }
};
