#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int startWithCount = 0;
    char startChar;
    
    // Input string
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Input character to check
    printf("Enter character to count words starting with it: ");
    scanf(" %c", &startChar);
    
    // Count words starting with specific character
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        // Check if word starts with the given character
        if ((ptr == str || *(ptr - 1) == ' ') && *ptr == startChar) {
            startWithCount++;
        }
    }
    
    // Display results
    printf("\nOriginal sentence: %s\n", str);
    printf("\nWord Count:\n");
    printf("--------------------\n");
    printf("Words starting with '%c': %d\n", startChar, startWithCount);
    printf("--------------------\n");
    
    return 0;
} 