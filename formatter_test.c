#include <stdio.h>
#include <assert.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

void run_formatter_tests() {
    printf("Testing reference manual formatters...\n");
    
    // Test markdown format
    printReferenceManual(&MarkdownFormatter);
    
    // Test CSV format
    printReferenceManual(&CsvFormatter);
    
    // Test JSON format
    printReferenceManual(&JsonFormatter);
    
    printf("All formatter tests passed!\n");
}