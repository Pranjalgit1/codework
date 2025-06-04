#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int n, i;
    
    // Open file for writing
    file = fopen("chars.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    // Get number of characters
    printf("Enter number of characters: ");
    scanf("%d", &n);
    
    // Clear input buffer
    getchar();
    
    // Input characters and write to file
    printf("Enter %d characters:\n", n);
    for (i = 0; i < n; i++) {
        ch = getchar();
        fputc(ch, file);
    }
    
    fclose(file);
    
    // Open file for reading
    file = fopen("chars.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Move to end of file
    fseek(file, 0, SEEK_END);
    
    // Print characters in reverse order
    printf("\nCharacters in reverse order:\n");
    for (i = 0; i < n; i++) {
        fseek(file, -1, SEEK_CUR);  // Move back one character
        ch = fgetc(file);
        printf("%c", ch);
        fseek(file, -1, SEEK_CUR);  // Move back again to read next character
    }
    printf("\n");
    
    fclose(file);
    return 0;
} 