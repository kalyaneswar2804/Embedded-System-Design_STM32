//Lab Task-4: Write a C++ program with mbed APIs to design a warning signals system for an Automotive

#include "mbed.h"
BusIn myswitch(PC_4,PB_13,PB_14,PB_15);
PwmOut speaker(PC_8);
int main(){
  while(1){
    if(myswitch==1){
      speaker.period(1.0/2.0); speaker=0.5; wait(0.5);
    }
    else if(myswitch==2){
      speaker.period(1.0/400.0); speaker=0.5; wait(0.5);
    }
    else if(myswitch==4){
      speaker.period(1.0/612.0); speaker=0.5; wait(0.5);
    }
    else if (myswitch==8){
      speaker.period(1.0/1000.0); speaker=0.5; wait(0.5);
    }
    else{
      speaker.period(1.0/240.0); speaker=0; wait(0.5);
    }
  }
}
