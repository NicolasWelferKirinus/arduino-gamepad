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

    void button_press(int button_value){
      switch(button_value){
        case 101:
          Mouse.press(MOUSE_LEFT);
          break;
        case 102:
          Mouse.press(MOUSE_MIDDLE);
          break;
        case 103:
          Mouse.press(MOUSE_RIGHT);
          break;
        default:
          Keyboard.press(button_value);
          break;
        }
      }

    void button_release(int button_value){
      switch(button_value){
        case 101:
          Mouse.release(MOUSE_LEFT);
          break;
        case 102:
          Mouse.release(MOUSE_MIDDLE);
          break;
        case 103:
          Mouse.release(MOUSE_RIGHT);
          break;
        default:
          Keyboard.release(button_value);
          break;
        }
      }

    void button_action(int pressed, int button_value)
    {
            if (pressed == 0) {                          
                button_press(button_value);                             
            } else {
                button_release(button_value);                          
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
          pressed[2] = Esplora.readButton(SWITCH_LEFT);
          pressed[3] = Esplora.readButton(SWITCH_RIGHT);
          pressed[4] = Esplora.readButton(SWITCH_DOWN);

          for (int i = 0; i < 5; i++) {
            if (pressed[i] != comp[i]) {
              button_action(pressed[i], button[i]);
              comp[i] = pressed[i];
            }
          }
    }

};
#endif // ARDUINOCONTROLLER_H
