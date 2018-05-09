#include <LiquidCrystalPlus.h>
#include "BigDigits.h"

class HourWidget: public Widget {
    uint8_t hour = 1;
    uint8_t digitSize = BigDigits::DIGIT_H_SEGMENTS;

    void update() {
        uint8_t firstDigit = hour / 10;
        uint8_t secondDigit = hour % 10;

        uint8_t x = 0;
        
        if (firstDigit != 0)
            printBigDigit(x, firstDigit);        
        else
            printBigDigit(x, 10);        

        printBigDigit(2, secondDigit);
    }

    void printBigDigit(uint8_t startX, uint8_t digit) {        
        for (int i=0; i<digitSize; i++) {
            for (int j=0; j<digitSize; j++) {
                display->setCursor(startX + j, i);
                display->printChar(BigDigits::digits[digit][i * digitSize + j]);
            }
        }
    }

    bool needsUpdate() {
        if (msSinceUpdate > 800) {
            hour = (hour < 12 ? hour + 1 : 1);
            parentPage->invalidate();
            delay(800);
        }        
        return false;
    }
};