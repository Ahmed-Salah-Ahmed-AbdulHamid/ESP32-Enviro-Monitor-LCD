
//Ahmed Salah
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 4          
#define DHTTYPE DHT11     
#define LDR_PIN 35        
#define RELAY_PIN 5       

LiquidCrystal_I2C lcd(0x27, 16, 2); 
DHT dht(DHTPIN, DHTTYPE);

int lastTemp = -1;
int lastHum = -1;
int lastLight = -1;
int lastRelayState = -1;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); 

  lcd.begin(); 
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Smart GreenHouse");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int ldrValue = analogRead(LDR_PIN);
  int currentLight = map(ldrValue, 0, 4095, 0, 100);

  
  if (isnan(t) || isnan(h)) {
    Serial.println("Error reading DHT!");
    lcd.setCursor(0, 0);
    lcd.print("DHT Sensor Error"); 
    delay(2000);
    lcd.clear();
    return; 
  }

  
  int currentTemp = (int)t;
  int currentHum = (int)h;

  
  if (currentTemp != lastTemp || currentHum != lastHum) {
    lcd.setCursor(0, 0);
    lcd.print("T:"); lcd.print(currentTemp); lcd.print("C  ");
    lcd.print("Hum:"); lcd.print(currentHum); lcd.print("%  ");
    
    lastTemp = currentTemp;
    lastHum = currentHum;
  }

  
  int currentRelayState = (currentLight < 30) ? 1 : 0; 

  
  if (currentLight != lastLight || currentRelayState != lastRelayState) {
    lcd.setCursor(0, 1);
    lcd.print("Lght:"); lcd.print(currentLight); lcd.print("%  ");
    
    if (currentRelayState == 1) {
      digitalWrite(RELAY_PIN, LOW); 
      lcd.setCursor(12, 1);
      lcd.print("ON ");
    } else {
      digitalWrite(RELAY_PIN, HIGH); 
      lcd.setCursor(12, 1);
      lcd.print("OFF");
    }

    lastLight = currentLight;
    lastRelayState = currentRelayState;
  }

  delay(500);
}