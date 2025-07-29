//Lab Task-3: Write a program to design smart parking system using HC-SR04 ultrasonic sensor, servo motor, buzzer, LCD and STM32 Nucleo-64 board. (Challenging Task)

#include "mbed.h"
#include "TextLCD.h"
PwmOut PW(PC_9);
TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0);
DigitalOut trigger(PC_8);
DigitalIn echo(PC_6);
DigitalOut buzzer(PC_10);
int distance =0;
Timer sonar;
int count = 5;
int main(){
  lcd.cls();
  while(1){
    lcd.locate(0,0); lcd.printf("Smart Parking");
    lcd.locate(1,1); lcd.printf("Av Slot: %d",count);
    wait(0.2);
    trigger = 1;
    sonar.reset();
    wait_us(10.0);
    trigger =0;
    while(echo==0);
    sonar.start();
    while(echo==1);
    sonar.stop();
    distance=(sonar.read_us())/58.0;
    if(distance<10 && count<=5){
      PW.pulsewidth_us(1500);
      count = count-1;
      wait(1.0);
      PW.pulsewidth_us(500);
      if(count==-1) count=0;
    }
    else if(count==0){
      buzzer=1;
      lcd.locate(1,1);
      lcd.printf("No Parking Slot");
      wait(1.0);
    }
    wait(1.0);
    lcd.cls();
  }
}
