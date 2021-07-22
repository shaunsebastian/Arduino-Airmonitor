#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int sensorValue;
LiquidCrystal_I2C lcd(0x27,16,2);
dht DHT;
#define DHT11_PIN 7
void setup(){
  pinMode(13, OUTPUT); 
  digitalWrite(13,HIGH);  
Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();
}
void loop(){
int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
sensorValue = analogRead(0);       // read analog input pin 0
Serial.print("AirQuality:");
Serial.print(sensorValue, DEC);               // prints the value read
Serial.println("PPM");
lcd.setCursor(0,0);
lcd.print("AirQuality:");
lcd.print(sensorValue,DEC);
lcd.print("PPM");
lcd.println("   "); 
lcd.print("  ");
delay(100);                                   // wait 100ms for next reading
}
