#include <Arduino.h>
#include <HX711.h>
#include <stdio.h>
#include "usart.h"

#define DOUT 2
#define SCK 3

HX711 loadcell;

void setup() { 

    Serial.begin(38400);
    loadcell.begin(DOUT,SCK);
    loadcell.set_scale(3910);
    loadcell.tare();


}


void loop() {
    Serial.println(loadcell.get_units());
}


