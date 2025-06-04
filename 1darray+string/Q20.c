#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int maxLength = 0;
    int currentWordLength = 0;
    
    // Input string
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Find maximum word length
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr != ' ') {
            currentWordLength++;
        } else {
            if (currentWordLength > maxLength) {
                maxLength = currentWordLength;
            }
            currentWordLength = 0;
        }
    }
    
    // Check last word
    if (currentWordLength > maxLength) {
        maxLength = currentWordLength;
    }
    
    // Display results
    printf("\nOriginal sentence: %s\n", str);
    printf("\nWord Length:\n");
    printf("--------------------\n");
    printf("Maximum word length: %d\n", maxLength);
    printf("--------------------\n");
    
    return 0;
} 