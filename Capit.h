#include <Servo.h>

//capit(bawah) - 30(taruh) 77(ambil)
//siku(atas) - 100(turun) 45(naik)


#define pinAtas 12
#define pinBawah 13

class Capit{
  private:
    Servo atas;
    Servo bawah;
    
  public:
    SensorJarak mata;
    Capit(){
        
    }
    void init(){
        atas.attach(pinAtas);
        bawah.attach(pinBawah);
        mata = SensorJarak(48,46);
        mata.init();
        atas.write(45);
        bawah.write(30);
        
    }
    void taruh(){
      for (int i = 77; i >= -10; i -= 1) {
        bawah.write(i);
        delay (20);
      }
    }
    void ambil(){
      for (int i = -10; i <= 77; i += 1) {
        bawah.write(i);
        delay (20); 
      }
    }
    void naik(){
      for (int i = 100; i >= 60; i -= 1) {
        atas.write(i);
        delay (10); 
      }
    }
    void turun(){
      for (int i = 60; i <= 100; i += 1) {
        atas.write(i);
        delay (10);
      }
    }
};
