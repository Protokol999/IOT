#include <Arduino.h>
#include "app_control.h"
#include "config.h"


void setup() {
app_control_init();
 
}

void loop() {

app_control_loop();

}

