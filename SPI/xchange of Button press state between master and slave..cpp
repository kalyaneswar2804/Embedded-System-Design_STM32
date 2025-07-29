//Lab Task-2: Exchange of Button press state between master and slave.

#include "mbed.h"
SPI ser_port(PB_15, PB_14, PB_13);
DigitalOut cs(PB_12);
Serial pc(USBTX, USBRX);
DigitalOut led(PC_8);
DigitalIn switch_ip(PC_4);
int switch_word_tx;
char tx_val;
int main(){ 
  while (1){
    switch_word_tx = 0x00;
    if(switch_ip == 1) switch_word_tx = switch_word_tx | 0x01;
    cs = 0;
    tx_val = ser_port.write(switch_word_tx);
    cs = 1;
    wait(1);
    led = 0;
    tx_val = tx_val & 0x01;
    if (tx_val == 1) led = 1;
  }
}
