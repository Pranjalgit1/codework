#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    printf("\nOriginal string: %s\n", str);
    
    // Convert case
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        // Method 1: Using ASCII values
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr = *ptr + 32;  // Convert to lowercase
        }
        else if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - 32;  // Convert to uppercase
        }
        
        /* Method 2: Using ctype.h functions
        if (isupper(*ptr)) {
            *ptr = tolower(*ptr);
        }
        else if (islower(*ptr)) {
            *ptr = toupper(*ptr);
        }
        */
    }
    
    printf("Converted string: %s\n", str);
    
    return 0;
} 