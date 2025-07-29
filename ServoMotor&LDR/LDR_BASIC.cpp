//Lab Task-2: Write a program to design auto intensity street light controller. This system helps the street light to get switched on automatically as per surrounding brightness. 
//For example, sometimes when the weather become hazy its quite difficult to see anything then at that point this auto intensity street light gets switched ON based on present
//lighting condition. Implement and verify this logic on STM32 board.

#include "mbed.h"
PwmOut PWM1(PC_8);
AnalogIn Ain(PC_3);
int main(){
  while (1){
    PWM1.period(0.010); //PWM period = 10 milli seconds
    PWM1=1-Ain;
    wait(0.1);
  }
}
