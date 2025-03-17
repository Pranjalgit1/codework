#include <stdio.h>

int countFourLetterWords(char str[]) {
    int count = 0;  // Counter for words with exactly 4 characters
    int wordLength = 0;  // Tracks the length of the current word
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            // If the character is not a space, it is part of a word
            wordLength++;
        } else {
            // If we encounter a space or newline, check the length of the word
            if (wordLength == 4) {
                count++;
            }
            wordLength = 0;  // Reset word length for the next word
        }
        i++;
    }

    // Check the last word (if the string doesn't end with a space)
    if (wordLength == 4) {
        count++;
    }

    return count;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read the input string safely

    int result = countFourLetterWords(str);

    printf("Number of words with 4 characters: %d\n", result);

    return 0;
}
