#include <Arduino.h>

#define RADAR_PIN 2

void setup() {
  Serial.begin(115200);
  // Boot message
  Serial.print("Project: ");
  Serial.println("\"Kolm Silma\"");
  Serial.print("Compiled: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);
  Serial.println("Made by Tauno Erik.");

  pinMode(RADAR_PIN, INPUT);

}

void loop() {
  bool is_movement = digitalRead(RADAR_PIN);

  if (is_movement) {
    Serial.print("H");
  } else {
    Serial.print("L");
  }
}