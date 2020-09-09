//when the button is pressed, it press and release F14 (for AHK) and then HOLDS F13 (for PPT)
//when the button is released, it sends F14 again and RELEASES F13

#include "Keyboard.h"
#include "Bounce2.h"

//F13 code source: https://www.reddit.com/r/arduino/comments/71c6xg/simulate_function_keys_f13f24_on_arduino/dnbks4s/

const int buttonPin = 16;          // input pin for pushbutton
char ctrlKey = KEY_LEFT_CTRL;
char shiftKey = KEY_LEFT_SHIFT;

const char F13key = 240;
const char F14key = F13key + 1;

Bounce  bouncer  = Bounce();

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT_PULLUP);
  bouncer.attach(buttonPin);
  bouncer.interval(50);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void toggleMute()
{
  Keyboard.press(F14key);
  delay(10);
  Keyboard.releaseAll();
  delay(100);
}

void loop() {
  // read the pushbutton:
  bouncer.update();
  if (bouncer.fell())
  {
    toggleMute();
    Keyboard.press(F13key);
  }
  else if(bouncer.rose())
  {
    toggleMute();
    Keyboard.release(F13key);
  }
}
