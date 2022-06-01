#include <Arduino.h>

//=== PREPROCESSOR =====================================================
//--- AX12A
#include <SoftwareSerial.h>
#include <AX12A.h> 
#include <vector_type.h> 
#include <ArduinoQueue.h> 
#include <QMC5883LCompass.h>

#define lamabanget 200
#define lama 100
#define sedang 50
#define cepet 20

#define DirectionPin   (10u)
#define BaudRate      (1000000ul)
#define ID (1u)

#define MAJU 1
#define MUNDUR -1
#define KIRI -1
#define KANAN 1
