
class Kompas{
  private:
    QMC5883LCompass compass;
  public:
    Kompas(){
      
    }
    void init(){
      compass.init();  
    }
    int getDirection(){
      compass.read();
    
      return compass.getAzimuth();
    }
};
