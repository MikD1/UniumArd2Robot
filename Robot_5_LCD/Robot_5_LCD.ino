/*
 *  1 - gnd - display -
 *  2 - 5v  - display +
 *  3 - gnd - contrast
 *  
 *  5 - gnd - write mode
 *  4 - D4  - RS
 *  6 - D5  - E
 * 11 - D10 - DB4 
 * 12 - D11 - DB5
 * 13 - D12 - DB6
 * 14 - D13 - DB7 *  
 *  
 * 15 - 5v  - backlight +
 * 16 - gnd - backlight -
 * 
 */

#include <LiquidCrystal.h>

//                RS, E, DB4, DB5, DB6, DB7
LiquidCrystal Lcd(4,  5, 10,  11,  12,  13);

int N = 0;

void setup()
{
  Lcd.begin(16, 2);
  Lcd.print("Hello, world!");
}

void loop()
{
  Lcd.setCursor(0, 1);
  Lcd.print(N);
  N = N + 1;
  delay(500);
}
