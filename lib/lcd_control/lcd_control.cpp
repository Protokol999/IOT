#include <Arduino.h>
#include "lcd_control.h"
#include "config.h"

// Глобальный объект LCD (определение)
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

void lcdInit() {
    lcd.init();
    lcd.backlight();
}

void lcdPrint(const String &message) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message.substring(0, LCD_COLS));
}

void lcdPrintLine(const String &message, uint8_t line) {
    if (line >= LCD_ROWS) {
        Serial.println("Error: Line number out of range");
        return;
    }
    lcd.setCursor(0, line);
    lcd.print(message.substring(0, LCD_COLS));
}

void lcdScrollText(const String &message, uint16_t delayMs) {
    String scrollText = message + " ";  // Добавляем пробел в конец
    lcd.clear();
    for (size_t i = 0; i <= scrollText.length(); i++) {
        lcd.setCursor(0, 0);
        lcd.print(scrollText.substring(i, i + LCD_COLS));
        delay(delayMs);
    }
}
