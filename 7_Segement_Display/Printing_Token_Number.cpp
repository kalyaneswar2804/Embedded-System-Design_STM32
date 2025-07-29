//Lab Task-2: Write a mbed C++ program to design a token display system which helps to serve the customer without the need of standing in a queue. This display system consist of one
//7-segment display to display token numbers from 0 to 9, and token numbers are received into Nucleo board via 4x3 keypad. Design and implement this logic on the
//STM 32 Nucleo L152RE board using Keil studio could platform.

#include "mbed.h"
#include "keypad.h"
Keypad keypad (PC_0, PC_1, PB_0, PC_8, PA_4, PA_1, PA_0);
BusOut display (PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9,PC_7);
char i;
int main(){
  keypad.enablePullUp();
  while(1){
    while(keypad.getKey() == '\0');
    i = keypad.getKey();
    switch(i){
      case 0: display=0xc0; break;
      case 1: display=0xf9; break;
      case 2: display=0xa4; break;
      case 3: display=0xb0; break;
      case 4: display=0x99; break;
      case 5: display=0x92; break;
      case 6: display=0x82; break;
      case 7: display=0xf8; break;
      case 8: display=0x80; break;
      case 9: display=0x90; break;
      case 10: display=0x88; break;
      case 11: display=0x83; break;
      case 12: display=0xc6; break;
      case 13: display=0xa1; break;
      case 14: display=0x86; break;
      case 15: display=0x8e; break;
    }
    wait(0.5);
  }
}
