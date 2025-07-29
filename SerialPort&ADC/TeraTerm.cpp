//Lab Task-1: Write a C++ code with mbed APIs to receive a character (H) from PC via host terminal application (Tera term) & switch ON the on-board LED1. 
//For all other character LED1 must be in OFF state. Implement and verify this logic on the STM32 Nucleo-64 board using Keil Studio Cloud IDE.

#include "mbed.h"
Serial pc(USBTX,USBRX);
DigitalOut myled(PC_8);
int main(){
  printf("Press a character");
  while(1){
    int y=pc.getc();
    printf("%c\n",y);
    if(y=='H'){
      myled=1;
      wait(0.2);
    }
    else{
      myled=0;
    }
  }
}
