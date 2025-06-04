#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int fourLetterWords = 0;
    int currentWordLength = 0;
    
    // Input string
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Count four letter words
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr != ' ') {
            currentWordLength++;
        } else {
            if (currentWordLength == 4) {
                fourLetterWords++;
            }
            currentWordLength = 0;
        }
    }
    
    // Check last word
    if (currentWordLength == 4) {
        fourLetterWords++;
    }
    
    // Display results
    printf("\nOriginal sentence: %s\n", str);
    printf("\nWord Count:\n");
    printf("--------------------\n");
    printf("Words with exactly 4 letters: %d\n", fourLetterWords);
    printf("--------------------\n");
    
    return 0;
} 