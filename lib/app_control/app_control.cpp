#include "app_control.h"

static const char *command_list[] = {
    "led_on",
    "led_off"
};

void (*command_functions[])(const uint8_t) = {
    led_control_on,
    led_control_off
};

void app_control_init(void) {
    led_control_setup(LED_GREEN);
    led_control_off(LED_GREEN);
    own_stdio_init(SERIAL_BAUDRATE);
    printf("App initialized.\n\r");
    printf("Available commands:\n\r");

    size_t command_count = sizeof(command_list) / sizeof(command_list[0]);

    for (size_t i = 0; i < command_count; i++) {
        printf(" - %s\n\r", command_list[i]);
    }
}

void app_control_execute(const char *command) {
    size_t command_count = sizeof(command_list) / sizeof(command_list[0]);
    for (size_t i = 0; i < command_count; i++) {
        if (strcmp(command, command_list[i]) == 0) {
            command_functions[i](LED_GREEN);
            printf("Executed command: %s\n\r", command);
            return;
        }
    }
    printf("Unknown command: %s\n\r", command);
}

void app_control_loop(void) {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim(); // Удаление лишних пробелов и символов новой строки
        app_control_execute(input.c_str());
    }
}