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
  int xValue = Esplora.readJoystickX();
  int yValue = Esplora.readJoystickY();
  int mouseX = map(xValue, -512, 512, 10, -10);  
  int mouseY = map(yValue, -512, 512, -10, 10);  
  Mouse.move(mouseX, mouseY, 0);                

  gamepad.check();
}
