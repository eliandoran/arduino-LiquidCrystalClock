#include <LiquidCrystalPlus.h>
#include "CustomCharacters.h"

class HumidityWidget: public Widget {
    uint8_t humidity = 85;
    bool humidityChanged = false;

    void update() {
        display->printChar(CustomCharacters::humidityIcon);
        display->print(' ');
        display->print(humidity);
        display->print('%');
    }

    bool needsUpdate() {
        return humidityChanged;
    }
};