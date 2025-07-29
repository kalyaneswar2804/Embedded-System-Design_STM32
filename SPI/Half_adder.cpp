//Lab Task-3: Half Adder.

#include "mbed.h"
SPI ser_port(PB_15, PB_14, PB_13);
DigitalOut cs(PB_12);
Serial pc(USBTX, USBRX);
DigitalOut sum_led(PC_8);
DigitalIn switch_A(PC_4);
char received_sum; 
int A;
int main(){
  ser_port.format(8, 0);
  ser_port.frequency(1000000);
  cs = 1;
  while(1){
    A = switch_A.read();
    pc.printf("Master: A = %d\r\n", A);
    cs = 0;
    wait_us(10);
    received_sum = ser_port.write(A);
    wait_us(10);
    cs = 1;
    pc.printf("Master Received Sum: %x\r\n", received_sum);
    sum_led = received_sum;
    wait(0.5);
  }
}
