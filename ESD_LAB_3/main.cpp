#include "mbed.h"

BusIn ip(PB_7, PC_13, PC_14, PC_15); 
PwmOut buzz(PC_8);

void generate_signal(float frequency) {
    buzz.period(1.0 / frequency);
    buzz.write(0.5);
    wait(0.5);
    buzz.write(0.0);
    wait(0.5);
}

int main() {
    while (true) {
        if (ip == 8) {
            generate_signal(2.0); 
        } else if (ip == 4) {
            generate_signal(400.0);
        } else if (ip == 2) {
            generate_signal(612.0); 
        } else if (ip == 1) {
            generate_signal(1000.0); 
        } else {
            buzz.write(0.0); 
        }
    }
}


