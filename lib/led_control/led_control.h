#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>

void led_control_setup(const uint8_t pin);
void led_control_on(const uint8_t pin);
void led_control_off(const uint8_t pin);

#endif // LED_CONTROL_H