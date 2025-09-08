#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

// Test markdown formatting
void testPrintReferenceManual() {
    char buff[256];
    md_header(buff, sizeof(buff));
    assert(strstr(buff, "Color Code Reference Manual") != NULL);
    
    md_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strstr(buff, "1") != NULL && strstr(buff, "White") != NULL && strstr(buff, "Blue") != NULL);
    
    printReferenceManual(&MarkdownFormatter);
}

// Test CSV formatting
void testPrintReferenceManualCSV() {
    char buff[256];
    csv_header(buff, sizeof(buff));
    assert(strstr(buff, "Pair No.,Major Color,Minor Color") != NULL);
    
    csv_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strstr(buff, "1,White,Blue") != NULL);
    
    printReferenceManual(&CsvFormatter);
}

// Test JSON formatting
void testPrintReferenceManualJSON() {
    char buff[256];
    json_header(buff, sizeof(buff));
    assert(strstr(buff, "colorPairs") != NULL);
    
    json_line_format(buff, sizeof(buff), 1, WHITE, BLUE);
    assert(strstr(buff, "White") != NULL && strstr(buff, "Blue") != NULL);
    
    // Test full manual printing
    printReferenceManual(&JsonFormatter);
}

// Main test function for formatters
void run_formatter_tests() {
    printf("Testing reference manual formatters...\n");
    
    testPrintReferenceManual();
    testPrintReferenceManualCSV();
    testPrintReferenceManualJSON();
    
    printf("All formatter tests passed!\n");
}
