#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H

class Arduinocontroller
{
private:
    int pressed[5];
    int comp[5];
    int button[5];
public:
    Arduinocontroller(): button{0, 0, 0, 0, 0},
        pressed{0, 0, 0, 0, 0},
        comp{0, 0, 0, 0, 0}
    {

    }

    void button_action(int pressed, int button_value)
    {
        if (button_value == 128) {
            if (pressed == 0) {                          
                Mouse.press();                             
            } else {
                Mouse.release();                          
            }
        } else {
            if (pressed == 0) {                           
                Keyboard.press(button_value);                     
            } else {
                Keyboard.release(button_value); 
            }
        }
    }

    void check(){
        int it = 0;
        while (Serial.available() > 0)
         {
               button[it] = Serial.read();
               it++;
         }
          pressed[0] = Esplora.readJoystickSwitch();
          pressed[1] = Esplora.readButton(SWITCH_UP);
          pressed[2] = Esplora.readButton(SWITCH_RIGHT);
          pressed[3] = Esplora.readButton(SWITCH_DOWN);
          pressed[4] = Esplora.readButton(SWITCH_LEFT);

          for (int i = 0; i < 5; i++) {
            if (pressed[i] != comp[i]) {
              button_action(pressed[i], button[i]);
              comp[i] = pressed[i];
            }
          }
    }

};
#endif // ARDUINOCONTROLLER_H
