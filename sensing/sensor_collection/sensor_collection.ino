#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float temperature;
float humidity, pressure;

boolean c = true;


void setup() {
  delay(1500);
  CARRIER_CASE = true;
  carrier.begin();
}

void loop() {
  
  temperature = carrier.Env.readTemperature(); //reads temperature

  humidity = carrier.Env.readHumidity(); //reads humidity
  pressure = carrier.Pressure.readPressure(); //reads pressure

  
}
