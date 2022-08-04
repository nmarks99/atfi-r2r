#include<Arduino.h>
#include "usart.h"

void setup() {
  usart_init();
}

void loop() {
  delay(1000);
  char m[50];
  int years = 22;
  sprintf(m,"Hello I am %d years old",years);
  usart_println(m);
}