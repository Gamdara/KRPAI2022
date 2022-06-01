
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

class SensorWarna{
  private:
    int frequency = 0;
    int color=0;    
  public:
    SensorWarna(){
        pinMode(S0, OUTPUT);
        pinMode(S1, OUTPUT);
        pinMode(S2, OUTPUT);
        pinMode(S3, OUTPUT);
        pinMode(sensorOut, INPUT);
        digitalWrite(S0, HIGH);
        digitalWrite(S1, LOW);
    }

    void printWarna(){
        vec3_t RGB;
        Serial.print("R= ");//printing name
        Serial.print(RGB.x);//printing RED color frequency
        Serial.print("  ");

        Serial.print("G= ");//printing name
        Serial.print(RGB.y);//printing GREEN color frequency
        Serial.print("  ");

        Serial.print("B= ");//printing name
        Serial.print(RGB.z);//printing BLUE color frequency
        Serial.println("  ");
    }

    vec3_t cekRGB(){
         // Setting red filtered photodiodes to be read
        digitalWrite(S2, LOW);
        digitalWrite(S3, LOW);
        // Reading the output frequency
        frequency = pulseIn(sensorOut, LOW);
        int R = frequency;
        // print hasil Red
        delay(sedang);
        
        // Setting Green filtered photodiodes to be read
        digitalWrite(S2, HIGH);
        digitalWrite(S3, HIGH);
        // Reading the output frequency
        frequency = pulseIn(sensorOut, LOW);
        int G = frequency;
        // Printing the value on the serial monitor
        
        delay(sedang);
       
        // Setting Blue filtered photodiodes to be read
        digitalWrite(S2, LOW);
        digitalWrite(S3, HIGH);
        // Reading the output frequency
        frequency = pulseIn(sensorOut, LOW);
        int B = frequency;
        
        delay(sedang);

        return {R,G,B};
    }
    
    int cekWarna() {  
      vec3_t RGB = cekRGB();  
      // angka orange dan putih  belum pasti jadi harus discan ulang kembali
      if(RGB.x<30 && RGB.x>36 && RGB.y<75 && RGB.y>55){
        color = 1; // orange
        
      }
      if(RGB.y<40 && RGB.y>37 && RGB.z<30 && RGB.z>26){
        color = 2; // white
        
      }
      return color;  
    }

    bool adaKorban(){
      return false;  
    }
};
