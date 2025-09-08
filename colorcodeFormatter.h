#ifndef COLORCODE_FORMATTER_H
#define COLORCODE_FORMATTER_H

#include "colorcode.h"

// Formatter structure definition
typedef struct {
    void (*header)(char* buffer, size_t bufferSize);
    void (*line_format)(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor);
    void (*footer)(char* buffer, size_t bufferSize);
} Formatter;

// Formatters
extern Formatter MarkdownFormatter;
extern Formatter CsvFormatter;
extern Formatter JsonFormatter;

// Markdown formatter functions
void md_header(char* buffer, size_t bufferSize);
void md_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor);
void md_footer(char* buffer, size_t bufferSize);

// CSV formatter functions
void csv_header(char* buffer, size_t bufferSize);
void csv_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor);
void csv_footer(char* buffer, size_t bufferSize);

// JSON formatter functions
void json_header(char* buffer, size_t bufferSize);
void json_line_format(char* buffer, size_t bufferSize, int pairNumber, enum MajorColor major, enum MinorColor minor);
void json_footer(char* buffer, size_t bufferSize);

// Function to print the reference manual using the specified formatter
void printReferenceManual(Formatter* formatter);

#endif /* COLORCODE_FORMATTER_H */
