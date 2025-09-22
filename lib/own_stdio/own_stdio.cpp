#include "own_stdio.h"

static FILE flow = {0};

int own_stdio_getchar(FILE * f)
{
    while (!Serial.available());
    return Serial.read();
}

int own_stdio_putchar(char c, FILE * f)
{
  return Serial.write(c);
}

void own_stdio_init(const uint32_t baudrate)
{
   Serial.begin(baudrate);
   fdev_setup_stream(&flow, own_stdio_putchar, own_stdio_getchar, _FDEV_SETUP_RW);
   stdin = &flow;
    stdout = &flow;
}
