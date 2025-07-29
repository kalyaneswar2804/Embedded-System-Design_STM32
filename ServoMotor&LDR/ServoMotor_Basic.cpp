//Lab Task-1: Write a program to control the servo motor by rotating slowly from 0 degrees to 180 degrees, 45 degree at a time. When the motor has to be rotated 180 degrees, it will
//return to the initial position. Implement and verify this logic on STM32 board.

#include "mbed.h"
PwmOut PWM1(PC_8);
int main(){
  while(1){
    PWM1.period_ms(20); 
    PWM1.pulsewidth_us(500); // 45 degree
    wait(1);
    PWM1.pulsewidth_us(1000); // 45 degree
    wait(1);
    PWM1.pulsewidth_us(1500); // 90 degree
    wait(1);
    PWM1.pulsewidth_us(2000); // 135 degree
    wait(1);
    PWM1.pulsewidth_us(2500); // 180 degree
    wait(1);
  }
}
