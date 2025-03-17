#include <stdio.h>

void printWordsMoreThan3Letters(char str[]) {
    int currLen = 0;  // Tracks the length of the current word
    int start = 0;    // Start index of the current word
    int i = 0;

    printf("Words with more than 3 letters:\n");

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            // Part of a word
            if (currLen == 0) {
                start = i;  // Mark the start of the word
            }
            currLen++;
        } else {
            // End of a word // space detected 
            if (currLen > 3) {
                // Print the word
                for (int j = start; j < start + currLen; j++) {
                    printf("%c", str[j]);
                }
                printf("\n");
            }
            currLen = 0;  // Reset current word length
        }
        i++;
    }

    // Check the last word in the string
    if (currLen > 3) {
        for (int j = start; j < start + currLen; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

int main() {
    char str[200];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);  // Read the input string safely

    printWordsMoreThan3Letters(str);

    return 0;
}
