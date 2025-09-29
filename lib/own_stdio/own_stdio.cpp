#include "own_stdio.h"
#include "config.h"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ==================
// Глобальные объекты
// ==================
extern LiquidCrystal_I2C lcd;   // объявлены в main.cpp
extern Keypad keypad;

static FILE flow = {0};

// ------------------
// Serial stdio
// ------------------
int own_stdio_getchar(FILE * f)
{
    while (!Serial.available());
    return Serial.read();
}

int own_stdio_putchar(char c, FILE * f)
{
    return Serial.write(c);
}

// ------------------
// LCD вывод (аналог puts/printf)
// ------------------
void lcd_puts(const char* text)
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(text);
}

void lcd_puts_line(const char* text, uint8_t line)
{
    if (line >= LCD_ROWS) {
        Serial.println("Error: Line number out of range");
        return;
    }
    lcd.setCursor(0, line);
    lcd.print(text);
}

// ------------------
// Keypad ввод (аналог scanf/getchar)
// ------------------
String keypad_gets(uint8_t length, bool masked)
{
    if (length > LCD_COLS) {
        length = LCD_COLS; // Ограничиваем длину строки шириной дисплея
    }

    String input = "";
    lcd.setCursor(0, 1);
    for (uint8_t i = 0; i < LCD_COLS; i++) {
        lcd.print(" ");
    }
    lcd.setCursor(0, 1);

    while (input.length() < length) {
        char key = keypad.getKey();
        if (key) {
            input += key;
            if (masked) {
                lcd.setCursor(input.length()-1, 1);
                lcd.print("*");   // выводим звёздочку вместо символа
            } else {
                lcd.setCursor(input.length()-1, 1);
                lcd.print(key);
            }
        }
    }
    return input;
}

// ------------------
// Init
// ------------------
void own_stdio_init(const uint32_t baudrate)
{
    Serial.begin(baudrate);
    fdev_setup_stream(&flow, own_stdio_putchar, own_stdio_getchar, _FDEV_SETUP_RW);
    stdin = &flow;
    stdout = &flow;
}