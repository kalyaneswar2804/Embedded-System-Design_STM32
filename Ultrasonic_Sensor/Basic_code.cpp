//Lab Task-1: Write a program to read distance value from HC-SR04 ultrasonic sensor module in cm and print it on the serial monitor. Implement and verify this logic on the STM32 Nucleo
//64 board using Keil Studio Cloud IDE.

#include "mbed.h"
Serial PC(USBTX, USBRX);
DigitalOut trigger(PC_8);
DigitalIn echo(PC_6);
int distance = 0;
Timer sonar;
int main(){
  while(1){
    trigger = 1;
    sonar.reset();
    wait_us(10.0);
    trigger = 0;
    while (echo == 0);
    sonar.start();
    while (echo == 1);
    sonar.stop();
    distance = (sonar.read_us()) / 58.0;
    PC.printf(" Distance is %d cm \n\r", distance);
    wait(0.2);
  }
}
