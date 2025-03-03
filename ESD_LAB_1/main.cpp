#include "mbed.h"

DigitalOut myled(PC_4);
DigitalOut myled2(PB_13);
DigitalOut myled3(PB_14);
DigitalOut myled4(PB_15);

int main() {
  while(1) {
    myled = 1;
    myled2 = 0;
    myled3 = 1;
    myled4 = 0;
    wait(0.2);
    myled = 0;
    myled2 = 1;
    myled3 = 0;
    myled4 = 1;
    wait(0.2);
  }
}
