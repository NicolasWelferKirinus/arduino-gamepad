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
}

void loop()
{
  gamepad.check();
}
