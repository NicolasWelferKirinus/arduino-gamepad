#include "Arduinocontroller.h"

Arduinocontroller gamepad;

void setup()
{
}

void loop()
{
  gamepad.check_serial();
  gamepad.check_buttons();
  gamepad.check_joy();
  gamepad.check_gyro();
}
