//Lab Task-3: Write a C++ program with mbed APIs to gradually increase and decrease LED brightness by changing the position of the Potentiometer via ADC. Also print itâ€™s
//voltage value on serial monitor. Use Implement and verify this logic on the STM32 Nucleo-64 board using Keil Studio Cloud IDE.

#include "mbed.h"
Serial pc(USBTX,USBRX);
AnalogIn ain(PC_3);
PwmOut PWM1(PC_8);
int main(){
  while(1){
    float value =ain*5;
    pc.printf("The reading of pot:%f",value);
    wait(1);
    PWM1.period(0.01);
    PWM1=ain;
  }
}
