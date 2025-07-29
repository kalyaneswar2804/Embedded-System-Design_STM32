//Lab Task-3: Write a C++ program with mbed APIs to design a traffic light controller system for a four lane junction (North, South, East, West) to coordinate the traffic moves.

#include "mbed.h"
DigitalOut r1(PB_4);
DigitalOut y1(PB_5);
DigitalOut g1(PB_3);
DigitalOut r2(PA_5);
DigitalOut y2(PA_6);
DigitalOut g2(PA_7);
DigitalIn switch1(PC_13);
int main() {
  while(1) {
    if(switch1==1){
      r1=1; y1=0; g1=0;
      r2=1; y2=0; g2=0;
      wait(1);
      r2=0; y2=1; g2=0;
      wait(2);
      r2=0; y2=0; g2=1;
      wait(15);
      r1=1; y1=0; g1=0;
      r2=1; y2=0; g2=0;
      wait(1);
      r1=0; y1=1; g1=0;
      wait(2);
      r1=0; y1=0; g1=1;
      wait(15);
    }
    else{
      r1=0; r2=0; 
      g1=0; g2=0;
      y1=1; y2=1;
      wait(2);
      r1=0; r2=0;
      g1=0; g2=0;
      y1=0; y2=0;
      wait(2);
    }
  }
}
