#include "mbed.h"
#include "TextLCD.h"

AnalogIn ldr1(PC_5); 
AnalogIn ldr2(PC_4);
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0); // rs, e, d4-d7
PwmOut servo(PC_8);

int main() {
    servo.period_ms(20);

    while (1) {
        float ldr1_value = ldr1.read();
        float ldr2_value = ldr2.read();

        lcd.locate(1, 0);
        lcd.printf("L1 %.2f", ldr1_value);
        lcd.locate(8, 0);
        lcd.printf(" L2 %.2f", ldr2_value);

        float pulse_width;
        if (ldr1_value > ldr2_value) {
            pulse_width = 1500 + (ldr1_value - ldr2_value) * 1000;
        } else {
            pulse_width = 1500 - (ldr2_value - ldr1_value) * 1000;
        }
        servo.pulsewidth_us(pulse_width);

        float servo_angle = (pulse_width - 500) * 180.0 / 2000.0;

        lcd.locate(0, 1);
        lcd.printf("Servo: %.2f deg", servo_angle);

        wait(0.1);
    }
}
