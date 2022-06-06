#include "SensorJarak.h"

class SensorJarakController{
    public:
    SensorJarak depan;
    SensorJarak belakang;
    SensorJarak kiri;
    SensorJarak kanan;
    
    SensorJarakController(){
        depan = SensorJarak(5,9);
        belakang = SensorJarak(6,10);
        kiri = SensorJarak(4,8);
        kanan  = SensorJarak(7,11);
    }
    void init(){
        depan.init();
        belakang.init();
        kiri.init();
        kanan.init();
    }
};
