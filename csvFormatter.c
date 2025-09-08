#include <stdio.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

// CSV formatter functions
void csv_header(char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "Pair No.,Major Color,Minor Color");
}

void csv_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, bufferSize, "%d,%s,%s", 
             pairNumber, 
             MajorColorNames[major], 
             MinorColorNames[minor]);
}

void csv_footer(char* buffer, size_t UNUSED_bufferSize) {
    (void)UNUSED_bufferSize; // Suppress unused parameter warning
    buffer[0] = '\0'; // No footer for CSV
}

// Define the CSV formatter
Formatter CsvFormatter = {
    csv_header,
    csv_line_format,
    csv_footer
};