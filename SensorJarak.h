class  SensorJarak{
  private:
    int echoPin;
    int trigPin;
    
  public:
    int note;
    SensorJarak(){}
    SensorJarak(int echoPin, int trigPin){
        this->note = -1;
        this->echoPin = echoPin;
        this->trigPin = trigPin;
        
    }
    void init(){
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }
    int bacaJarak(){
      resetTrigger();
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      
      int jarak = pulseIn(echoPin, HIGH) * 0.034 / 2;
//      Serial.println(jarak);
      if(abs(note - jarak ) < 50 )
        note = jarak;
      return jarak;
    }
    void setNote(int val){
        note = val;
    }
    void resetTrigger(){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);  
    }
};
