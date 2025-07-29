//Lab Task-3: Blinking one LED at a time serially (1000, 0100, 0010, 0001)

#include "mbed.h"
DigitalOut myled1(PC_4);
DigitalOut myled2(PB_13);
DigitalOut myled3(PB_14);
DigitalOut myled4(PB_15);
int main(){
  while(1){
    myled1 = 1; myled2 = 0; myled3 = 0; myled4 = 0; wait(0.5);
    myled1 = 0; myled2 = 1; myled3 = 0; myled4 = 0; wait(0.5);
    myled1 = 0; myled2 = 0; myled3 = 1; myled4 = 0; wait(0.5);
    myled1 = 0; myled2 = 0; myled3 = 0; myled4 = 1; wait(0.5);
  }
}
