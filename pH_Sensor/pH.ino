#define analogInPin A2
int sensorpH = 0;        
float outputpH = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorpH = analogRead(analogInPin);  
  outputpH = (-0.0139*sensorpH)+7.7851;
}
