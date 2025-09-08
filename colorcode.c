#include <stdio.h>
#include "colorcode.h"


const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};
const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

// Convert ColorPair to string
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

// Get color from pair number
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

// Get pair number from color
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
           colorPair->minorColor + 1;
}

// Print color code reference manual
void PrintColorCodeReferenceManual() {
    printf("Color Code Reference Manual:\n");
    printf("Pair No. | Major Color | Minor Color\n");
    printf("------------------------------------\n");
    
    for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i);
        char colorPairStr[MAX_COLORPAIR_STRING_LENGTH];
        ColorPairToString(&colorPair, colorPairStr);
        printf("%-8d | %-11s | %s\n", i, 
               MajorColorNames[colorPair.majorColor], 
               MinorColorNames[colorPair.minorColor]);
    }
}
