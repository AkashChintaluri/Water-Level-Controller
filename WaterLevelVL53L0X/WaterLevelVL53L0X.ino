#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

const int relayPin = 13;

void setup() {
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);

  Serial.begin(9600);
  
  pinMode(relayPin, OUTPUT);
}

void loop() {
  if (sensor.timeoutOccurred()) {
    Serial.println("Sensor timeout!");
  } else {
    int distance = sensor.readRangeSingleMillimeters() / 10; 
    // Display the distance in the Serial Monitor.
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 5) {
      digitalWrite(relayPin, HIGH);
    } else {
      digitalWrite(relayPin, LOW);
    }
  }
  delay(1000);
}
