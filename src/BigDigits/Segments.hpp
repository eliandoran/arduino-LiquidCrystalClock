#ifndef SEGMENTS_HPP
#define SEGMENTS_HPP

#include <Arduino.h>

#define NUM_DIGITS 10
#define NUM_SEGMENTS 14
#define SEGMENTS_PER_DIGIT 2

enum BigDigitSegment {
    SEGMENT_RIGHT = 0,
    SEGMENT_TOP_LEFT_RIGHT = 1,
    SEGMENT_TOP_LEFT_BOTTOM = 2,
    SEGMENT_TOP_RIGHT = 3,
    SEGMENT_TOP_RIGHT_BOTTOM = 4,
    SEGMENT_BOTTOM_LEFT = 5,
    SEGMENT_BOTTOM_LEFT_RIGHT = 6,
    SEGMENT_BOTTOM_RIGHT = 7,
    SEGMENT_ALL = 8,
};

#endif
