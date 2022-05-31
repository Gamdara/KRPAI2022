#include <Servo.h>

#define pinAtas 7
#define pinBawah 8

class Capit{
  private:
    Servo atas;
    Servo bawah;
  public:
    Capit(){
        atas.attach(pinAtas);
        bawah.attach(pinBawah);
    }
    void ambil(){
      bawah.write(50);
    }
    void taruh(){
      bawah.write(75);
    }
    void naik(){
      for(int i = 65; i > 29; i--) {
        atas.write(i);
        delay(2);
      } 
      delay(200);
      
      for(int i = 29; i < 115; i++) {
        atas.write(i);
        delay(2);
      }
    }
    void turun(){
      atas.write(115);
      delay(500);
      
      for(int i = 115; i > 65; i--) {
        atas.write(i);
        delay(2);
      }
    }
    
};
