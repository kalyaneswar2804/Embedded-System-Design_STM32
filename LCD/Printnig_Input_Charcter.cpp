//Lab Task-2: Write a program that accepts a serial input character via the â€œTeratermâ€ software from a host computer and displays it on the LCD. Assume LCD operates in 4-bit with EN
//and RS active state. Design and verify this logic on Nucleo-152RE board using online Keil Studio platform.

#include "mbed.h"
#include "TextLCD.h"
TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0); // rs, e, d4-d7
Serial pc(USBTX,USBRX);
int main(){
  while(1){
    pc.printf("\nPress a Character: ");
    char y=pc.getc();
    lcd.locate(3,0);
    lcd.putc(y);
    pc.putc(y);
  }
}
