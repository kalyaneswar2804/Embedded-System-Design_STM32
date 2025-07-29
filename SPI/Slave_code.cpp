//Lab Task-1: Read input form master and display on slave.

#include "mbed.h"
SPISlave spi(PB_15, PB_14, PB_13, PB_12);
Serial pc(USBTX, USBRX);
int main(){
  char recd_val; pc.printf("Received word is...\n");
  while (1){
    if(spi.receive()){ 
      recd_val = spi.read();
      pc.printf("%c", recd_val);
    }
  }
}
