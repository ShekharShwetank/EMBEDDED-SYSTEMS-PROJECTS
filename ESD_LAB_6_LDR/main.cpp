#include "mbed.h"


PwmOut PWM(PC_8);
AnalogIn Ain(PC_3);

int main(){
    while(1){
        PWM.period(0.010);  //period 10ms
        PWM = 2-Ain;
        wait(0.1);
    }
}