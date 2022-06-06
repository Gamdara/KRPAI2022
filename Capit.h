#include <Servo.h>

//capit(bawah) - 30(taruh) 77(ambil)
//siku(atas) - 100(turun) 45(naik)


#define pinAtas 13
#define pinBawah 12

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
      for (int i = 77; i >= 30; i -= 1) {
        bawah.write(i);
        delay (5);
      }
    }
    void ambil(){
      for (int i = 30; i <= 77; i += 1) {
        bawah.write(i);
        delay (5); // Wait for 20 millisecond(s)
      }
    }
    void naik(){
      for (int i = 100; i >= 45; i -= 1) {
        atas.write(i);
        delay (5); // Wait for 20 millisecond(s)
      }
    }
    void turun(){
      for (int i = 45; i <= 100; i += 1) {
        atas.write(i);
        delay (5);
      }
    }
};
