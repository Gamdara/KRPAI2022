
class SensorGaris{
  private:
    int outPin;
    int counterPutih = 0;
  public:
    SensorGaris(){}
    SensorGaris(int outPin){
      this->outPin = outPin;
      pinMode(outPin, INPUT);
    }
    int cekGaris(){
      return digitalRead(outPin);
    }
    void bacaPutih(){
      unsigned long seconds = millis();
      bool ada = false;
      while(seconds < 1000 && cekGaris() == 1)
        ada = true;
      if(ada) counterPutih++;
    }
    int jumlahPutih(){
      return counterPutih;
    }
    void resetCounter(){
      counterPutih = 0;  
    }
};
