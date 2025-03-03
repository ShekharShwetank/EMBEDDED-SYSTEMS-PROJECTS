#include "mbed.h"

Serial PC(USBTX, USBRX);
PwmOut led(PC_8);
float brtnes = 0.0;

int main() {
  while(1) {
    PC.printf("Enter i -> inc / d -> dec");
    char c= PC.getc();
    if(c == 'i'){
        PC.printf("Increasing by 10%. \r\n");
        brtnes += 0.1;
        led = brtnes;
    }
    if(c == 'd' && brtnes > 0.0){
        PC.printf("Decreasing by 10%. \r\n");
        brtnes -= 0.1;
        led = brtnes;
    }
  }
}
