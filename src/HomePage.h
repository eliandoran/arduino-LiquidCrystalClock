#include <LiquidCrystalPlus.h>
#include "TemperatureWidget.h"
#include "HumidityWidget.h"

class HomePage: public Page {
    TemperatureWidget temperature;
    HumidityWidget humidity;

    void show() {
        add(temperature, 11, 1);
        add(humidity, 11, 0);
    }

    void loop() {

    }
};
