
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
      if(cekGaris() == 1) counterPutih++;
    }
    int jumlahPutih(){
      return counterPutih;
    }
    void resetCounter(){
      counterPutih = 0;  
    }
};
