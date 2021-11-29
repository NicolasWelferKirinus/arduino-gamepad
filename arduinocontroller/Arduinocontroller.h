#include <Esplora.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <XInput.h>

#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H

class Arduinocontroller
{
private:
    int pressed[5];
    int comp[5];
    int button[5];
    int joy_button[5];
    int joy_value[2];
    int joy_comp[2];
public:
    Arduinocontroller(): button{0, 0, 0, 0, 0},
        pressed{0, 0, 0, 0, 0},
        comp{0, 0, 0, 0, 0},
        joy_button{0, 0, 0, 0, 0},
        joy_value{0, 0},
        joy_comp{0, 0}
    {

    }

    void button_press(int button_value){
      switch(button_value){
        case 104:
          Mouse.press(MOUSE_LEFT);
          break;
        case 105:
          Mouse.press(MOUSE_MIDDLE);
          break;
        case 106:
          Mouse.press(MOUSE_RIGHT);
          break;
        case 107:
          Mouse.move(0, -3, 0); 
          break;
        case 108:
          Mouse.move(-3, 0, 0); 
          break;
        case 109:
          Mouse.move(3, 0, 0); 
          break;
        case 110:
          Mouse.move(0, 3, 0); 
          break;
        case 111:
          Mouse.move(0, 0, 1); 
          break;
        case 112:
          Mouse.move(0, 0, -1); 
          break;
        case 113:
          XInput.press(BUTTON_Y);
          break;
        case 114:
          XInput.press(BUTTON_X);
          break;
        case 115:
          XInput.press(BUTTON_B);
          break;
        case 116:
          XInput.press(BUTTON_A);
          break;
        case 117:
          XInput.press(TRIGGER_LEFT);
          break;
        case 118:
          XInput.press(TRIGGER_RIGHT);
          break;
          case 119:
          XInput.press(BUTTON_LB);
          break;
        case 120:
          XInput.press(BUTTON_RB);
          break;
         case 121:
          XInput.press(DPAD_UP);
          break;
          case 122:
          XInput.press(DPAD_LEFT);
          break;
          case 123:
          XInput.press(DPAD_RIGHT);
          break;
          case 124:
          XInput.press(DPAD_DOWN);
          break;
          case 125:
          XInput.press(BUTTON_BACK);
          break;
          case 126:
          XInput.press(BUTTON_LOGO);
          break;
          case 127:
          XInput.press(BUTTON_START);
          break;
          case 222:
          XInput.press(BUTTON_L3);
          break;
          case 223:
          XInput.press(BUTTON_R3);
          break;
          case 224:
          XInput.setJoystick(JOY_LEFT, 0, 32767);
          XInput.setJoystick(JOY_LEFT, 0, 0);
          break;
        case 225:
          XInput.setJoystick(JOY_LEFT, -32768, 0);
          XInput.setJoystick(JOY_LEFT, 0, 0);
          break;
        case 226:
          XInput.setJoystick(JOY_LEFT, 32767, 0); 
          XInput.setJoystick(JOY_LEFT, 0, 0);
          break;
        case 227:
          XInput.setJoystick(JOY_LEFT, 0, -32768);
          XInput.setJoystick(JOY_LEFT, 0, 0);
          break;
        case 228:
          XInput.setJoystick(JOY_RIGHT, 0, 32767);
          XInput.setJoystick(JOY_RIGHT, 0, 0);
          break;
        case 229:
          XInput.setJoystick(JOY_RIGHT, -32768, 0);
          XInput.setJoystick(JOY_RIGHT, 0, 0);
          break;
        case 230:
          XInput.setJoystick(JOY_RIGHT, 32767, 0); 
          XInput.setJoystick(JOY_RIGHT, 0, 0);
          break;
        case 231:
          XInput.setJoystick(JOY_RIGHT, 0, -32768);
          XInput.setJoystick(JOY_RIGHT, 0, 0);
          break;
        default:
          Keyboard.press(button_value);
          break;
        }
      }

    void button_release(int button_value){
      switch(button_value){
        case 104:
          Mouse.release(MOUSE_LEFT);
          break;
        case 105:
          Mouse.release(MOUSE_MIDDLE);
          break;
        case 106:
          Mouse.release(MOUSE_RIGHT);
          break;
          case 113:
          XInput.release(BUTTON_Y);
          break;
          case 114:
          XInput.release(BUTTON_X);
          break;
          case 115:
          XInput.release(BUTTON_B);
          break;
          case 116:
          XInput.release(BUTTON_A);
          break;
          case 117:
          XInput.release(TRIGGER_LEFT);
          break;
        case 118:
          XInput.release(TRIGGER_RIGHT);
          break;
          case 119:
          XInput.release(BUTTON_LB);
          break;
        case 120:
          XInput.release(BUTTON_RB);
          break;
          case 121:
          XInput.release(DPAD_UP);
          break;
          case 122:
          XInput.release(DPAD_LEFT);
          break;
          case 123:
          XInput.release(DPAD_RIGHT);
          break;
          case 124:
          XInput.release(DPAD_DOWN);
          break;
          case 125:
          XInput.release(BUTTON_BACK);
          break;
          case 126:
          XInput.release(BUTTON_LOGO);
          break;
          case 127:
          XInput.release(BUTTON_START);
          break;
          case 222:
          XInput.release(BUTTON_L3);
          break;
          case 223:
          XInput.release(BUTTON_R3);
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

        void joy_action(int pressed, int num)
    {
            
        if(pressed >= 5){
          if (num == 0) {
                  button_press(joy_button[3]);  
                  if((joy_button[3] > 106 && joy_button[3] < 113) || (joy_button[3] > 223 && joy_button[3] < 232)){
              joy_comp[num] = 0;
              }
                } else {
                  button_press(joy_button[4]); 
                  if((joy_button[4] > 106 && joy_button[4] < 113) || (joy_button[4] > 223 && joy_button[4] < 232)){
              joy_comp[num] = 0;
              } 
                }
        }else{
        if(pressed <= -5){
          if (num == 0) {
                  button_press(joy_button[2]); 
                  if((joy_button[2] > 106 && joy_button[2] < 113) || (joy_button[2] > 223 && joy_button[2] < 232)){
              joy_comp[num] = 0;
              } 
                } else {
                  button_press(joy_button[1]);  
                  if((joy_button[1] > 106 && joy_button[1] < 113) || (joy_button[1] > 223 && joy_button[1] < 232)){
              joy_comp[num] = 0;
              }
                }
        }else{
          if (num == 0) {
                  button_release(joy_button[2]); 
                  button_release(joy_button[3]);   
                } else {
                  button_release(joy_button[1]); 
                  button_release(joy_button[4]);  
                }
        }
        }
        }
            
          
                                         
        

    void check(){
        if (Serial.available()>0){
        int it = 0;
        int str[10];
        while (Serial.available() > 0)
         {
               str[it] = Serial.read();
               it++;
         } 
         for (int i = 0; i < 5; i++) {
          button[i] = str[i];
          }
         for (int i = 0; i < 5; i++) {
          joy_button[i] = str[i+5];
          }
        }
          joy_value[0] = Esplora.readJoystickX();
          joy_value[1] = Esplora.readJoystickY();
          pressed[0] = Esplora.readJoystickSwitch();
          pressed[1] = Esplora.readButton(SWITCH_UP);
          pressed[2] = Esplora.readButton(SWITCH_LEFT);
          pressed[3] = Esplora.readButton(SWITCH_RIGHT);
          pressed[4] = Esplora.readButton(SWITCH_DOWN);

          for (int i = 0; i < 5; i++) {
            if ((button[i] > 106 && button[i] < 113) || (button[i] > 223 && button[i] < 232)){
              button_action(pressed[i], button[i]);
              }else{
            if(pressed[i] != comp[i]){
              button_action(pressed[i], button[i]);
              comp[i] = pressed[i];
            }
          }
          }
          
          if(joy_button[0]== 101){
            joy_value[0] = map(joy_value[0], -512, 512, 3, -3);  
            joy_value[1] = map(joy_value[1], -512, 512, -3, 3);  
            Mouse.move(joy_value[0], joy_value[1], 0); 
          }
          if(joy_button[0]== 220){
            joy_value[0] = map(joy_value[0], -512, 512, 32767, -32768);  
            joy_value[1] = map(joy_value[1], -512, 512, 32767, -32768);  
            XInput.setJoystick(JOY_LEFT, joy_value[0], joy_value[1]);
          }
          if(joy_button[0]== 221){
            joy_value[0] = map(joy_value[0], -512, 512, 32767, -32768);  
            joy_value[1] = map(joy_value[1], -512, 512, 32767, -32768);  
            XInput.setJoystick(JOY_RIGHT, joy_value[0], joy_value[1]);
          }
          if(joy_button[0]== 102){
            joy_value[0] = map(joy_value[0], -512, 512, 10, -10);  
            joy_value[1] = map(joy_value[1], -512, 512, -10, 10); 
            
            
            for (int i = 0; i < 2; i++) {
              if((joy_value[i] >= 5 && joy_comp[i] < 5) || (joy_value[i] <= -5 && joy_comp[i] > -5) || ((joy_value[i] > -5 && joy_value[i] < 5) && (joy_comp[i] >= 5 || joy_comp[i] <= -5))){
              joy_comp[i] = joy_value[i];
              joy_action(joy_value[i], i);
              }
              }
          }
    }
    

};
#endif // ARDUINOCONTROLLER_H
