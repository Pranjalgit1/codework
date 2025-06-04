#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256  // For ASCII characters

int main() {
    char str[100];
    int charCount[MAX_CHARS] = {0};  // Array to store character counts
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Count frequency of each character
    // Method 1: Using unsigned char (more efficient)
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        charCount[(unsigned char)*ptr]++;
    }
    
    // Method 2: Using int (works but less efficient)
    /*
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        charCount[(int)*ptr]++;
    }
    */
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("\nCharacter Frequencies:\n");
    printf("--------------------\n");
    
    // Display only characters that appear at least once
    for (int i = 0; i < MAX_CHARS; i++) {
        if (charCount[i] > 0) {
            if (i == ' ') {
                printf("Space: %d\n", charCount[i]);
            } else {
                printf("'%c': %d\n", (char)i, charCount[i]);
            }
        }
    }
    printf("--------------------\n");
    
    return 0;
} 