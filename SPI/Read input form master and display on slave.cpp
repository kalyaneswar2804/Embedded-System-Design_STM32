//Lab Task-1: Read input form master and display on slave.

#include "mbed.h"
SPI spi(PB_15, PB_14, PB_13);
DigitalOut cs(PB_12);
Serial pc(USBTX, USBRX);
int main(){
  char send_val;
  pc.printf("Press any key to start...\n");
  while (1){
    send_val = pc.getc();
    pc.printf("%c", send_val);
    cs = 0;
    spi.write(send_val);
    cs = 1;
    wait(0.01);
  }
}
