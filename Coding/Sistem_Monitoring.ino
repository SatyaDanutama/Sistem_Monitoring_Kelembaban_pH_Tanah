#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorSoil = A0;
int nilai;

#define analogInPin A2
int sensorpH = 0;        
float outputpH = 0.0;

int RELAY1 = 4;
int RELAY2 = 5;

int LED1 = 13;
int LED2 = 12;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Alat Monitoring");
  delay(2000);
  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

}

void loop(){
  
  int kelembabanTanah;
  int nilai = analogRead(sensorSoil);
  kelembabanTanah = (100 - ((nilai/1023.00)*100));

  lcd.setCursor(0, 0);
  lcd.print("Kelembaban tanah : ");
  lcd.setCursor(0, 1);
  lcd.print(kelembabanTanah);
  lcd.print("%");
  delay(1000);
  lcd.clear();

  if(kelembabanTanah <= 40){
  digitalWrite(RELAY1, LOW);
  digitalWrite(LED1, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Tanah kering");
  lcd.setCursor(0, 1);
  lcd.print("siram air");
  delay(500);
  }
  else {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(LED1, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Tanah lembab/bas");
  lcd.setCursor(0, 1);
  lcd.print("ah");
  delay(1000);
}

  Serial.print("Kelembaban tanah : ");
  Serial.println(kelembabanTanah);
  Serial.println("%");
  delay(1000);
  lcd.clear();

  //read the analog in value:
  sensorpH = analogRead(analogInPin);
  //rumus didapat berdasarkan datasheet   
  outputpH = (-0.0139*sensorpH)+7.7851;

  lcd.setCursor(0, 0);
  lcd.print("adc= ");
  lcd.print(sensorpH);
  lcd.setCursor(0, 1);
  lcd.print("pH Tanah= ");
  lcd.print(outputpH);
  delay(1000);
  lcd.clear();

if(outputpH <= 5.0) {
  digitalWrite(RELAY2, LOW);
  digitalWrite(LED2, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Kadar pH tanah");
  lcd.setCursor(0, 1);
  lcd.print("kurang");
  delay(1000);
}
 else {
  digitalWrite(RELAY2, HIGH);
  digitalWrite(LED2, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Kadar pH tanah");
  lcd.setCursor(0, 1);
  lcd.print("bagus");
  delay(1000);
  }
    
  Serial.print("adc= ");
  Serial.println(sensorpH);
  Serial.print("pH Tanah= ");
  Serial.println(outputpH);
  delay(1000);
  lcd.clear();
  delay(1000);
}
