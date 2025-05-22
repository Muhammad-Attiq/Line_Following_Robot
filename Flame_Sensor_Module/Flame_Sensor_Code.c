const int flameSensorPin = A0;   // KY-026 analog output
const int relayPin = 2;          // Relay control (fan)
const int redLedPin = 3;         // Flame detected
const int greenLedPin = 4;       // System ready

int flameThreshold = 500;        // Adjust based on testing (higher = less sensitive)
bool flameDetected = false;

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  digitalWrite(relayPin, LOW);   // Fan OFF initially
  digitalWrite(greenLedPin, HIGH); // System ready
  Serial.begin(9600);            
}

void loop() {
  int flameValue = analogRead(flameSensorPin);
  Serial.print("Flame Sensor: ");
  Serial.println(flameValue);

  if (flameValue < flameThreshold) { // Flame detected
    flameDetected = true;
    digitalWrite(redLedPin, HIGH);  
    digitalWrite(greenLedPin, LOW); 
    digitalWrite(relayPin, HIGH);   // Fan ON
    delay(3000);                    // Run fan for 3 sec
    digitalWrite(relayPin, LOW);    // Fan OFF
    flameDetected = false;
  } else {                          // No flame
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(relayPin, LOW);
  }
  delay(100); // Small delay for stability
}
