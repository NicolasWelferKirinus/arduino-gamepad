#include <Joystick.h>
#include <Esplora.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <XInput.h>

#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H

Joystick_ Joystick(0x03, 0x05, 9, 0, true, true, false, false, false, false, false, false, false, false, false);

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
      Joystick.begin(true);
      Joystick.setXAxis(511);
      Joystick.setYAxis(511);
    }

    void button_press(int button_value){
        switch(button_value){
        case 67:
            Mouse.press(MOUSE_LEFT);
            break;
        case 68:
            Mouse.press(MOUSE_MIDDLE);
            break;
        case 69:
            Mouse.press(MOUSE_RIGHT);
            break;
        case 70:
            Mouse.move(0, -3, 0);
            break;
        case 71:
            Mouse.move(-3, 0, 0);
            break;
        case 72:
            Mouse.move(3, 0, 0);
            break;
        case 73:
            Mouse.move(0, 3, 0);
            break;
        case 74:
            Mouse.move(0, 0, 1);
            break;
        case 75:
            Mouse.move(0, 0, -1);
            break;
        case 76:
            XInput.press(BUTTON_Y);
            break;
        case 77:
            XInput.press(BUTTON_X);
            break;
        case 78:
            XInput.press(BUTTON_B);
            break;
        case 79:
            XInput.press(BUTTON_A);
            break;
        case 80:
            XInput.press(TRIGGER_LEFT);
            break;
        case 81:
            XInput.press(TRIGGER_RIGHT);
            break;
        case 82:
            XInput.press(BUTTON_LB);
            break;
        case 83:
            XInput.press(BUTTON_RB);
            break;
        case 84:
            XInput.press(DPAD_UP);
            break;
        case 85:
            XInput.press(DPAD_LEFT);
            break;
        case 86:
            XInput.press(DPAD_RIGHT);
            break;
        case 87:
            XInput.press(DPAD_DOWN);
            break;
        case 88:
            XInput.press(BUTTON_BACK);
            break;
        case 89:
            XInput.press(BUTTON_LOGO);
            break;
        case 90:
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
        case 240:
        case 241:
        case 242:
        case 243:
        case 244:
        case 245:
        case 246:
        case 247:
        case 248:
            Joystick.setButton(button_value - 240, 1);
            break;
        case 21:
            Joystick.setYAxis(0);
            break;
        case 22:
            Joystick.setXAxis(0);
            break;
        case 23:
            Joystick.setXAxis(1023);
            break;
        case 24:
            Joystick.setYAxis(1023);
            break;
        default:
            Keyboard.press(button_value);
            break;
        }
    }

    void button_release(int button_value){
        switch(button_value){
        case 67:
            Mouse.release(MOUSE_LEFT);
            break;
        case 68:
            Mouse.release(MOUSE_MIDDLE);
            break;
        case 69:
            Mouse.release(MOUSE_RIGHT);
            break;
        case 76:
            XInput.release(BUTTON_Y);
            break;
        case 77:
            XInput.release(BUTTON_X);
            break;
        case 78:
            XInput.release(BUTTON_B);
            break;
        case 79:
            XInput.release(BUTTON_A);
            break;
        case 80:
            XInput.release(TRIGGER_LEFT);
            break;
        case 81:
            XInput.release(TRIGGER_RIGHT);
            break;
        case 82:
            XInput.release(BUTTON_LB);
            break;
        case 83:
            XInput.release(BUTTON_RB);
            break;
        case 84:
            XInput.release(DPAD_UP);
            break;
        case 85:
            XInput.release(DPAD_LEFT);
            break;
        case 86:
            XInput.release(DPAD_RIGHT);
            break;
        case 87:
            XInput.release(DPAD_DOWN);
            break;
        case 88:
            XInput.release(BUTTON_BACK);
            break;
        case 89:
            XInput.release(BUTTON_LOGO);
            break;
        case 90:
            XInput.release(BUTTON_START);
            break;
        case 222:
            XInput.release(BUTTON_L3);
            break;
        case 223:
            XInput.release(BUTTON_R3);
            break;
        case 240:
        case 241:
        case 242:
        case 243:
        case 244:
        case 245:
        case 246:
        case 247:
        case 248:
            Joystick.setButton(button_value - 240, 0);
            break;
        case 21:
            Joystick.setYAxis(511);
            break;
        case 22:
            Joystick.setXAxis(511);
            break;
        case 23:
            Joystick.setXAxis(511);
            break;
        case 24:
            Joystick.setYAxis(511);
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
                if((joy_button[3] > 69 && joy_button[3] < 74) || (joy_button[3] > 223 && joy_button[3] < 232)){
                    joy_comp[num] = 0;
                }
            } else {
                button_press(joy_button[4]);
                if((joy_button[4] > 69 && joy_button[4] < 74) || (joy_button[4] > 223 && joy_button[4] < 232)){
                    joy_comp[num] = 0;
                }
            }
        }else{
            if(pressed <= -5){
                if (num == 0) {
                    button_press(joy_button[2]);
                    if((joy_button[2] > 69 && joy_button[2] < 74) || (joy_button[2] > 223 && joy_button[2] < 232)){
                        joy_comp[num] = 0;
                    }
                } else {
                    button_press(joy_button[1]);
                    if((joy_button[1] > 69 && joy_button[1] < 74) || (joy_button[1] > 223 && joy_button[1] < 232)){
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





    void check_serial(){
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
    }

    void check_buttons(){
        pressed[0] = Esplora.readJoystickSwitch();
        pressed[1] = Esplora.readButton(SWITCH_UP);
        pressed[2] = Esplora.readButton(SWITCH_LEFT);
        pressed[3] = Esplora.readButton(SWITCH_RIGHT);
        pressed[4] = Esplora.readButton(SWITCH_DOWN);

        for (int i = 0; i < 5; i++) {
            if ((button[i] > 69 && button[i] < 74) || (button[i] > 223 && button[i] < 232)){
                button_action(pressed[i], button[i]);
            }else{
                if(pressed[i] != comp[i]){
                    button_action(pressed[i], button[i]);
                    comp[i] = pressed[i];
                }
            }
        }
    }

    void check_joy(){
        joy_value[0] = Esplora.readJoystickX();
        joy_value[1] = Esplora.readJoystickY();
        switch(joy_button[0]){
          case 65:
            joy_value[0] = map(joy_value[0], -512, 512, 3, -3);
            joy_value[1] = map(joy_value[1], -512, 512, -3, 3);
            Mouse.move(joy_value[0], joy_value[1], 0);
            break;
        case 220:
            joy_value[0] = map(joy_value[0], -512, 512, 32767, -32768);
            joy_value[1] = map(joy_value[1], -512, 512, 32767, -32768);
            XInput.setJoystick(JOY_LEFT, joy_value[0], joy_value[1]);
            break;
        case 221:
            joy_value[0] = map(joy_value[0], -512, 512, 32767, -32768);
            joy_value[1] = map(joy_value[1], -512, 512, 32767, -32768);
            XInput.setJoystick(JOY_RIGHT, joy_value[0], joy_value[1]);
            break;
        case 249:
            joy_value[0] = map(joy_value[0], -512, 512, 1023, 0);
            joy_value[1] = map(joy_value[1], -512, 512, 0, 1023);
            Joystick.setXAxis(joy_value[0]);
            Joystick.setYAxis(joy_value[1]);
            break;
        case 66:
            joy_value[0] = map(joy_value[0], -512, 512, 10, -10);
            joy_value[1] = map(joy_value[1], -512, 512, -10, 10);
            for (int i = 0; i < 2; i++) {
                if((joy_value[i] >= 5 && joy_comp[i] < 5) || (joy_value[i] <= -5 && joy_comp[i] > -5) || ((joy_value[i] > -5 && joy_value[i] < 5) && (joy_comp[i] >= 5 || joy_comp[i] <= -5))){
                    joy_comp[i] = joy_value[i];
                    joy_action(joy_value[i], i);
                    }
            }
            break;
        }
    }

};
#endif // ARDUINOCONTROLLER_H
