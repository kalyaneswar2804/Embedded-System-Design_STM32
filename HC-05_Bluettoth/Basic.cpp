//Lab Task-1: Print name and registration number in smartphone serial console

#include "mbed.h"
Serial pc(USBTX, USBRX);
Serial bt(PC_10, PC_11);
int main(){
  pc.baud(9600);
  bt.baud(9600);
  pc.printf("Hello!\n\r");
  char c; 
  while(1){ 
    if(pc.readable()){
      c = pc.getc();
      pc.printf("%c", c);
      bt.printf("%c", c);
    }
    else if(bt.readable()){
      c = bt.getc();
      pc.printf("%c", c);
      bt.printf("%c", c);
    }
  }
} 
