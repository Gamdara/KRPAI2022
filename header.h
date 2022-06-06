#include <Arduino.h>

//=== PREPROCESSOR =====================================================
//--- AX12A
#include <SoftwareSerial.h>
#include <AX12A.h> 
#include <vector_type.h> 
#include <ArduinoQueue.h> 
#include <Ultrasonic.h> 
#include <QMC5883LCompass.h>
#include <Servo.h>


#define lamabanget 200
#define lama 100
#define sedang 50
#define cepet 20
#define sonic 15



#define MAJU 1
#define MUNDUR -1
#define KIRI -1
#define KANAN 1

#define SUDUTJALANDEF 20
#define SUDUTPUTAR30 18

#include "Robot.h"






#define DirectionPin   (10u)
#define BaudRate      (1000000ul)
#define ID (1u)
