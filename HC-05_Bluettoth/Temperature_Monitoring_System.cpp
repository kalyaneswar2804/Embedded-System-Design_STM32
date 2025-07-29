//Lab Task-3: Temperature monitoring system 

#include "mbed.h"
Serial bt(PC_10, PC_11);
AnalogIn temp(PC_5);
DigitalOut buz(PC_8);
int main(){
  bt.baud(9600);
  bt.printf("Temprature sensing");
  while(1){
    float read = temp * 500;
    bt.printf("Temperature is %.4f\n\r", read);
    if(read > 35.0) buz = 1;
    else buz = 0;
    wait(1);
  }
} 
