#include "mbed.h"

DigitalIn switch1(PC_10);
BusOut N(PB_13,PB_14,PB_15);
BusOut S(PC_5,PC_6,PC_8);
BusOut E(PA_15,PA_14,PA_13);
BusOut W(PC_15,PC_14,PC_13);
int main(){
    while(1){
        if (switch1 == 1){
            E = 1;
            W = 1;
            N = 3;
            S = 3;
            wait(15);
            E = 2;
            W = 2;
            N = 3;
            S = 3;
            wait(2);
            E = 3;
            W = 3;
            N = 1;
            S = 1;
            wait(10);
            E = 3;
            W = 3;
            N = 2;
            S = 2;
            wait(2);
        } 
        else{
            N = 2;
            S = 2;
            W = 2;
            E = 2;
            wait(2);
        }
    }
}