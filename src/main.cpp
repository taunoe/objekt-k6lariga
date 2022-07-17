#include <Arduino.h>
#include "notes.h"

#define RADAR_PIN 2
#define SPEAKER_PIN 10

const int melody_leght = 8;
int melody[melody_leght] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int note_durations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  /*
  Serial.begin(115200);
  // Boot message
  Serial.print("Project: ");
  Serial.println("\"Objekrt kõlariga\"");
  Serial.print("Compiled: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);
  Serial.println("Made by Tauno Erik.");
  */

  pinMode(RADAR_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);

  for (int note = 0; note < melody_leght; note++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int note_duration = 1000 / note_durations[note];
    tone(SPEAKER_PIN, melody[note], note_duration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pause = note_duration * 1.30;
    delay(pause);
    noTone(SPEAKER_PIN);
  }

}

void loop() {
  bool is_movement = digitalRead(RADAR_PIN);

  if (is_movement) {
    Serial.print("H");
  } else {
    Serial.print("L");
  }
}