#include "mbed.h"

Serial pc(USBTX,USBRX);
Serial bt(PC_10,PC_11);

int main(){
    char ch;
    pc.baud(9600);
    bt.baud(9600);
    pc.printf("Bluetooth working\n\r");
    pc.printf("22BEC1204");
    bt.printf("22BEC1204");
    while(1){
        if(bt.readable()){
            ch=bt.getc();
            pc.printf("%c",ch);
        }
        else if(pc.readable()){
            ch=pc.getc();
            bt.printf("%C",ch);
        }
    }
}
