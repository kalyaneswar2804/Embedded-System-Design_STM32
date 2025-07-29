//Lab Task-2: Write a C++ program with mbed APIs to blink one LED at a time serially in a group of 4 LEDs using switch. 
//If switch is LOW, blink the LEDs one at a time from left to right (1000, 0100, 0010, 0001 pattern) with 0.5 Sec delay between each.
//If switch is HIGH, blink the LEDs one at a time from right to left (0001, 0010, 0100, 1000 pattern) with 0.5 Sec delay between each.

#include "mbed.h"
DigitalIn switch1(PC_13);
BusOut myled(PC_4,PB_13,PB_14,PB_15);
int main(){
  while(1){
    if(switch1==0){
      myled=8; wait(0.5);
      myled=4; wait(0.5);
      myled=2; wait(0.5);
      myled=1; wait(0.5);
    }
    else{
      myled=1; wait(0.5);
      myled=2; wait(0.5);
      myled=4; wait(0.5);
      myled=8; wait(0.5);
    }
  }
}
