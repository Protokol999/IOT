#include <Keypad.h>
#include "keypad_control.h"
#include "config.h"
#include "lcd_control.h" // Для работы с LCD

// Глобальный объект клавиатуры
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String getKeypadInput(int maxLength, unsigned long timeout = 10000, bool masked = false) {
    String input = "";
    unsigned long startTime = millis();

    // Очистка строки на LCD перед вводом
    lcd.clear();
    lcd.setCursor(0, 0);

    while (input.length() < maxLength) {
        if (millis() - startTime > timeout) {
            return ""; // Возврат пустой строки при истечении времени
        }

        char key = keypad.getKey();
        if (key) {
            if (key == '*') { // Удаление символа
                if (input.length() > 0) {
                    input.remove(input.length() - 1); // Удаление последнего символа
                    lcd.setCursor(input.length(), 0);
                    lcd.print(" "); // Очистка последнего символа на LCD
                    lcd.setCursor(input.length(), 0);
                }
            } else {
                input += key;
                lcd.setCursor(input.length() - 1, 0);
                lcd.print(masked ? '*' : key); // Отображение символа или звездочки
            }
        }
    }
    return input;
}