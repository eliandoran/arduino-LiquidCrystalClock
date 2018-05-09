#include <Arduino.h>
#include <LiquidCrystal.h>

//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

uint8_t glyphLargeRight[] = {
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011
};

uint8_t glyphLargeTopLeftBottom[] = {
  0b11111,
  0b11111,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11111,
  0b11111,
};

uint8_t glyphLargeTopBottom[] = {
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
};

uint8_t glyphLargeBottomRight[] = {
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b11111,
  0b11111,
};

uint8_t glyphLargeBottom[] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
};


uint8_t glyphBlank[] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

uint8_t glyphDigit2[] = {
  0b11111,
  0b00001,
  0b00001,
  0b11111,
  0b10000,
  0b10000,
  0b10000,
  0b11111
};

uint8_t glyphDigit4[] = {
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};

uint8_t glyphTemp[] = {
    B00100,
    B01010,
    B01010,
    B01010,
    B01010,
    B10001,
    B10001,
    B01110
};

uint8_t glyphHumidity[] = {
    B00000,
    B00100,
    B01010,
    B10001,
    B10001,
    B01110,
    B00000,
    B00000
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, glyphLargeRight);
  lcd.createChar(1, glyphLargeTopLeftBottom);
  lcd.createChar(2, glyphLargeTopBottom);
  lcd.createChar(3, glyphLargeBottom);
  lcd.createChar(4, glyphLargeBottomRight);

  lcd.createChar(5, glyphHumidity);
  lcd.createChar(6, glyphTemp); 

  writeAt(0, 0, 0);
  writeAt(0, 1, 0);

  writeAt(1, 0, 1);
  writeAt(2, 0, 2);
  writeAt(1, 1, 3);
  writeAt(2, 1, 4);

  printAt(3, 0, ":56:40");
  printAt(4, 1, "Su 16");

  writeAt(11, 0, 5);
  printAt(13, 0, "80%");

  writeAt(11, 1, 6);
  printAt(13, 1, "26");
  writeAt(15, 1, 0b11011111);
}

void writeAt(int x, int y, byte ch) {
  lcd.setCursor(x, y);
  lcd.write(ch);
}

void printAt(int x, int y, char str[]) {
  lcd.setCursor(x, y);
  lcd.print(str);
}

void loop() {
  // put your main code here, to run repeatedly:

}
