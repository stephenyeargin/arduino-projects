/*
 * @author Stephen Yeargin <stephen.yeargin@gmail.com>
 */

#include <Morse.h>

// Output to LED pin
byte led = 13;

// Class instance of 'Morse'
Morse morse=Morse(led, 10, 1);

// Setup
void setup() {
  pinMode(led, OUTPUT);
}

// Run
void loop() {
  morse.sendmsg("S O S");
  delay(5000);
  morse.sendmsg("MY ARDUINO IS ALIVE!");
  delay(5000);
}
