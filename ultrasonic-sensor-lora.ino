// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

#include <MKRWAN.h>

#include "arduino_secrets.h"

LoRaModem modem;


Statistic sensordata;


// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// Please enter your sensitive data in the Secret tab or arduino_secrets.h
String appEui = SECRET_APP_EUI;
String appKey = SECRET_APP_KEY;
// String modemBand = US915;


// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // Send ping, get distance in cm
  distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  
  if (distance >= 400 || distance <= 2) 
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}



static inline float getDistance() {

  // Initialize
  sensordata.clear();
  int timer = 500;

  // Loop 5 times
  for (count=0;count<5;count++) {

    // Send ping, get distance in cm
    distance = sonar.ping_cm();

    sensordata.add(distance);

    delay(timer);
  }

  // Return the average of those 5 reads.
  return myStats.average();
}

  


  
  // Send ping, get distance in cm
  distance = sonar.ping_cm();

  
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  
  if (distance >= 400 || distance <= 2) 
  {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);



  
  static unsigned long lastMillis;
  static float temperature = 0;

  unsigned long now = millis();
  if (now - lastMillis >= temperatureDelay * 1000) {
    lastMillis = now;
    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);
  }
  return temperature;
}


float average (int * array, int len)  // assuming array is int.
{
  long sum = 0L ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;  // average will be fractional, so float may be appropriate.
}
