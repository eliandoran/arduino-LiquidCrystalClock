#ifndef SEGMENT_REPRESENTATIONS_H
#define SEGMENT_REPRESENTATIONS_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Segments.hpp"

#define GLYPH_HEIGHT 8

class SegmentRepresentations
{
private:
    const byte glyphRight[GLYPH_HEIGHT] = {
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001 };

    const byte glyphTopLeftRight[GLYPH_HEIGHT] = {
        0b11111,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001 };

    const byte glyphTopLeftBottom[GLYPH_HEIGHT] = {
        0b11111,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b11111 };

    const byte glyphTopRight[GLYPH_HEIGHT] = {
        0b11111,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001 };

    const byte glyphTopRightBottom[GLYPH_HEIGHT] = {
        0b11111,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b11111 };

    const byte glyphBottomLeft[GLYPH_HEIGHT] = {
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b11111 };

    const byte glyphBottomLeftRight[GLYPH_HEIGHT] = {
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b11111 };

    const byte glyphBottomRight[GLYPH_HEIGHT] = {
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b00001,
        0b11111 };

    const byte glyphAll[GLYPH_HEIGHT] = {
        0b11111,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b10001,
        0b11111 };

    byte* obtainGlyph(byte segment) {
        switch (segment) {
            case SEGMENT_RIGHT:
                return glyphRight;

            case SEGMENT_TOP_LEFT_RIGHT:
                return glyphTopLeftRight;

            case SEGMENT_TOP_LEFT_BOTTOM:
                return glyphTopLeftBottom;

            case SEGMENT_TOP_RIGHT:
                return glyphTopRight;

            case SEGMENT_TOP_RIGHT_BOTTOM:
                return glyphTopRightBottom;

            case SEGMENT_BOTTOM_LEFT:
                return glyphBottomLeft;

            case SEGMENT_BOTTOM_LEFT_RIGHT:
                return glyphBottomLeftRight;

            case SEGMENT_BOTTOM_RIGHT:
                return glyphBottomRight;

            case SEGMENT_ALL:
                return glyphAll;

            default:
                return 0;
        }
    }

public:
    short loadSegment(LiquidCrystal lcd, short segment, short index) {
        byte* glyphData = this->obtainGlyph(segment);
        lcd.createChar(index, glyphData);
    }
};

#endif
