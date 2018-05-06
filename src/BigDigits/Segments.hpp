#include <Arduino.h>

#define NUM_DIGITS 10
#define NUM_SEGMENTS 11
#define SEGMENTS_PER_DIGIT 4

enum BigDigitSegment {
    SEGMENT_BLANK = 0,
    SEGMENT_LEFT = 1,
    SEGMENT_RIGHT = 2,
    SEGMENT_TOP = 3,
    SEGMENT_TOP_LEFT = 4,
    SEGMENT_TOP_RIGHT = 5,
    SEGMENT_TOP_BOTTOM = 6,
    SEGMENT_TOP_LEFT_BOTTOM = 7,
    SEGMENT_TOP_RIGHT_BOTTOM = 8,
    SEGMENT_BOTTOM_LEFT = 9,
    SEGMENT_BOTTOM_RIGHT = 10
};

class BigDigit
{
private:
    byte digits[NUM_DIGITS][SEGMENTS_PER_DIGIT] = {
        // Digit 0
        { SEGMENT_TOP_LEFT, SEGMENT_TOP_RIGHT,
          SEGMENT_BOTTOM_LEFT, SEGMENT_BOTTOM_RIGHT },

        // Digit 1
        { SEGMENT_BLANK, SEGMENT_RIGHT,
          SEGMENT_BLANK, SEGMENT_RIGHT },

        // Digit 2
        { SEGMENT_TOP, SEGMENT_TOP_RIGHT,
          SEGMENT_TOP_LEFT_BOTTOM, SEGMENT_TOP_BOTTOM },

        // Digit 3
        { SEGMENT_TOP, SEGMENT_TOP_RIGHT,
          SEGMENT_TOP_BOTTOM, SEGMENT_TOP_RIGHT_BOTTOM },

        // Digit 4
        { SEGMENT_LEFT, SEGMENT_RIGHT,
          SEGMENT_TOP, SEGMENT_TOP_RIGHT },

        // Digit 5
        { SEGMENT_TOP_LEFT, SEGMENT_TOP,
          SEGMENT_TOP_BOTTOM, SEGMENT_TOP_RIGHT_BOTTOM },

        // Digit 6
        { SEGMENT_TOP_LEFT, SEGMENT_TOP,
          SEGMENT_TOP_LEFT_BOTTOM, SEGMENT_TOP_RIGHT_BOTTOM },

        // Digit 7
        { SEGMENT_TOP, SEGMENT_TOP_RIGHT,
          SEGMENT_BLANK, SEGMENT_RIGHT },

        // Digit 8
        { SEGMENT_TOP_LEFT, SEGMENT_TOP_RIGHT,
          SEGMENT_TOP_LEFT_BOTTOM, SEGMENT_TOP_RIGHT_BOTTOM },

        // Digit 9
        { SEGMENT_TOP_LEFT, SEGMENT_TOP_RIGHT,
          SEGMENT_TOP, SEGMENT_TOP_RIGHT }
    };

public:
    void segmentDebug() {
        int minSegments = NUM_SEGMENTS;
        int maxSegments = 0;
        int count = 0;

        for (int digit0 = 0; digit0 < NUM_DIGITS; digit0++)
        for (int digit1 = 0; digit1 < NUM_DIGITS; digit1++)
        for (int digit2 = 0; digit2 < NUM_DIGITS; digit2++)
        for (int digit3 = 0; digit3 < NUM_DIGITS; digit3++) {
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

            minSegments = min(minSegments, segmentCount);
            maxSegments = max(maxSegments, segmentCount);
            count++;
        }

        Serial.print("Count: "); Serial.println(count);
        Serial.print("Max: "); Serial.println(maxSegments);
        Serial.print("Min: "); Serial.println(minSegments);
    }

    void insertSegmentsIntoSet(int digit, bool segmentMap[]) {
        for (int i=0; i<SEGMENTS_PER_DIGIT; i++) {
            segmentMap[this->digits[digit][i]] = true;
        }
    }
};
