#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Count vowels and consonants
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        // Method 1: Using ASCII values
        if ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')) {
            // Check for vowels (both uppercase and lowercase)
            if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
                *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
        
        /* Method 2: Using ctype.h functions
        if (isalpha(*ptr)) {
            if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
                *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
        */
    }
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("\nCharacter Count:\n");
    printf("--------------------\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("--------------------\n");
    
    return 0;
} 