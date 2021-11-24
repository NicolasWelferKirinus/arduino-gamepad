#include <Esplora.h>
#include <Mouse.h>
#include <Keyboard.h>
#include "Arduinocontroller.h"

Arduinocontroller gamepad;

void setup()
{
  Serial.begin(9600);      
  Mouse.begin();            
  Keyboard.begin();
}

void loop()
{
  gamepad.check();
}
