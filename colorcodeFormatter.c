#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorcode.h"
#include "colorcodeFormatter.h"

enum {MARKDOWN, CSV, JSON};

void printReferenceManual(int format) {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    
    switch (format) {
        case MARKDOWN:
            printf("# Color Code Reference Manual\n\n");
            printf("| Pair No. | Major Color | Minor Color |\n");
            printf("|----------|-------------|-------------|\n");
            
            for (int i = 1; i <= totalPairs; i++) {
                ColorPair colorPair = GetColorFromPairNumber(i);
                printf("| %d | %s | %s |\n", i, 
                       MajorColorNames[colorPair.majorColor], 
                       MinorColorNames[colorPair.minorColor]);
            }
            break;
            
        case CSV:
            printf("Pair No.,Major Color,Minor Color\n");
            
            for (int i = 1; i <= totalPairs; i++) {
                ColorPair colorPair = GetColorFromPairNumber(i);
                printf("%d,%s,%s\n", i, 
                       MajorColorNames[colorPair.majorColor], 
                       MinorColorNames[colorPair.minorColor]);
            }
            break;
            
        case JSON:
            printf("{\n  \"colorPairs\": [\n");
            
            for (int i = 1; i <= totalPairs; i++) {
                ColorPair colorPair = GetColorFromPairNumber(i);
                char buffer[100];
                
                sprintf(buffer, "    {\"pairNumber\": %d, \"majorColor\": \"%s\", \"minorColor\": \"%s\"},", 
                        i, MajorColorNames[colorPair.majorColor], MinorColorNames[colorPair.minorColor]);
                
                if (i == totalPairs) {
                    buffer[strlen(buffer) - 1] = '\0'; // remove ","
                }
                printf("%s\n", buffer);
            }
            
            printf("  ]\n}\n");
            break;
            
        default:
            fprintf(stderr, "Unsupported format type: %d\n", format);
            break;
    }
}
