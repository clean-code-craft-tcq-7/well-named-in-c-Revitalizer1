#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

// Markdown formatter functions
void md_header(char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "# Color Code Reference Manual\n\n| Pair No. | Major Color | Minor Color |\n|----------|-------------|-------------|");
}

void md_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, bufferSize, "| %d | %s | %s |", 
             pairNumber, 
             MajorColorNames[major], 
             MinorColorNames[minor]);
}

void md_footer(char* buffer, size_t bufferSize) {
    buffer[0] = '\0'; // No footer for markdown
}

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

void csv_footer(char* buffer, size_t bufferSize) {
    buffer[0] = '\0'; // No footer for CSV
}

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

// Define the formatters
Formatter MarkdownFormatter = {
    md_header,
    md_line_format,
    md_footer
};

Formatter CsvFormatter = {
    csv_header,
    csv_line_format,
    csv_footer
};

Formatter JsonFormatter = {
    json_header,
    json_line_format,
    json_footer
};

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
