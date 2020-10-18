/* This is a humidity and temperature sensor IoT Dashboard system using DHT22, Arduino Nano 33 IoT and the Arduino IoT Cloud. */ 

#include "thingProperties.h" // This file cn be found in the same folder
#include <SimpleDHT.h> // DHT.h library does not work on the nano 33 Iot board so I have used this library

#define DHTPIN 2 // defined the DHT22 to Digital pin 2

SimpleDHT22 dht22(DHTPIN);


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  float temperature_raw = 0;
  float humidity_raw = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&temperature_raw, &humidity_raw, NULL)) != SimpleDHTErrSuccess) {
    delay(1000);
    return;
  }
  temperature = temperature_raw;
  humidity = humidity_raw;
  Serial.println(temperature);
  Serial.println(humidity);
