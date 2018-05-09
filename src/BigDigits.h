#include <LiquidCrystalPlus.h>

namespace BigDigits {
    const int DIGIT_H_SEGMENTS = 2;
    const int DIGIT_V_SEGMENTS = 2;

    CustomChar segmentRight[] = {
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011
    };    

    CustomChar segmentTop[] = {
        0B11111,
        0B11111,
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B00000
    };    

    CustomChar segmentTopBottom[] = {
        0B11111,
        0B11111,
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B11111,
        0B11111
    };    

    CustomChar segmentTopLeft[] = {
        0B11111,
        0B11111,
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11000
    }; 

    CustomChar segmentTopLeftBottom[] = {
        0B11111,
        0B11111,
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11111,
        0B11111
    }; 

    CustomChar segmentTopRightBottom[] = {
        0B11111,
        0B11111,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B11111,
        0B11111
    };    

    CustomChar segmentBottomLeft[] = {
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11000,
        0B11111,
        0B11111
    };    

    CustomChar segmentBottom[] = {
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B00000,
        0B11111,
        0B11111
    };    

    CustomChar segmentBottomRight[] = {
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B11111,
        0B11111
    };    

    CustomChar segmentTopRight[] = {
        0B11111,
        0B11111,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011,
        0B00011
    };    

    CustomChar* digits[][4] = {
        // 0
        { segmentTopLeft, segmentTopRight,
          segmentBottomLeft, segmentBottomRight },

        // 1
        { NULL, segmentRight,
          NULL, segmentRight },

        // 2
        { segmentTopBottom, segmentTopRightBottom, 
          segmentBottomLeft, segmentBottom },

        // 3
        { segmentTopBottom, segmentTopRightBottom,
          segmentBottom, segmentBottomRight },

        // 4
        { segmentBottomLeft, segmentBottomRight, 
          NULL, segmentRight },

        // 5
        { segmentTopLeftBottom, segmentTopBottom,
          segmentBottom, segmentBottomRight },

        // 6
        { segmentTopLeftBottom, segmentTopBottom,
          segmentBottomLeft, segmentBottomRight },
        
        // 7
        { segmentTop, segmentTopRight,
          NULL, segmentRight },

        // 8
        { segmentTopLeftBottom, segmentTopRightBottom,
          segmentBottomLeft, segmentBottomRight },

        // 9
        { segmentTopLeftBottom, segmentTopRightBottom,
          NULL, segmentBottomRight },

        // 10th digit, aka empty segment
        { NULL, NULL,
          NULL, NULL }
    };
};