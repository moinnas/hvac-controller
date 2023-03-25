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
/*
  //reads IMU sensor  
  carrier.IMUmodule.readGyroscope(gyroscope_x, gyroscope_y, gyroscope_z); //read gyroscope (x, y z)
  carrier.IMUmodule.readAcceleration(accelerometer_x, accelerometer_y, accelerometer_z); //read accelerometer (x, y z)

  //reads ambient light
  if (carrier.Light.colorAvailable()) {
    carrier.Light.readColor(none, none, none, light);
  }
*/
  //updates state of all buttons
  carrier.Buttons.update();

  //checks if button 1 has been pressed
  if (carrier.Button1.onTouchDown()) { 
      c = !c;
   }
/*
  carrier.leds.setPixelColor(pixel, g , r , b); //sets pixels. e.g. 3, 255, 0 , 255
  carrier.leds.show(); //displays pixels

  carrier.Relay1.open(); //opens relay 1
  carrier.Relay1.close(); //closes relay 1

  carrier.Buzzer.sound(500); //sets frequency of buzzer
  delay(1000); //sets duration for sounds
  carrier.Buzzer.noSound(); //stops buzzer
*/

  //controlling screen
  //carrier.display.fillScreen(ST77XX_RED); //red background
  carrier.display.fillScreen(0x0000);
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(2); //medium sized text

  carrier.display.setCursor(20, 80); //sets position for printing (x and y)
  
  carrier.display.print("Temp: "); //prints text
  if(c){
    carrier.display.print(temperature); //prints a variable
    carrier.display.println(" C"); //prints text
    carrier.leds.setPixelColor(1, 0 , 200 , 0); //sets pixels. e.g. 3, 255, 0 , 255

  }else{
    carrier.display.print((temperature*9/5) + 32); //prints a variable
    carrier.display.println(" F"); //prints text
    carrier.leds.setPixelColor(1, 200 , 0 , 0); //sets pixels. e.g. 3, 255, 0 , 255
  }
  
  carrier.display.setCursor(20, 100); //sets position for printing (x and y)
  carrier.display.print("Humidity: ");
  carrier.display.print(humidity); //prints a variable
  carrier.display.println("%"); //prints text


  carrier.display.setCursor(20, 120); //sets position for printing (x and y)
  carrier.display.print("Pressure: ");
  carrier.display.print(pressure); //prints a variable
  carrier.display.println("hPa"); //prints text
   
  carrier.leds.show(); //displays pixels

  delay(500);

}


 
void configure()
{
  carrier.display.fillScreen(0x0000);
  //Basic configuration for the text
  carrier.display.setRotation(0);
  carrier.display.setTextWrap(true);}
