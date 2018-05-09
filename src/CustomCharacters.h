#ifndef CUSTOM_CHARACTERS
#define CUSTOM_CHARACTERS

#include <LiquidCrystalPlus.h>

namespace CustomCharacters {
    CustomChar temperatureIcon[] = {
        B00100,
        B01010,
        B01010,
        B01010,
        B01010,
        B10001,
        B10001,
        B01110
    };

    CustomChar humidityIcon[] = {
        B00000,
        B00100,
        B01010,
        B10001,
        B10001,
        B01110,
        B00000,
        B00000
    };
};

#endif