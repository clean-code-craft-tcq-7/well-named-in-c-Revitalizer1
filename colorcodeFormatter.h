#ifndef COLORCODE_FORMATTER_H
#define COLORCODE_FORMATTER_H

// Format options for the reference manual
enum FormatType {
    MARKDOWN_FORMAT,
    CSV_FORMAT,
    JSON_FORMAT
};

// Function to print the reference manual in the specified format
void printReferenceManual(int format);

#endif /* COLORCODE_FORMATTER_H */
