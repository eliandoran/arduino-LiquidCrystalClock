#include <LiquidCrystalPlus.h>
#include "TemperatureWidget.h"

class HomePage: public Page {
    TemperatureWidget temperature;

    void show() {
        add(temperature, 11, 1);
    }

    void loop() {

    }
};
