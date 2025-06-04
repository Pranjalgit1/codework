#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[100];
    int count = 0;
    
    // Input main string
    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';  // Remove newline
    
    // Input substring
    printf("Enter substring to search: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strlen(sub) - 1] = '\0';  // Remove newline
    
    // Count substring occurrences
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        const char *strPtr = ptr;
        const char *subPtr = sub;
        
        // Check if substring matches from current position
        while (*subPtr != '\0' && *strPtr == *subPtr) {
            strPtr++;
            subPtr++;
        }
        
        // If we reached end of substring, it means we found a match
        if (*subPtr == '\0') {
            count++;
        }
    }
    
    // Display results
    printf("\nMain string: %s\n", str);
    printf("Substring: %s\n", sub);
    printf("\nResult:\n");
    printf("--------------------\n");
    if (count > 0) {
        printf("Substring appears %d time(s) in the main string\n", count);
    } else {
        printf("Substring is not present in the main string\n");
    }
    printf("--------------------\n");
    
    return 0;
} 