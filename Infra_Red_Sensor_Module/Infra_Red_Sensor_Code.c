int sensors[] = {A0, A1, A2, A3, A4};
int sensorValues[5];

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    sensorValues[i] = analogRead(sensors[i]);
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  Serial.println();
  delay(200);
}
