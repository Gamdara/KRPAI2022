#include "header.h"
#include "LegGroup.h"

class Robot{
  private:
    LegGroup legs;
  public:
    Robot(){}
    Robot(){
      
    }
    void walk(dir){
        legs.walk(dir);
    }
};
