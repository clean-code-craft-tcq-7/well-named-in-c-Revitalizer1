#include <stdio.h>
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

void md_footer(char* buffer, size_t UNUSED_bufferSize) {
    (void)UNUSED_bufferSize; // Suppress unused parameter warning
    buffer[0] = '\0'; // No footer for markdown
}

// Define the Markdown formatter
Formatter MarkdownFormatter = {
    md_header,
    md_line_format,
    md_footer
};