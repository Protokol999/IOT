#include <Arduino.h>
#include "lcd_control.h"
#include "keypad_control.h"
#include "led_control.h"
#include "config.h"

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    lcdInit();
    lcdPrint("System Ready");
    Serial.println("System Ready");

    led_control_setup(LED_GREEN);
    led_control_setup(LED_RED);
    led_control_off(LED_GREEN);
    led_control_off(LED_RED);
}

void loop() {
    lcdPrint("Enter code:");
    Serial.println("Waiting for code...");

    String inputCode = getKeypadInput(4);
    Serial.print("Input code: ");
    Serial.println(inputCode);

    if (inputCode == VALID_CODE) {
        lcdPrint("Code valid!");
        Serial.println("Code valid!");
        led_control_on(LED_GREEN);
        led_control_off(LED_RED);
    } else {
        lcdPrint("Code invalid!");
        Serial.println("Code invalid!");
        led_control_on(LED_RED);
        led_control_off(LED_GREEN);
    }

    delay(3000);
}
