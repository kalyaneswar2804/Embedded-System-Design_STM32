//Lab Task-2: Home automation with LED and buzzer

#include "mbed.h"
Serial bt(PC_10, PC_11);
DigitalOut led(LED1);
DigitalOut buz(PC_8);
int main(){
  bt.baud(9600);
  bt.printf("Hello, world!");
  while(1){
    if(bt.readable()){
      char c = bt.getc();
      switch(c){
        case '1': led = 1; bt.printf("LED is ON"); break; 
        case '2': led = 0; bt.printf("LED is OFF"); break;
        case '3': buz = 1; bt.printf("Buzzer is ON"); break; 
        case '4': buz = 0; bt.printf("Buzzer is OFF"); break;
      }
    }
  }
} 
