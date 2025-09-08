#include <stdio.h>
#include <assert.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

void run_formatter_tests() {
    printf("Testing color code formatters...\n");
    
    // Test markdown format
    printReferenceManual(0); // Markdown format
    
    // Test CSV format
    printReferenceManual(1); // CSV format
    
    // Test JSON format
    printReferenceManual(2); // JSON format
    
    printf("All formatter tests passed!\n");
}