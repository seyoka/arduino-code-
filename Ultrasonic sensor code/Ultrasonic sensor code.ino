
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

int trigPin = 9;    
int echoPin = 8;    

float duration_us, distance_cm;

void setup() {
  lcd.init();               
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_us = pulseIn(echoPin, HIGH);
  distance_cm = 0.017 * duration_us;

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Distance: ");
  lcd.print(distance_cm);

  delay(500);