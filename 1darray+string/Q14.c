#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isalpha() and isdigit() functions

int main() {
    char str[100];
    int alphabets = 0, digits = 0, special = 0;
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Count characters
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        // Method 1: Using ctype.h functions
        if (isalpha(*ptr)) {
            alphabets++;
        }
        else if (isdigit(*ptr)) {
            digits++;
        }
        else {
            special++;
        }
        
        /* Method 2: Without ctype.h
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
            alphabets++;
        }
        else if (*ptr >= '0' && *ptr <= '9') {
            digits++;
        }
        else {
            special++;
        }
        */
    }
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("\nCharacter Count:\n");
    printf("--------------------\n");
    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Special Symbols: %d\n", special);
    printf("--------------------\n");
    
    return 0;
} 