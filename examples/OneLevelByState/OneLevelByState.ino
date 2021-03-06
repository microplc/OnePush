#include <OnePush.h>
#include <Debounce.h>

// 1 level OnePush button called myButton.
// Each button press will turn the led On or Off.

byte button = 22;
byte led = 23;
OnePush myButton = OnePush(button); // Creates an OnePush button.

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, myButton.state()); // Write the state directly to the led.
}
