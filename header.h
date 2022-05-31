#include <Arduino.h>
#include <math.h> 
#include <vector_type.h>
#include <ArduinoQueue.h>
#include "InversKinematik.h"
#include <QMC5883LCompass.h>


#define MAJU 1
#define MUNDUR -1
#define KANAN 1
#define KIRI -1
#define ORANGE 1
#define PUTIH 2


//=== PREPROCESSOR =====================================================
//--- AX12A
#include <SoftwareSerial.h>
#include <AX12A.h> 
#define DirectionPin   (10u)
#define BaudRate      (1000000ul)
#define ID (1u)
