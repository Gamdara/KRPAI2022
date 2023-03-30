#include <Arduino.h>
#include <math.h> 
#include <vector_type.h>
#include <ArduinoQueue.h>
#include "InversKinematik.h"

#define MAJU 1
#define MUNDUR -1

#define KANAN 1
#define KIRI -1

#define GRUP1 1
#define GRUP2 -1

#define DEPAN 1
#define TENGAH 2
#define BELAKANG 3

#define ORANGE 1
#define PUTIH 2


//=== PREPROCESSOR =====================================================
//--- AX12A
#include <SoftwareSerial.h>
#include <AX12A.h> 
#define DirectionPin   (10u)
#define BaudRate      (1000000ul)
#define ID (1u)
