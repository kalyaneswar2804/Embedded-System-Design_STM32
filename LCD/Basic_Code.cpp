//Lab Task-1: Write a program for 16x2 LCD to display your register number (ex: â€œ20BEC1001â€) at row-0 3rd position and your name (ex: â€œABCDEFGHâ€) at beginning of the row-1.
// Assume LCD operates in 4-bit with EN and RS active state. Design and verify this logic on the Nucleo-L152RE board using online Keil Studio platform.

#include "mbed.h"
#include "TextLCD.h"
TextLCD lcd(PC_0,PC_1,PB_0,PA_4, PA_1, PA_0); // rs, e, d4-d7
int main() {
  lcd.locate(3,0);
  lcd.printf("22BEC1219\n");
  lcd.locate(0,1);
  lcd.printf("Kalyaneswar M\n");
}
