#include "mbed.h"

AnalogIn ain(PC_3);                
Serial pc(USBTX, USBRX);            
BusOut led(PC_8, PC_15, PC_14, PC_13, PB_7);  

int main() {
    while(1) {
        float voltage = ain.read() * 5.0; 
        
        if(voltage >= 0.0 && voltage < 1.0) {
            pc.printf("0 to 1V\n");
            led = 0x01;  
        } else if(voltage >= 1.0 && voltage < 2.0) {
            pc.printf("1 to 2V\n");
            led = 0x03;  
        } else if(voltage >= 2.0 && voltage < 3.0) {
            pc.printf("2 to 3V\n");
            led = 0x07; 
        } else if(voltage >= 3.0 && voltage < 4.0) {
            pc.printf("3 to 4V\n");
            led = 0x0F; 
        } else if(voltage >= 4.0 && voltage <= 5.0) {
            pc.printf("4 to 5V\n");
            led = 0x1F; 
        }
        wait(0.5); 
    }
}
