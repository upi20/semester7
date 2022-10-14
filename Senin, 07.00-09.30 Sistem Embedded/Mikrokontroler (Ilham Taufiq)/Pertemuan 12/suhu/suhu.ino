/* How to use the DHT-22 sensor with Arduino
   Temperature and humidity sensor and
   I2C LCD1602
   SDA --> A4
   SCL --> A5
   Dev: Panagiotis Papadopoulos // Date: 7/6/2016 // */

//Libraries
#include <DHT.h>;
//I2C LCD:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
//int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value


void setup()
{
    Serial.begin(9600);
    Serial.println("ppdo's Temp and Humidity Sensor Test");
  dht.begin();
    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight
}

void loop()
{
    //Read data and store it to variables hum and temp
    // Reading temperature or humidity takes about 250 milliseconds!
   
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");

    
// set the cursor to (0,0):
    lcd.setCursor(0, 0);
// print from 0 to 9:

    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");
  
    lcd.setCursor(0, 1);

    lcd.print("Lembab: ");
    lcd.print(hum);
    lcd.print(" %");
  
  delay(3000); //Delay 3 sec.
}
