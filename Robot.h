#include "KakiController.h"
#include "SensorJarakController.h"
#include "SensorWarna.h"
#include "SensorGarisController.h"
#include "Capit.h"
#include "Kompas.h"
#include "PemadamApi.h"

class Robot{
  private:
    int arah ;
  public:
    Capit capit;
//    SensorWarna sWarna;
    SensorGarisController IR;
    SensorJarakController mata;
    PemadamApi pemadam;
//    Kompas kompas;
    KakiController kaki;
    
    Robot(){
      arah = KANAN;
    }
    void init(){
      capit.init();
      IR.init();
      mata.init();
      pemadam.init();
      kaki.berdiri();
      delay(cepet);
      capit.naik();
      delay(cepet);
      capit.taruh();
    }
    void jalanZigZag(int dir = MAJU, int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF, int dile = sedang){
      if(mata.bacaDiagonal(KANAN) < 15)
        kaki.putar(KIRI, 5);
      else if(mata.bacaDiagonal(KIRI) < 15) 
        kaki.putar(KANAN, 5);
      else if(mata.kanan.bacaJarak() < 13)
        kaki.jalanSamping(KANAN);
      else if(mata.kiri.bacaJarak() < 13)
        kaki.jalanSamping(KIRI);
      else
        kaki.jalan(dir, SUDUTNAIK, SUDUTJALAN, dile);
    }
    void jalanAvoid(int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF, int dile = sedang){
      if(mata.kanan.bacaJarak() < 10) {
        kaki.putar(KIRI,10);
        jalanLangkah(2, SUDUTNAIK, SUDUTJALAN, dile);
      }
      
      else if(mata.kiri.bacaJarak() < 10){
        kaki.putar(KANAN,10);
        jalanLangkah(2, SUDUTNAIK, SUDUTJALAN, dile);
      }
      
      kaki.jalan(MAJU);
    }

    void jalanLangkah(int jumlah,int SUDUTNAIK = -65, int SUDUTJALAN = SUDUTJALANDEF, int dile = sedang){
      for(int i = 0; i < jumlah; i++)
        jalanZigZag(SUDUTNAIK, SUDUTJALAN, dile);
    }

};
