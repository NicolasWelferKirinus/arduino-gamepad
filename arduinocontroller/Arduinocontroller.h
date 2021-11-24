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
                } else {
                  button_press(joy_button[4]);  
                }
        }else{
        if(pressed <= -5){
          if (num == 0) {
                  button_press(joy_button[2]);  
                } else {
                  button_press(joy_button[1]);  
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
            if(pressed[i] != comp[i]){
              button_action(pressed[i], button[i]);
              comp[i] = pressed[i];
            }
          }
          
          if(joy_button[0]== 101){
            joy_value[0] = map(joy_value[0], -512, 512, 3, -3);  
            joy_value[1] = map(joy_value[1], -512, 512, -3, 3);  
            Mouse.move(joy_value[0], joy_value[1], 0); 
          }
          if(joy_button[0]== 102){
            joy_value[0] = map(joy_value[0], -512, 512, 10, -10);  
            joy_value[1] = map(joy_value[1], -512, 512, -10, 10); 
            for (int i = 0; i < 2; i++) {
              if((joy_value[i] >= 5 && joy_comp[i] < 5) || (joy_value[i] <= -5 && joy_comp[i] > -5) || ((joy_value[i] > -5 && joy_value[i] < 5) && (joy_comp[i] >= 5 || joy_comp[i] <= -5))){
              joy_action(joy_value[i], i);
              joy_comp[i] = joy_value[i];
              }
          }
    }
    }

};
#endif // ARDUINOCONTROLLER_H
