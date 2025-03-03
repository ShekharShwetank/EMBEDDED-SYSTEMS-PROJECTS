#include "mbed.h"

Serial pc(USBTX, USBRX);
Serial bt(PC_10, PC_11);

AnalogIn lm35(PC_5);
DigitalOut buzz(PB_8);

int main() {
    pc.baud(9600);
    bt.baud(9600);
    pc.printf("Temperature Monitoring System Initialized!\n\r");

    while (1) {
            float temp = lm35.read() * 100.00;

            pc.printf("Temperature: %.2f degC\n\r", temp);
            bt.printf("Temperature: %.2f degC\n\r", temp);

            if (temp > 7.00) {
                buzz = 1;
                pc.printf("Temperature exceeds 15 degC! Buzzer ON\n\r");
                bt.printf("Temperature exceeds 15 degC! Buzzer ON\n\r");
            } else {
                buzz = 0;
            }
            wait(1);
        }
    }
