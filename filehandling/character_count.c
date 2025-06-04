#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int alphabets = 0, digits = 0, special = 0;
    
    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Check for alphabet
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            alphabets++;
        }
        // Check for digit
        else if (ch >= '0' && ch <= '9') {
            digits++;
        }
        // Check for special character (not alphabet, not digit, not space, not newline)
        else if (ch != ' ' && ch != '\n' && ch != '\t') {
            special++;
        }
    }
    
    // Display results
    printf("\nCharacter Count in file:\n");
    printf("------------------------\n");
    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Special Characters: %d\n", special);
    printf("Total Characters: %d\n", alphabets + digits + special);
    
    fclose(file);
    return 0;
} 