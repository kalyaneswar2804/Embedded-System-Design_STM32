//Lab Task-3: Write a program to display the potentiometer value with 4 decimal places on the LCD display on row-1 5th position. Assume LCD operates in 4 bit with EN and RS active state. 
//Design and verify this logic on Nucleo-L152RE board using online Keil Studio Platform.

#include "mbed.h"
#include "TextLCD.h"
AnalogIn ain(PC_5);
TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0); // rs,e,d4-d7
int main(){
  lcd.cls();
  while(1) {
    float value = ain*5;
    lcd.locate(5,0);
    lcd.printf("v = %0.3f",value);
    wait(2);
    lcd.cls();
    wait(1);
  }
} 
