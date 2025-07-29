//Lab Task-3: Write a mbed C++program to design home security system that consists of three main modules (1) Intruder detection (2) Activate fence light during night time (2) password
//based door lock system. (Challenging Task)

#include "mbed.h"
#include "keypad.h"
#include "TextLCD.h"
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);
Keypad keypad(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8, PA_9, PC_7);
DigitalOut buzz(PC_6);
PwmOut servo(PC_8);
DigitalIn pirSensor(PC_9); // PIR motion sensor
AnalogIn ldr(PC_4); // LDR for light detection
DigitalOut fenceLight(PB_2);
const char ACTUAL_PW[4] = {'1', '2', '4', '5'};
char PW_ENTERED[4];
int count;
int main(){
  keypad.enablePullUp();
  servo.period_ms(20);
  servo.pulsewidth_us(500); // Lock door position
  buzz = 0;
  while (1){
    // *Intruder Detection (PIR Sensor)*
    if (pirSensor.read() == 1){
      lcd.cls();
      lcd.locate(0, 0);
      lcd.printf("Intruder Alert!");
      buzz = 1;
      wait(2);
      buzz = 0;
    }
    // *Fence Light Activation (LDR)*
    if (ldr.read() < 0.3) { // If it's dark
      fenceLight = 1; // Turn on lights
    }
    else{
      fenceLight = 0; // Turn off lights
    }
    // *Password-Based Door Lock*
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("Enter password:");
    count = 0;
    while (count < 4){
      char key = '\0';
      while (key == '\0'){
        key = keypad.getKey(); // Wait for key press
      }
      PW_ENTERED[count] = key;
      lcd.locate(count, 1);
      lcd.printf(""); // Display '' for entered digits
      count++;
      wait(0.5); // Debounce delay
    }
    bool correct = true;
    for(int i = 0; i < 4; i++){
      if(PW_ENTERED[i] != ACTUAL_PW[i]){
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
      buzz = 0;
      servo.pulsewidth_us(2000); // Unlock door
      wait(3);
      servo.pulsewidth_us(500); // Lock door again
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
