const int RELAY_PIN = 2;
const int TRIGGER_PIN = 8;
const int ECHO_PIN = 9;

void setup() {
    
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  delay(1000);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void loop() {
  long duration, distance_cm;

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = microsecondsToCentimeters(duration);

  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm > 5) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(100);
}
