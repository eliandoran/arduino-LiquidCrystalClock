#include <LiquidCrystalPlus.h>
#include "CustomCharacters.h"

class TemperatureWidget: public Widget {
    int8_t temperature = 20;
    bool temperatureChanged = false;

    void update() {
        display->printChar(CustomCharacters::temperatureIcon);
        display->print(' ');
        display->print(temperature);        
        display->write(0b11011111);
    }

    bool needsUpdate() {
        return temperatureChanged;
    }
};
