#include <Arduino.h>

//=== PREPROCESSOR =====================================================
//--- AX12A
#include <SoftwareSerial.h>
#include <AX12A.h> 
#define DirectionPin   (10u)
#define BaudRate      (1000000ul)
#define ID (1u)

//--- AX12A
void init_bot(); // posisi awal
void walk_angkat(int depan,int tengah,int belakang); // 3 kaki diangkat (depan,tengah,belakang)
void walk_turun(int depan,int tengah,int belakang); // 3 kaki turun (depan,tengah,belakang)
void walk_dorong(int depan,int tengah,int belakang,int posisi); // dorong paha
void maju(); // maju 1 kali
void mundur(); // mundur 1 kali
void ke_kanan(); // puter kanan 30 derajat
void ke_kiri(); // puter kiri 30 derajat
void belok_kanan(); // belok kanan
void belok_kiri(); // belok kiri
void geser_kanan(int depankanan,int depankiri,int belakangkanan,int belakangkiri,int tengahkanan,int tengahkiri); // geser kanan 1x
void geser_kiri(int depankanan,int depankiri,int belakangkanan,int belakangkiri,int tengahkanan,int tengahkiri); // geser kiri 1x
