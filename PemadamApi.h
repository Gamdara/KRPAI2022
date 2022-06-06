
class PemadamApi{
  private:
    int pinApi[5] = {A5,A4,A3,A2,A1};
    int pump1 = 38;
    
  public:
    PemadamApi(){
        
    }

    void init(){
      pinMode(pinApi[0], INPUT);
      pinMode(pinApi[1], INPUT);
      pinMode(pinApi[2], INPUT);
      pinMode(pinApi[3], INPUT);
      pinMode(pinApi[4], INPUT);
      pinMode(pump1, OUTPUT); 
      digitalWrite(pump1, LOW);
    }
    
    int cekApi(int pin){
      return digitalRead(pinApi[pin - 1]);
    }
    
    void semprot(int state){
//      unsigned long seconds = millis();
      digitalWrite(pump1, state);
//      if (seconds >= 3000)
//      digitalWrite(pump1, LOW);
    }

};
