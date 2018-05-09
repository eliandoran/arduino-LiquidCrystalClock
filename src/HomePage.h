#include <LiquidCrystalPlus.h>
#include "TemperatureWidget.h"
#include "HumidityWidget.h"
#include "HourWidget.h"

class HomePage: public Page {
    HourWidget hour;
    TemperatureWidget temperature;
    HumidityWidget humidity;    

    void show() {
        add(hour, 0, 0);

        add(temperature, 11, 1);
        add(humidity, 11, 0);        
    }

    void loop() {

    }
};
