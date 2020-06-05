/*
	Basic Blink LED Example
*/
#include "Arduino.h"

int main(){
	init();
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	while(true){
		Serial.println("LED ON!");
		digitalWrite(LED_BUILTIN, HIGH);
		delay(1000);
		Serial.println("LED OFF!");
		digitalWrite(LED_BUILTIN, LOW);
		delay(1000);
	}
	Serial.flush();
	return 0;
}
