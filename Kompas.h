
class Kompas{
  private:
    QMC5883LCompass compass;
  public:
    Kompas(){
      compass.init();  
    }
    vec3_t getDirection(){
      compass.read();

      byte a = compass.getAzimuth();
    
      char myArray[3];
      compass.getDirection(myArray, a);
      
      return {myArray[0], myArray[1], myArray[2]};  
    }
};
