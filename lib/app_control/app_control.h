#ifndef APP_CONTROL_H
#define APP_CONTROL_H

#include <Arduino.h>
#include "led_control.h"
#include "config.h"
#include "own_stdio.h"

/**
 * @brief Инициализация приложения: настройка светодиодов, инициализация Serial.
 */
void app_control_init(void);

/**
 * @brief Основной цикл обработки команд, полученных через Serial.
 */
void app_control_loop(void);

#endif // APP_CONTROL_H