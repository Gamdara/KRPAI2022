#include "SensorJarak.h"

class SensorJarakGroup{
    public:
    SensorJarak depan;
    SensorJarak belakang;
    SensorJarak kiri;
    SensorJarak kanan;
    
    SensorJarakGroup(){
        depan = SensorJarak(1,2);
        belakang = SensorJarak(1,2);
        kiri = SensorJarak(1,2);
        kanan  = SensorJarak(1,2);
    }
};
