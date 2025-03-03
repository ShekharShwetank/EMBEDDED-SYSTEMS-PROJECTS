#include "mbed.h"

Serial pc(USBTX,USBRX);
Serial bt(PC_10,PC_11);
DigitalOut led(PC_8);
DigitalOut buzz(PB_8);

int main(){
    char ch;
    bt.baud(9600);
    pc.baud(9600);
    pc.printf("1204 TASK 2\n\r");
    while(1)
    if(bt.readable()){
        ch = bt.getc();
        if(ch == '1'){
            led = 0;
            pc.printf("LED OFF\n\r");
        }
        if(ch == '2'){
            led = 1;
            pc.printf("LED ON\n\r");
        }
        if(ch == '3'){
            buzz = 0;
            pc.printf("BUZZER OFF\n\r");
        }
        if(ch == '4'){
            buzz = 1;
            pc.printf("BUZZER ON\n\r");
        }
    }
}
