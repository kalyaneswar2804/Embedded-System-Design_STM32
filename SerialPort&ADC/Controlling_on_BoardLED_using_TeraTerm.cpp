//Lab Task-2: Write a C++ program with mbed APIs to gradually increase and decrease on-board LED brightness by receiving a character (â€œiâ€ for increase and â€œdâ€ for decrease) from
//PC via host terminal application (Tera term) using PWM signal with variable duty cycle. Implement and verify this logic on the STM32 Nucleo-64 board using Keil Studio Cloud IDE.

#include "mbed.h"
Serial pc(USBTX,USBRX);
PwmOut led(PC_8);
float brightness=0.0;
int main(){
  while(1){
    pc.printf("Enter the command to increase/decrease the brightness(i/d)");
    char c =pc.getc();
    if((c=='i')){
      pc.printf("Increasing the brightness by 10%: \r\n");
      brightness+=0.1;
      led = brightness;
    }
    if((c=='d')&&(brightness>0.0)){
      pc.printf("decreasing the brightness by 10%: \r\n");
      brightness -=0.1;
      led = brightness;
    }
  }
}
