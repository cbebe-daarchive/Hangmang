#include <Arduino.h>
/*
   Test read and write to arduino through minicom
   test with 
        serial-mon

    there is no input echoing on the terminal side, so you cannot see
    what you type until the arduino echos it.  But you can turn on
    echoing in minicom using the command menu <CTRL>-A

    Use <CTRL>-A X to quit.

 */

uint8_t debug = 0;

void setup() {
    Serial.begin(9600);

}

// for incoming serial data, note must be bigger than a byte
// because -1 is used as a indicator of no data available

int16_t in_char = 0;   

uint8_t receiving_line = 0;

void loop() {
    if ( ! receiving_line ) {
        Serial.println("Send me something please, ^A Q to stop serial-mon");
        receiving_line = 1;
        }
    else {

        // wait for a byte to arrive
        while ( Serial.available() == 0 ) { }

        // read the incoming byte:
        in_char = Serial.read();

        // say what you got:
        if ( debug ) {
            Serial.print("I received: ");
            Serial.print(in_char, HEX);
            Serial.print(" '");
            Serial.write(in_char);
            Serial.print("'");
            Serial.println();
            }


        if (in_char == '\n' || in_char == '\r') {
            // go for another line 
            Serial.println();
            receiving_line = 0;
            }
        else {
            // echo back the character you typed
            Serial.write(in_char);
            }
        }
    }
 

