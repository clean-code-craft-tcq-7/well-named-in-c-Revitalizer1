#include <stdio.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

// JSON formatter functions
void json_header(char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "{\n  \"colorPairs\": [");
}

void json_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, bufferSize, "    {\"pairNumber\": %d, \"majorColor\": \"%s\", \"minorColor\": \"%s\"}", 
             pairNumber, 
             MajorColorNames[major], 
             MinorColorNames[minor]);
}

void json_footer(char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "  ]\n}");
}

// Define the JSON formatter
Formatter JsonFormatter = {
    json_header,
    json_line_format,
    json_footer
};