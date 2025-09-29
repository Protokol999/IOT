#ifndef CONFIG_H
#define CONFIG_H

// Serial
#define SERIAL_BAUDRATE 9600

// LEDs
#define LED_GREEN 12
#define LED_RED 11

// LCD (I2C)
#define LCD_COLS 16
#define LCD_ROWS 2

// Valid code
#define VALID_CODE "1234"

// Keypad (только пины и матрица, без include!)
const byte ROWS = 4; 
const byte COLS = 4; 
const char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
const byte rowPins[ROWS] = {22, 24, 26, 28}; 
const byte colPins[COLS] = {30, 32, 34, 36}; 

#endif
