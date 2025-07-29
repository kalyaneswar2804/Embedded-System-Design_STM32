//Lab Task-1: Write a mbed C++ program to accepts input from a 4x3 keypad and displays it on the serial monitor and LCD. Assume LCD operates in 4-bit with EN and RS active state.
//Design and verify this logic on Nucleo 152RE board using online Keil Studio platform.

#include "mbed.h"
#include "keypad.h"
#include "TextLCD.h"
Serial pc(USBTX, USBRX);`
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);
Keypad keypad(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8, PA_9, PC_7);
char key;
int main(){
  keypad.enablePullUp();
  lcd.printf("Pressed Key: ");
  pc.printf("Pressed Key: \n\r");
  while(1){
    while(keypad.getKey() == '\0');
    key = keypad.getKey();
    lcd.locate(12,0);
    lcd.printf("%c", key);
    pc.printf("%c\r\n", key);
    wait(1);
  }
}
