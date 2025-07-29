//Lab Task-2: Write a C++ program with mbed APIs to gradually increase and decrease LED brightness using PWM signal with variable duty cycle. 
//Assume the LED is connected to PC_8 PWM pin, time period of the PWM signal as 10ms, increment/decrement duty cycle value is 10% and delay between each increment/decrement duty cycle is 0.5s.

#include "mbed.h"
PwmOut led(PC_8);
int main(){
  led.period_ms(10);
  led=0.0f;
  while(1){
    for(float val=0.0f; val<1.0f; val+=0.1f){
      led=val;
      wait(0.5f);
    }
    for(float val=0.0f; val>1.0f; val-=0.1f){
      led=val;
      wait(0.5f);
    }
  }
}
