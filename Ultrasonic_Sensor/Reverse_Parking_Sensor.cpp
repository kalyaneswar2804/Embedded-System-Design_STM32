//Lab Task-2: Write a program to design a reverse parking sensor module. This module consist of HCSR04 ultrasonic sensor, LCD and buzzer interfaced with Nucleo. The ultrasonic sensor
//continuously measure the distance (in cm) between the car and obstacle, then display it on the first row of the LCD. Whenever the measured distance is lesser than 30cm
//generate warning signal to driver using buzzer also display a message â€œObstacle !!!â€ on the second row of the LCD display. Implement and verify this logic on the STM32
//Nucleo-64 board using Keil Studio Cloud IDE.

#include "mbed.h"
#include "TextLCD.h"
TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0); // rs,e,d4-d7
Digitalout trigger(PC_8);
DigitalIn echo(PC_6);
DigitalOut buzzer(PC_10);
int distance = 0;
Timer sonar;
int main(){
  lcd.cls();
  while(1){
    trigger = 1;
    sonar.reset();
    wait_us(10.0);
    trigger = 0;
    while (echo == 0);
    sonar. start();
    while (echo == 1);
    sonar.stop();
    distance = (sonar.read_us())/58.0;
    lcd.locate(0,0);
    lcd.printf("Distance: ",distance);
    wait(0.2);
    if(distance<30){
      buzzer=1;
      lcd.locate(1,1);
      lcd.printf("obstacle !!!");
    }
    else{
      buzzer=0;
    }
  }
}
