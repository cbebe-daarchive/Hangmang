#include "Morse.h"

#define BUZZER_PIN 13
#define TONE_FREQ 600    // Hz
#define UNIT_DURATION 25 // milliseconds

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

// wrap the on and off signals in void functions
// and pass on to Morse class
void onSignal()
{
  tone(BUZZER_PIN, TONE_FREQ);
  digitalWrite(BUZZER_PIN, HIGH);
}

void offSignal()
{
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
}

Morse buzzer(onSignal, offSignal, UNIT_DURATION);

void loop()
{
  buzzer.flashMessage("HELLO WORLD ");
  delay(1000);
}
