#include <LiquidCrystalPlus.h>
#include "HomePage.h"

LiquidCrystalPlus lcd;

void setup() {
    lcd.setPins(8, 9, 4, 5, 6, 7);
    lcd.setResolution(16, 2);
    lcd.init();
    lcd.show(new HomePage());
}

void loop() {
    lcd.doLoop();
}
