#ifndef APP_CONTROL_H
#define APP_CONTROL_H

#include <Arduino.h>
#include "led_control.h"
#include "config.h"
#include "own_stdio.h"

void app_control_init(void);
void app_control_loop(void);

#endif // APP_CONTROL_H