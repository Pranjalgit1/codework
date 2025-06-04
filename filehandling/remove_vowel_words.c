#include <stdio.h>

int main() {
    FILE *input, *output;
    char word[100];
    char ch;
    int i = 0;
    
    // Open input file
    input = fopen("Data.txt", "r");
    if (input == NULL) {
        printf("Error opening Data.txt!\n");
        return 1;
    }
    
    // Open output file
    output = fopen("newfile.txt", "w");
    if (output == NULL) {
        printf("Error creating newfile.txt!\n");
        fclose(input);
        return 1;
    }
    
    // Read file character by character
    while ((ch = fgetc(input)) != EOF) {
        // If character is not a space or newline, add to word
        if (ch != ' ' && ch != '\n') {
            word[i] = ch;
            i++;
        } else {
            // If we have a word
            if (i > 0) {
                word[i] = '\0';  // End the word
                
                // Check if first character is a vowel
                if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || 
                    word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || 
                    word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || 
                    word[0] == 'U') {
                    // If word starts with vowel, write a space
                    fprintf(output, " ");
                } else {
                    // If word doesn't start with vowel, write it
                    fprintf(output, "%s", word);
                }
                
                i = 0;  // Reset word index
            }
            // Write the space or newline
            fputc(ch, output);
        }
    }
    
    // Handle the last word if exists
    if (i > 0) {
        word[i] = '\0';
        // Check if first character is a vowel
        if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || 
            word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || 
            word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || 
            word[0] == 'U') {
            // If word starts with vowel, write a space
            fprintf(output, " ");
        } else {
            // If word doesn't start with vowel, write it
            fprintf(output, "%s", word);
        }
    }
    
    // Close files
    fclose(input);
    fclose(output);
    
    printf("Words starting with vowels have been removed and saved in newfile.txt\n");
    
    return 0;
} 