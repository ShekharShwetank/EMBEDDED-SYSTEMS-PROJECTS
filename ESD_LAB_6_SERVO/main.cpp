#include "mbed.h"

//find out why the values are the what they are.

PwmOut PWM(PC_8);

int main(){
    while(1){
        PWM.period_ms(20);

        PWM.pulsewidth_us(500);
        wait(1);

        PWM.pulsewidth_us(1000);
        wait(1);

        PWM.pulsewidth_us(1500);
        wait(1);

        PWM.pulsewidth_us(2000);
        wait(1);

        PWM.pulsewidth_us(2500);
        wait(1);
    }
}