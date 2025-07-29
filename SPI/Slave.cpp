//Lab Task-3: Half Adder.

#include "mbed.h"
SPISlave ser_port(PB_15, PB_14, PB_13, PB_12);
Serial pc(USBTX, USBRX);
DigitalOut carry_led(PC_8);
DigitalIn switch_B(PC_4);
char A, B, sum, carry;
int main(){
  while(1){
    if(ser_port.receive()){
      A = ser_port.read();
      B = switch_B.read();
      pc.printf("Slave: Received A = %d, B = %d\r\n", A, B);
      sum = A ^ B;
      carry = A & B;
      ser_port.reply(sum);
      carry_led = carry;
      pc.printf("Slave: Sum = %d, Carry = %d\r\n", sum, carry);
    }
  }
}
