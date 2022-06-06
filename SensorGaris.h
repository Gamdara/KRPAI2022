
class SensorGaris{
  private:
    int outPin;
    int counterPutih = 0;
    int counterHitam = 0;
    
  public:
    SensorGaris(){}
    SensorGaris(int outPin){
      this->outPin = outPin;
    }
    void init(){
      pinMode(outPin, INPUT);
    }
    int cekGaris(){
      return digitalRead(outPin);
    }
    void bacaPutih(){
//      unsigned long seconds = millis();
//      bool ada = false;
      if(cekGaris() == 1)
        counterPutih++;
    }
    void bacaHitam(){
      if(cekGaris() == 0)
        counterHitam++;
    }
    int jumlahHitam(){
      return counterHitam;
    }
    int jumlahPutih(){
      return counterPutih;
    }
    void resetCounter(){
      counterPutih = 0;  
    }
};
