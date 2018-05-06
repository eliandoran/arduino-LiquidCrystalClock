#ifndef BIGDIGITS_H
#define BIGDIGITS_H

#include "Segments.hpp"
#include "SegmentRepresentations.hpp"
#include <LiquidCrystal.h>

class BigDigit
{
private:
    byte digits[NUM_DIGITS][SEGMENTS_PER_DIGIT] = {
        // Digit 0
        { SEGMENT_TOP_LEFT_RIGHT, SEGMENT_BOTTOM_LEFT_RIGHT },

        // Digit 1
        { SEGMENT_RIGHT, SEGMENT_RIGHT },

        // Digit 2
        { SEGMENT_TOP_RIGHT_BOTTOM, SEGMENT_BOTTOM_LEFT },

        // Digit 3
        { SEGMENT_TOP_RIGHT_BOTTOM, SEGMENT_BOTTOM_RIGHT },

        // Digit 4
        { SEGMENT_BOTTOM_LEFT, SEGMENT_RIGHT },

        // Digit 5
        { SEGMENT_TOP_LEFT_BOTTOM, SEGMENT_BOTTOM_RIGHT },

        // Digit 6
        { SEGMENT_TOP_LEFT_BOTTOM, SEGMENT_BOTTOM_LEFT_RIGHT},

        // Digit 7
        { SEGMENT_TOP_RIGHT, SEGMENT_RIGHT },

        // Digit 8
        { SEGMENT_ALL, SEGMENT_BOTTOM_LEFT_RIGHT },

        // Digit 9
        { SEGMENT_ALL, SEGMENT_BOTTOM_RIGHT }
    };

public:
    void segmentDebug() {
        int minSegments = NUM_SEGMENTS;
        int maxSegments = 0;
        int count = 0;
        int fails = 0;

        for (int digit0 = 0; digit0 < 2; digit0++)
        for (int digit1 = 0; digit1 < 10; digit1++)
        for (int digit2 = 0; digit2 < 5; digit2++)
        for (int digit3 = 0; digit3 < 10; digit3++) {
            bool segmentMap[NUM_SEGMENTS] = {};

            insertSegmentsIntoSet(digit0, segmentMap);
            insertSegmentsIntoSet(digit1, segmentMap);
            insertSegmentsIntoSet(digit2, segmentMap);
            insertSegmentsIntoSet(digit3, segmentMap);

            int segmentCount = 0;
            for (int i = 0; i < NUM_SEGMENTS; i++) {
                if (segmentMap[i])
                    segmentCount++;
            }

            if (segmentCount > 8) {
                Serial.print(digit0);
                Serial.print(digit1);
                Serial.print(digit2);
                Serial.println(digit3);
                fails++;
            }

            minSegments = min(minSegments, segmentCount);
            maxSegments = max(maxSegments, segmentCount);
            count++;
        }

        Serial.print("Count: "); Serial.println(count);
        Serial.print("Max: "); Serial.println(maxSegments);
        Serial.print("Min: "); Serial.println(minSegments);
        Serial.print("Fails: "); Serial.println(fails);
    }

    void insertSegmentsIntoSet(int digit, bool segmentMap[]) {
        for (int i=0; i<SEGMENTS_PER_DIGIT; i++) {
            int segment = this->digits[digit][i];
            segmentMap[segment] = true;
        }
    }

    void drawDigit(LiquidCrystal lcd, short x, short digit) {
        SegmentRepresentations rep;

        for (int y=0; y < 2; y++) {
            rep.loadSegment(lcd, this->digits[digit][y], y);
            lcd.setCursor(x, y);
            lcd.write(y);
        }
    }
};

#endif
