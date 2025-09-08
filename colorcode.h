#ifndef COLORCODE_H
#define COLORCODE_H

#define MAX_COLORPAIR_STRING_LENGTH 16

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

extern const char* MajorColorNames[];
extern const int numberOfMajorColors;
extern const char* MinorColorNames[];
extern const int numberOfMinorColors;

void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void PrintColorCodeReferenceManual();

#endif /* COLORCODE_H */
