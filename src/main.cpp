#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int GLYPH_TEMPERATURE = 0;
const int GLYPH_HUMIDITY = 1;
const int GLYPH_DEGREES = 2;
const int GLYPH_DIGIT_RIGHT = 3;
const int GLYPH_DIGIT_TOP_RIGHT = 4;
const int GLYPH_DIGIT_TOP_LEFT = 5;
const int GLYPH_DIGIT_C = 6;
const int GLYPH_DIGIT_TOP = 7;
const int GLYPH_DIGIT_TOP_BOTTOM = 8;
const int GLYPH_DIGIT_REVERSE_C = 9;

const byte glyphTemp[] = {
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B01110
};

const byte glyphDegree[] = {
  B01000,
  B10100,
  B01000,
  B00000,
  B00011,
  B00010,
  B00011,
  B00000
};

const byte glyphHumidity[] = {
  B00000,  
  B00100,
  B01010,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000
};

const byte glyphDigitRight[] = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011
};

const byte glyphDigitTop[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

const byte glyphDigitTopRight[] = {
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011
};

const byte glyphDigitC[] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111
};

const byte glyphDigitTopBottom[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte bigDigits[][4] = {
  // 0
  { NULL, NULL,
    NULL, NULL },
    
  // 1
  { NULL, GLYPH_DIGIT_RIGHT,
    NULL, GLYPH_DIGIT_RIGHT },

  // 2
  { GLYPH_DIGIT_TOP, GLYPH_DIGIT_TOP_RIGHT,
    GLYPH_DIGIT_C, GLYPH_DIGIT_TOP_BOTTOM }
};

void drawDigit(short startX, short digit) {
  short x = startX;
  short y = 0;

  for (int i=0; i<2; i++) {
    x = startX;
    
    for (int j=0; j<2; j++) {
      int glyph = bigDigits[digit][2*i+j];

      if (glyph != NULL) {
        lcd.setCursor(x, y);
        lcd.write(glyph);      
      }
            
      x += 1;
    }

    y += 1;
  }   
}

void setup() {
  lcd.createChar(0, glyphTemp);
  lcd.createChar(1, glyphDegree);
  lcd.createChar(2, glyphHumidity);
  lcd.createChar(GLYPH_DIGIT_RIGHT, glyphDigitRight);
  lcd.createChar(GLYPH_DIGIT_TOP, glyphDigitTop);
  lcd.createChar(GLYPH_DIGIT_TOP_RIGHT, glyphDigitTopRight);
  lcd.createChar(GLYPH_DIGIT_TOP_BOTTOM, glyphDigitTopBottom);
  lcd.createChar(GLYPH_DIGIT_C, glyphDigitC);  

  lcd.begin(16, 2);
  //drawTemperature();
  //drawHumidity();  
  drawDigit(0, 1);
  drawDigit(2, 2);
  lcd.setCursor(4, 1);
  lcd.write(':');
  drawDigit(5, 2);
  drawDigit(7, 1);
}

void drawTemperature() {
  lcd.setCursor(11, 1);
  lcd.write((byte)0);

  lcd.setCursor(13, 1);
  lcd.print("20");
  lcd.write((byte)1); 
}

void drawHumidity() {
  lcd.setCursor(11, 0);
  lcd.write((byte)2);

  lcd.setCursor(13, 0);
  lcd.print("60%");
}

void loop() {

}
