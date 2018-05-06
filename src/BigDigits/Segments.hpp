#include <Arduino.h>

#define NUM_DIGITS 10
#define SEGMENTS_PER_DIGIT 4

enum BigDigitSegment {
    SEGMENT_BLANK,
    SEGMENT_LEFT,
    SEGMENT_RIGHT,
    SEGMENT_TOP,
    SEGMENT_TOP_LEFT,
    SEGMENT_TOP_RIGHT,
    SEGMENT_TOP_BOTTOM,
    SEGMENT_TOP_LEFT_BOTTOM,
    SEGMENT_TOP_RIGHT_BOTTOM,
    SEGMENT_BOTTOM_LEFT,
    SEGMENT_BOTTOM_RIGHT
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
        int minSegments = 10;
        int maxSegments = 0;
        int count = 0;

        for (int digit0 = 0; digit0 <= 9; digit0++)
        for (int digit1 = 0; digit1 <= 9; digit1++)
        for (int digit2 = 0; digit2 <= 9; digit2++)
        for (int digit3 = 0; digit3 <= 9; digit3++) {
            bool segmentMap[10] = {};

            insertSegmentsIntoSet(digit0, segmentMap);
            insertSegmentsIntoSet(digit1, segmentMap);
            insertSegmentsIntoSet(digit2, segmentMap);
            insertSegmentsIntoSet(digit3, segmentMap);

            int segmentCount = 0;
            for (int i = 0; i < 10; i++) {
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
