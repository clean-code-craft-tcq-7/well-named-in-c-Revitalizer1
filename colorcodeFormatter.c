#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

// Print reference manual using the specified formatter
void printReferenceManual(Formatter* formatter) {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    char buffer[256];
    
    // Print header
    formatter->header(buffer, sizeof(buffer));
    printf("%s\n", buffer);
    
    // Print each color pair
    for (int i = 1; i <= totalPairs; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i);
        formatter->line_format(buffer, sizeof(buffer), i, 
                             colorPair.majorColor, 
                             colorPair.minorColor);
        
        // For JSON, handle commas between items
        if (formatter == &JsonFormatter && i < totalPairs) {
            strcat(buffer, ",");
        }
        printf("%s\n", buffer);
    }
    
    // Print footer
    formatter->footer(buffer, sizeof(buffer));
    if (buffer[0] != '\0') {
        printf("%s\n", buffer);
    }
}
