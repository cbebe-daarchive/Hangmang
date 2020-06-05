/*
 * Blink, with conditional compilation based on the device name.
 */

#include <Arduino.h>
#include "superfluous.h"

const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);

}

void loop() {
    unsigned int half_period = blink_period / 2;

    digitalWrite(ledPin, HIGH);
    delay(half_period);
    digitalWrite(ledPin, LOW);
    delay(half_period);


}

