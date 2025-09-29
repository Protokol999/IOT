#ifndef KEYPAD_CONTROL_H
#define KEYPAD_CONTROL_H
#include <Keypad.h>

#include <Arduino.h>

/**
 * @brief Считывает ввод с клавиатуры.
 * 
 * @param maxLength Максимальная длина вводимой строки.
 * @param timeout Время ожидания ввода (в миллисекундах). По умолчанию 10000 (10 секунд).
 * @param masked Если true, вводимые символы отображаются как '*'. По умолчанию false.
 * @return String Введенная строка. Если время ожидания истекло, возвращается пустая строка.
 */
String getKeypadInput(int maxLength, unsigned long timeout = 10000, bool masked = false);

#endif // KEYPAD_CONTROL_H