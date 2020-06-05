/*
 * Blink, with conditional compilation based on the device name.
 */

/* note you can detect the Mega chip type with 
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
*/

/* An example of conditional compilation based on the device type:
 * Make the blink period twice as long when compiling on Megas.
 *
 * A more realistic use of this is with defining pins or choosing
 * SoftwareSerial over HardwareSerial, etc.
 */

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    #define INITIAL_BLINK_PERIOD 100
#else
    #define INITIAL_BLINK_PERIOD 500
#endif

const int blink_period = INITIAL_BLINK_PERIOD;




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

