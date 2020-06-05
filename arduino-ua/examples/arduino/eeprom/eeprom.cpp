/*  eeprom-example.cpp:
    The microcontroller on the Arduino has EEPROM:
    memory whose values are kept when the board is turned off.
    This enables you to read and write those bytes and retain their values
    when the board is powered off.
  Example Uses:
    - Highscore in games.
    - Data Saving.
    - User Choice Selection.
*/
#include <Arduino.h>
// Header file to include functionality for EEPROM (located in this directory).
#include "EEPROM.h"

int main() {
  init();
  Serial.begin(9600);
  /* (INTRODUCTION)
    The EEPROM acts as an array container whose values will retain
    after being powered off and as such each value can be indexed as such:
    EEPROM[i], where 'i' is the arbitrary index you are trying to access.

    You do not have to define the EEPROM array yourself after including <EEPROM.h>
  */
  Serial.println("EEPROM DEMO\r\n");

  /* (SIZE)
    The size of the EEPROM varies from board to board but can be determined with:
    EEPROM.length()
  */
  Serial.print("The amount of bytes in the EEPROM is: ");
  Serial.println(EEPROM.length());

  /* (WRITING)
    Writing to the EEPROM works the same as assigning a value to an array.
    EEPROM[i] = (value)
    Ensure to only write to locations in the EEPROM you're positive exist.
    However, each byte of the EEPROM can only hold a value from 0 to 255.
  */
  Serial.println("Writing '42' to EEPROM index 0.");
  EEPROM[0] = 42;

  /* (READING)
    Reading to the EEPROM works the same as reading a value of an array.
    EEPROM[i]
    Ensure to only read to locations in the EEPROM you're positive exist.
    TIP: When storing chars, they will be stored as their ASCII value and
    need to be displayed accordingly.
  */
  Serial.print("EEPROM index 0 contains value: ");
  Serial.println(EEPROM[0]);

  /* (USAGE)
    The use of EEPROM is substantial in various development and persistent
    memory is a must have feature in many applications. Here's a quick example
    on how to read and write something like strings.
  */

  /* (WRITING STRINGS) */

  // Location of memory index where we will be storing data.
  int mem_index = 1;
  // Example string to store.
  char test[31] = "<Example String to Read/Write>";
  // Store the size of the string at the memory to allow for iteration.
  EEPROM[mem_index] = sizeof(test);
  // Iterate through the test string and write it in memory on the EEPROM.
  for (int i = 0; i < sizeof(test); ++i){
    // Write +1 index since the first index is the size of the string.
    EEPROM[mem_index+i+1] = test[i];
  };

  /* (READING STRINGS) */

  // Get the length of the string from the memory index.
  // Iterate through the length of the string.
  for (int i = 1; i <= EEPROM[mem_index]; ++i){
    Serial.write(EEPROM[mem_index+i]);
  }

  // Wait for all outgoing Serial data to complete.
  Serial.flush();
  return 0;
}
