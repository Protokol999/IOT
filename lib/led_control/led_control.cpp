#include "led_control.h"

void led_control_setup(const uint8_t pin) {
    pinMode(pin, OUTPUT);
}

void led_control_on(const uint8_t pin) {
    digitalWrite(pin, HIGH);
}

void led_control_off(const uint8_t pin) {
    digitalWrite(pin, LOW);
}
