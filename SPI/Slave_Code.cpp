//Lab Task-2: Exchange of Button press state between master and slave.

#include "mbed.h"
SPISlave ser_port(PB_15, PB_14, PB_13, PB_12);
Serial pc(USBTX, USBRX);
DigitalOut led(PC_8);
DigitalIn switch_ip(PC_4);
int switch_word_rx;
char rx_val;
int main(){
  while(1){
    switch_word_rx = 0x00;
    if(switch_ip == 1){
      switch_word_rx = switch_word_rx | 0x01;
    }
    if(ser_port.receive()){
      rx_val = ser_port.read();
      ser_port.reply(switch_word_rx);
    }
    led = 0;
    rx_val = rx_val & 0x01;
    if(rx_val == 1){
      led = 1;
    }
  }
}
