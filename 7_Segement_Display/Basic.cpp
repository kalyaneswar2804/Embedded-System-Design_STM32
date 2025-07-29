//Lab Task-1: Write a mbed C++ program to display decimal values from 0 to 9 on the 7-segment display interfaced with digital pins of Nucleo boards. Once the sequence completed
// from 0 to 9 then repeat the sequence again. Design and implement this logic on the STM 32 Nucleo L152RE board using Keil studio could platform.

#include "mbed.h"
BusOut display (PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9,PC_7);
int main(){
  while(1){
    for(int i=0; i<=16; i++){
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
}
