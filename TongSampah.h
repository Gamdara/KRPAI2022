void loopjelek(){
  switch(state){
    case 1:
      while(KSR.mata.depan.bacaJarak() > 20){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 2:
      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 2){
        KSR.IR.depan.bacaPutih();
        KSR.IR.belakang.bacaPutih();
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      while(KSR.mata.depan.bacaJarak() > 20 ){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 3:
      while(KSR.mata.kiri.bacaJarak() < 10 && KSR.mata.kanan.bacaJarak() < 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      while(KSR.mata.depan.bacaJarak() > 40 ){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;  
    case 4:
      for(int i = 0; i < 5; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;  
    case 5:
      while(KSR.IR.depan.jumlahPutih() < 2 && KSR.IR.belakang.jumlahPutih() < 1){
        KSR.IR.depan.bacaPutih();
        KSR.IR.belakang.bacaPutih();
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      state++;
      break;
    case 6:
      while(KSR.pemadam.cekApi()){
        KSR.kaki.putar(KIRI);
        delay(sedang);
        KSR.pemadam.semprot();
        KSR.kaki.putar(KANAN);
        delay(sedang);
        KSR.kaki.putar(KANAN);
        delay(lama);
        KSR.kaki.putar(KIRI);
        delay(sedang);
      }
      state++;
      break;
    case 7:
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      if(KSR.sWarna.adaKorban()){
        state++;
        break;
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 8:
      KSR.capit.taruh();
      delay(lama);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }  
      KSR.capit.ambil();
      delay(lama);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(lama);  
      }
      KSR.capit.naik();
      delay(lama);
      state++;
      break;
    case 9:
      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(lama);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(lama);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(lama);  
        }
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(lama);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
      }
      state++;
      break;
    case 10:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      KSR.capit.turun();
      delay(lama);
      KSR.capit.taruh();
      delay(lama);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(lama);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      state++;
      break;
    case 11:
      for(int i = 0; i < 15; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      state++;
      break;
    case 12:
      while(KSR.mata.depan.bacaJarak() > 30)
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      state++;
      break;
    case 13:
      while(KSR.pemadam.cekApi()){
        KSR.kaki.putar(KIRI);
        delay(sedang);
        KSR.pemadam.semprot();
        KSR.kaki.putar(KANAN);
        delay(sedang);
        KSR.kaki.putar(KANAN);
        delay(lama);
        KSR.kaki.putar(KIRI);
        delay(sedang);
      }
      state++;
      break;
    case 14:
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      if(KSR.sWarna.adaKorban()){
        state++;
        break;
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.putar(KIRI);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 15:
      KSR.capit.taruh();
      delay(lama);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }  
      KSR.capit.ambil();
      delay(lama);
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MUNDUR);
        delay(lama);  
      }
      KSR.capit.naik();
      delay(lama);
      state++;
      break;
    case 16:
      if(KSR.mata.kanan.bacaJarak() > KSR.mata.kiri.bacaJarak()){
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(lama);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(lama);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KANAN);
          delay(lama);  
        }
      }
      else{
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
        while(KSR.mata.depan.bacaJarak() > 10){
          KSR.kaki.jalan(MAJU);
          delay(lama);
        }
        for(int i = 0; i < 3; i++){
          KSR.kaki.putar(KIRI);
          delay(lama);  
        }
      }
      state++;
      break;
    case 17:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      for(int i = 0; i < 5; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KANAN);
        delay(lama);  
      }
      state++;
      break;
    case 18:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      KSR.capit.turun();
      delay(lama);
      KSR.capit.taruh();
      delay(lama);
      while(KSR.mata.depan.bacaJarak() > 40){
        KSR.kaki.jalan(MUNDUR);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 19:
      while(KSR.mata.depan.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.putar(KIRI);
        delay(lama);  
      }
      state++;
      break;
    case 20:
      while(KSR.mata.kiri.bacaJarak() > 10){
        KSR.kaki.jalan(MAJU);
        delay(lama);
      }
      for(int i = 0; i < 3; i++){
        KSR.kaki.jalan(MAJU);
        delay(lama);  
      }
      state++;
      break;
  }
}

ArduinoQueue<vec3_t> trajectory(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
    ArduinoQueue<vec3_t> result(1/t + 3);
    float mult = t;
    result.enqueue(P1);
    while(t<1){
        vec3_t Pt = pow(1-t,3) * P1 + 3*t*pow(1-t,2) * P2 + 3*t*t*(1-t) * P3 + pow(t,3) * P4;
        result.enqueue(Pt);
        t += mult;
        Serial.print(Pt.x);
        Serial.print(" ");
        Serial.print(Pt.y);
        Serial.print(" ");
        Serial.print(Pt.z);
        Serial.println(" ");
    }
    result.enqueue(P4);
    return result;
}

void langkah(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
    ArduinoQueue<vec3_t> steps = trajectory(P1,P2,P3,P4,t);
    while(!steps.isEmpty()){
        vec3_t temp = steps.dequeue();
        temp.x *= this->pos;
        moveDeg(temp);
    }
}

void jalan(int dir){
    vec3_t P1 = {-15,0,0};
    vec3_t tinggi = {0,0,45};
    vec3_t P4 = {15,0,0};

    if(this->grup == 1){
        langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.3);
        langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.3);
    }
    else{
        langkah(standPoint + P4 * dir,standPoint + P4 * dir,standPoint +  P1 * dir,standPoint + P1 * dir,0.3);
        langkah(standPoint + P1 * dir,standPoint + tinggi + P1 * dir,standPoint + tinggi + P4 * dir,standPoint + P4 * dir,0.3);
    }
}

void putar(float deg, int dir){
    vec3_t target = this->standPoint;
    vec3_t fw = rotateMatrix(target, deg * dir);
    vec3_t bw = rotateMatrix(target, deg *-1 * dir);
    vec3_t tinggi = {0,4,0};
    vec3_t titikBantu = {0,4,target.z-target.z};
    
    if(this->grup == 1){
        langkah(fw,fw + titikBantu + tinggi,bw+ titikBantu + tinggi,bw,0.3);
        delay(lamabanget);
        langkah(bw,bw + titikBantu,fw+ titikBantu ,fw,0.3);
    }
    else{
        langkah(bw,bw + titikBantu,fw+ titikBantu ,fw,0.3);
        delay(lamabanget);
        langkah(fw,fw + titikBantu + tinggi,bw+ titikBantu + tinggi,bw,0.3);
    }
}



    void jalanTest(int dir){
      vec3_t P1 = {-30,0,0};
      vec3_t tinggi = {0,0,60};
      vec3_t P4 = {30,0,0};

      ArduinoQueue<vec3_t> steps = trajectory(
          standPoint + P1 * dir,
          standPoint + tinggi + P1 * dir,
          standPoint + tinggi + P4 * dir,
          standPoint + P4 * dir,0.5
      );
      ArduinoQueue<vec3_t> backSteps = trajectory(
          standPoint + P4 * dir,
          standPoint + P4 * dir,
          standPoint + P1 * dir,
          standPoint + P1 * dir,0.5
      );
      
      while(!steps.isEmpty() && !backSteps.isEmpty()){
          
          vec3_t sTemp = steps.dequeue();
          vec3_t bTemp = backSteps.dequeue();

          RF.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          LM.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          RB.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          LF.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          RM.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          LB.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          delay(lama);
      }

      backSteps = trajectory(
          standPoint + P1 * dir,
          standPoint + tinggi + P1 * dir,
          standPoint + tinggi + P4 * dir,
          standPoint + P4 * dir,0.5
      );
      steps = trajectory(
          standPoint + P4 * dir,
          standPoint + P4 * dir,
          standPoint +  P1 * dir,
          standPoint + P1 * dir,0.5
      );
      
      while(!steps.isEmpty() && !backSteps.isEmpty()){
          vec3_t sTemp = steps.dequeue();
          vec3_t bTemp = backSteps.dequeue();
       
          RF.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          LM.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          RB.moveDeg({sTemp.x , sTemp.y,sTemp.z });
          delay(20);
          LF.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          RM.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          LB.moveDeg({bTemp.x , bTemp.y,bTemp.z });
          delay(20);
          delay(lama);
      }
      
    }

    ArduinoQueue<vec3_t> trajectory(vec3_t P1,vec3_t P2,vec3_t P3,vec3_t P4, float t){
        ArduinoQueue<vec3_t> result(1/t + 3);
        float mult = t;
        result.enqueue(P1);
        while(t<1){
            vec3_t Pt = pow(1-t,3) * P1 + 3*t*pow(1-t,2) * P2 + 3*t*t*(1-t) * P3 + pow(t,3) * P4;
            result.enqueue(Pt);
            t += mult;
        }
        result.enqueue(P4);
        return result;
    }

    
    void initKuda(){
      RF.moveDeg({45  ,0,-90});
      LF.moveDeg({45  ,0,-90});
      delay(sedang);  

      RB.moveDeg({-45  ,0,-90});
      LB.moveDeg({-45  ,0,-90});
      delay(sedang);  

      RM.moveDeg({0  ,0,-60});
      LM.moveDeg({0  ,0,-60});
      delay(sedang);  
    }
  
    void panjatKuda(int sudut){
      LF.moveDeg({sudut  ,0,-90});
      RB.moveDeg({0  ,0,-45});
      delay(lama);
      RF.moveDeg({0  ,0,-15});
      LB.moveDeg({-1 * sudut  ,0,0});
      delay(lama);

      LF.moveDeg({0  ,0,-90});
      RB.moveDeg({-1 * sudut  ,0,-45});
      delay(lama);
      RF.moveDeg({sudut  ,0,-15});
      LB.moveDeg({0  ,0,0});
      delay(lama);

      RF.moveDeg({sudut  ,0,-90});
      LB.moveDeg({0  ,0,-45});
      delay(lama);
      LF.moveDeg({0  ,0,-15});
      RB.moveDeg({-1 * sudut  ,0,0});
      delay(lama);
      
      RF.moveDeg({0  ,0,-90});
      LB.moveDeg({-1 * sudut  ,0,-45});
      delay(lama);
      LF.moveDeg({sudut  ,0,-15});
      RB.moveDeg({0  ,0,0});
      delay(lama);
    }

    void initPenyu(){
      RF.moveDeg({0  ,0,-90});
      LF.moveDeg({0  ,0,-90});
      RM.moveDeg({0  ,0,-45});
      LM.moveDeg({0  ,0,-45});
      RB.moveDeg({-45  ,0,-45});
      LB.moveDeg({-45  ,0,-45});
    }

    void panjatPenyu(){
      RF.moveDeg({0  ,0,0});
      delay(lama);
      RF.moveDeg({45  ,0,0});
      delay(lama);
      RF.moveDeg({45  ,0,-90});
      delay(lama);
      LF.moveDeg({0  ,0,0});
      delay(lama);
      LF.moveDeg({45  ,0,0});
      delay(lama);
      LF.moveDeg({45  ,0,-90});
      delay(lama);
     
      RM.moveDeg({-30  ,0,0});
      LM.moveDeg({-30  ,0,0});
      delay(lama);
      RM.moveDeg({30  ,0,0});
      LM.moveDeg({30  ,0,0});
      delay(lama);
      RM.moveDeg({30  ,0,-45});
      LM.moveDeg({30  ,0,-45});
      delay(lama);
      RM.moveDeg({30  ,0,-90});
      LM.moveDeg({30  ,0,-90});
      delay(lama);
      RM.moveDeg({-30  ,0,-90});
      LM.moveDeg({-30  ,0,-90});
      delay(lama);
      RM.moveDeg({-30  ,0,-45});
      LM.moveDeg({-30  ,0,-45});
      delay(lama);
      delay(500);

      RF.moveDeg({0  ,0,-90});
      LF.moveDeg({0  ,0,-90});
      delay(lama);
    }

    
    void panjatInit(int dir){
      LF.moveDeg({0  * dir,0,0});
      RF.moveDeg({0  * dir,0,0});
      delay(sedang);
      LF.moveDeg({30  * dir,0,0});
      RF.moveDeg({30  * dir,0,0});
      delay(lama);
      LF.moveDeg({30  * dir,0,-45});
      RF.moveDeg({30  * dir,0,-45});
      delay(sedang);
      
      LM.moveDeg({0  * dir,0,-90});
      RM.moveDeg({0  * dir,0,-90});
      LF.moveDeg({30  * dir,0,-90});
      RF.moveDeg({30  * dir,0,-90});
      delay(sedang);

      RM.moveDeg({0  * dir,0,-45});
      delay(sedang);
      LM.moveDeg({0  * dir,0,-45});
      delay(sedang);
    }

    void panjat(int dir){
      RF.moveDeg({0  * dir,0,-90});
      delay(sedang);
      RB.moveDeg({-45  * dir,0,-90});
      delay(sedang);

      LF.moveDeg({0  * dir,0,-90});
      delay(sedang);
      LB.moveDeg({-45  * dir,0,-90});
      delay(sedang);

      RF.moveDeg({0  * dir,0,0});
      delay(sedang);
      RF.moveDeg({45  * dir,0,0});
      delay(lama);
      RF.moveDeg({45  * dir,0,-90});
      delay(sedang);

      LF.moveDeg({0  * dir,0,0});
      delay(sedang);
      LF.moveDeg({45  * dir,0,0});
      delay(lama);
      LF.moveDeg({45  * dir,0,-90});
      delay(sedang);
      
      RM.moveDeg({0  * dir,0,-70});
      delay(sedang);
      RB.moveDeg({-45  * dir,0,-45});
      delay(sedang);
      RB.moveDeg({0  * dir,0,-45});
      delay(lama);
      RB.moveDeg({0  * dir,0,-90});
      delay(sedang);
      RM.moveDeg({0  * dir,0,-45});
      delay(sedang);

      LM.moveDeg({0  * dir,0,-70});
      delay(sedang);
      LB.moveDeg({-45  * dir,0,-45});
      delay(sedang);
      LB.moveDeg({0  * dir,0,-45});
      delay(lama);
      LB.moveDeg({0  * dir,0,-90});
      delay(sedang);
      LM.moveDeg({0  * dir,0,-45});
      delay(sedang);

      RF.moveDeg({0  * dir,0,-90});
      delay(sedang);
      LF.moveDeg({0  * dir,0,-90});
      delay(sedang);
      
      RB.moveDeg({-45  * dir,0,-90});
      delay(sedang);
      LB.moveDeg({-45  * dir,0,-90});
      delay(sedang);
    }



void jalanSampingSetengah(int dir, int SUDUTJALAN = 15){
      LF.moveDeg({0 * dir,0,-90});
      RB.moveDeg({0 * dir,0,-90});
      delay(sedang);
      RF.moveDeg({SUDUTJALAN * dir * -1,0,-65});
      LB.moveDeg({SUDUTJALAN * dir * -1,0,-65});
      delay(sedang);

      RF.moveDeg({SUDUTJALAN * dir * -1,0,-90});
      LB.moveDeg({SUDUTJALAN * dir * -1,0,-90});
      delay(sedang);
      LF.moveDeg({0 * dir,0,-65});
      RB.moveDeg({0 * dir,0,-65});
      delay(sedang);
      
      RF.moveDeg({0 * dir * -1,0,-90});
      LB.moveDeg({0 * dir * -1,0,-90});
      delay(sedang);
      LF.moveDeg({SUDUTJALAN * dir,0,-65});
      RB.moveDeg({SUDUTJALAN * dir,0,-65});
      delay(sedang);
      
      LF.moveDeg({SUDUTJALAN * dir,0,-90});
      RB.moveDeg({SUDUTJALAN * dir,0,-90});
      delay(sedang);
      RF.moveDeg({0 * dir * -1,0,-65});
      LB.moveDeg({0 * dir * -1,0,-65});
      delay(sedang);  
    }

void jalanDua(int dir,int SUDUTJALAN = SUDUTJALANDEF){
      RF.moveDeg({SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(sedang);
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      delay(sedang);

      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(sedang);
      LF.moveDeg({SUDUTJALAN  * dir,0,-45});
      RM.moveDeg({SUDUTJALAN  * dir,0,-45});
      LB.moveDeg({SUDUTJALAN  * dir,0,-45});
      delay(sedang);

      LF.moveDeg({SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({SUDUTJALAN  * dir,0,-90});
      delay(sedang);
      RF.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      LM.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      RB.moveDeg({-1 * SUDUTJALAN  * dir,0,-45});
      delay(sedang);
      
      LF.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      RM.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      LB.moveDeg({-1 * SUDUTJALAN  * dir,0,-90});
      delay(sedang);
      RF.moveDeg({SUDUTJALAN  * dir,0,-45});
      LM.moveDeg({SUDUTJALAN  * dir,0,-45});
      RB.moveDeg({SUDUTJALAN  * dir,0,-45});
      delay(sedang);
    }


void initPanjat(){
      LF.berdiri();
      LM.moveDeg({15 ,0,-90});
      LB.berdiri();
      RF.berdiri();
      RM.moveDeg({15,0,-90});
      RB.berdiri();
    }
