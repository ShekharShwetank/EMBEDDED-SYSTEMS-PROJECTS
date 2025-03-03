#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);

Serial PC(USBTX, USBRX);

DigitalIn entry_echo(PC_6);
DigitalOut entry_trig(PC_8);

DigitalIn exit_echo(PA_11);
DigitalOut exit_trig(PA_12);

DigitalOut buzz(PB_2);

PwmOut gate(PB_1);
Timer sonar_entry;
Timer sonar_exit;

int slots = 9;

void display_slots() {
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("Smart Parking");
    lcd.locate(0, 1);
    lcd.printf("Avail. slot: %d", slots);
}

void open_gate() {
    gate.period_ms(20);
    gate.pulsewidth_us(2000);
    wait(10);
    gate.pulsewidth_us(1000);
}

int get_distance(Timer &sonar, DigitalOut &trig, DigitalIn &echo) {
    trig = 1;
    wait_us(10);
    trig = 0;
    sonar.reset();
    while (echo == 0);
    sonar.start();
    while (echo == 1);
    sonar.stop();
    return sonar.read_us() / 58.0;
}

void check_entry() {
    int distance = get_distance(sonar_entry, entry_trig, entry_echo);
    if (distance < 20 && slots > 0) {
        slots--;
        display_slots();
        open_gate();
    } else if (distance < 20 && slots == 0) {
        buzz = 1;
        lcd.locate(0, 1);
        lcd.printf("No Parking slot");
        wait(5);
        buzz = 0;
        display_slots();
    }
}

void check_exit() {
    int distance = get_distance(sonar_exit, exit_trig, exit_echo);
    if (distance < 20) {
        slots++;
        display_slots();
        open_gate();
    }
}

int main() {
    display_slots();
    while (1) {
        check_entry();
        check_exit();
        wait(0.1);
    }
}
