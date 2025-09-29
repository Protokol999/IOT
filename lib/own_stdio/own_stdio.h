#ifndef OWN_STDIO_H
#define OWN_STDIO_H

#include <Arduino.h>

/**
 * @brief Инициализация Serial для работы с STDIO.
 * 
 * @param baudrate Скорость передачи данных (в бодах).
 */
void own_stdio_init(const uint32_t baudrate);

/**
 * @brief Вывод текста на LCD.
 * 
 * @param text Указатель на строку текста для отображения.
 */
void lcd_puts(const char* text);

/**
 * @brief Вывод текста на определенную строку LCD.
 * 
 * @param text Указатель на строку текста для отображения.
 * @param line Номер строки (начиная с 0). Если строка выходит за пределы дисплея, функция ничего не делает.
 */
void lcd_puts_line(const char* text, uint8_t line);

/**
 * @brief Считывание ввода с клавиатуры.
 * 
 * @param length Максимальная длина вводимой строки.
 * @param masked Если true, вводимые символы отображаются как '*'.
 * @return String Введенная строка.
 */
String keypad_gets(uint8_t length, bool masked);

#endif // OWN_STDIO_H