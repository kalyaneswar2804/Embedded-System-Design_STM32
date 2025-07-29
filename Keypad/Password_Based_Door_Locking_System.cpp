//Lab Task-2: Write a mbed C++ program to design a password based door locking system in which the system accept 4-digit password (last 4-digit of your reg. no) via keypad. Use the
//LCD display to message â€œEnter Passwordâ€ on the first line and display * symbol on the second line of the LCD to represent every digit of the password entered. Check whether entered password 
//matches with actual password, if matched activate the servo to open the door else also display message â€œCorrect Passwordâ€ on LCD first line and â€œDoor openingâ€ message on the LCD second line. 
//If password not matched, activate the buzzer also display message â€œIncorrect Passwordâ€ on LCD first line and â€œDoor canâ€™t openâ€ message on the LCD second line. Assume LCD operates in 4-bit with EN
//and RS active state. Design and verify this logic on Nucleo 152RE board using online Keil Studio platform.

#include "mbed.h"
#include "keypad.h"
#include "TextLCD.h"
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);
Keypad keypad(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8, PA_9, PC_7);
DigitalOut buzz(PC_6);
PwmOut servo(PC_8);
const char ACTUAL_PW[4] = {'1', '2', '3', '4'};
char PW_ENTERED[4];
int count;
int main(){
  keypad.enablePullUp();
  while(1){
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("Enter password:");
    servo.period_ms(20);
    servo.pulsewidth_us(500);
    buzz = 0;
    count = 0;
    while(count < 4){
      char key = '\0';
      while (key == '\0'){
        key = keypad.getKey();
      }
      PW_ENTERED[count] = key;
      lcd.locate(count, 1);
      lcd.printf("*");
      count++;
      wait(0.5);
    }
    bool correct = true;
    for(int i = 0; i < 4; i++){
      if (PW_ENTERED[i] != ACTUAL_PW[i]){
        correct = false;
        break;
      }
    }
    lcd.cls();
    if(correct){
      lcd.locate(0, 0);
      lcd.printf("Correct Password");
      lcd.locate(0, 1);
      lcd.printf("Door opening...");
      servo.pulsewidth_us(2000);
      wait(3);
      servo.pulsewidth_us(500);
    }
    else{
      lcd.locate(0, 0);
      lcd.printf("Incorrect Password");
      lcd.locate(0, 1);
      lcd.printf("Door can't open");
      buzz = 1;
      wait(2);
      buzz = 0;
    }
  }
}
