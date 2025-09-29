#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Глобальный объект LCD (объявление, без инициализации)
extern LiquidCrystal_I2C lcd;

/**
 * @brief Инициализация LCD.
 */
void lcdInit();

/**
 * @brief Вывод сообщения на LCD.
 */
void lcdPrint(const String &message);

/**
 * @brief Вывод сообщения на определённую строку LCD.
 */
void lcdPrintLine(const String &message, uint8_t line);

/**
 * @brief Прокрутка текста на LCD.
 */
void lcdScrollText(const String &message, uint16_t delayMs = 300);

#endif // LCD_CONTROL_H
