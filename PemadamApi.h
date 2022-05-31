
class PemadamApi{
  private:
    int pinApi;
    int Api;
    byte pump1;
  public:
    PemadamApi(){
        pinApi =A3;
        pump1 = 7;
        
        pinMode(pinApi, INPUT);
        pinMode(pump1, OUTPUT); 
        digitalWrite(pump1, LOW); 
    }
    
    bool cekApi(){
      return digitalRead(pinApi);
    }
    
    void semprot(){
      unsigned long seconds = millis();
      digitalWrite(pump1, HIGH);
      if (seconds >= 5000)
      digitalWrite(pump1, LOW);
    }
};
