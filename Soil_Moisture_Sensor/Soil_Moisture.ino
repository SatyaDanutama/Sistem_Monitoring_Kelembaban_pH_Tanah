int sensorSoil = A0;
int nilai;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int kelembabanTanah;
  int nilai = analogRead(sensorSoil);
  kelembabanTanah = (100 - ((nilai/1023.00)*100));
}
