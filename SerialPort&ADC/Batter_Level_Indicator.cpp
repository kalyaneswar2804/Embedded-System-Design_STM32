//Lab Task-4: Write a C++ program with mbed APIs to design a battery level indicator system using potentiometer and LEDs.

#include "mbed.h"
Serial pc(USBTX,USBRX);
AnalogIn ain(PC_3);
BusOut led(PC_8,PC_2,PC_6,PC_5,PC_4);
int main(){
  while(1){
    float value=ain*5;
    pc.printf("The reading of pot:%f\r\n",value);
    if(value>0 && value<=1){
      pc.printf("0 to 1V\r\n");
      led=16;//10000
      wait(0.5);
    }
    if(value>1 && value<=2){
      pc.printf("1 to 2V\r\n");
      led=24;//11000
      wait(0.5);
    }
    if(value>2 && value<=3){
      pc.printf("2 to 3V\r\n");
      led=28;//11100
      wait(0.5);
    }
    if(value>3 && value<=4){
      pc.printf("3 to 4V\r\n");
      led=30;//11110
      wait(0.5);
    }
    if(value>4 && value<=5){
      pc.printf("4 to 5V\r\n");
      led=31;//11111
      wait(0.5);
    }
  }
}
