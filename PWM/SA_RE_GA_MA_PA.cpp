//Lab Task-3: Write a C++ code with mbed APIs to generate a music note SA-RE-GA-MA-PA-THANEE on the buzzer using PWM signal.

#include "mbed.h"
PwmOut speaker(PC_8);
int main(){
  while(true){
    speaker.period(1.0/240.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/270.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/300.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/337.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/360.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/400.0); speaker=0.5; wait(0.5);
    speaker.period(1.0/450.0); speaker=0.5; wait(0.5);
    speaker=0.0;
  }
}
