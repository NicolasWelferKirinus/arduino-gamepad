#include <Joystick.h>
#include <Esplora.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <XInput.h>
#include "Arduinocontroller.h"

Arduinocontroller gamepad;

void setup()
{
  Serial.begin(9600);      
  Mouse.begin();            
  Keyboard.begin();
  XInput.begin();
  Joystick_(0x03, 0x05, 9, 0, true, true, false, false, false, false, false, false, false, false, false);
}

void loop()
{
  gamepad.check_serial();
  gamepad.check_buttons();
  gamepad.check_joy();
}
