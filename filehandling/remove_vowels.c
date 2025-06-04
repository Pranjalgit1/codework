#include <stdio.h>

int main() {
    FILE *input, *output;
    char ch;
    int n, i;
    
    // Open first file for writing
    input = fopen("input.txt", "w");
    if (input == NULL) {
        printf("Error creating input file!\n");
        return 1;
    }
    
    // Get number of characters from user
    printf("Enter number of characters: ");
    scanf("%d", &n);
    
    // Clear input buffer
    getchar();
    
    // Get characters from user and write to file
    printf("Enter %d characters: ", n);
    for (i = 0; i < n; i++) {
        // Method 1: Using scanf
        scanf("%c", &ch);
        // No need for getchar() here because scanf("%c") reads the newline
        
        // Method 2: Using fgetc
        // ch = fgetc(stdin);
        
        // Method 3: Using getchar (original)
        // ch = getchar();
        
        fputc(ch, input);
    }
    
    fclose(input);
    
    // Open files for reading and writing
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    // Read from input file and write to output file (excluding vowels)
    while ((ch = fgetc(input)) != EOF) {
        // Check if character is not a vowel
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            fputc(ch, output);
        }
    }
    
    // Close both files
    fclose(input);
    fclose(output);
    
    // Display final contents
    printf("\nFinal contents of output.txt:\n");
    output = fopen("output.txt", "r");
    while ((ch = fgetc(output)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(output);
    return 0;
} 