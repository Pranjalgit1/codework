#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *source, *target;
    char ch;
    int n, i;
    
    // Open source file for writing
    source = fopen("source.txt", "w");
    if (source == NULL) {
        printf("Error creating source file!\n");
        return 1;
    }
    
    // Get number of characters
    printf("Enter number of characters: ");
    scanf("%d", &n);
    getchar();  // Clear buffer
    
    // Input and write uppercase characters
    printf("Enter %d characters in uppercase:\n", n);
    for (i = 0; i < n; i++) {
        ch = getchar();
        // Convert to uppercase if not already
        ch = toupper(ch);
        fputc(ch, source);
    }
    
    fclose(source);
    
    // Open source file for reading and target file for writing
    source = fopen("source.txt", "r");
    target = fopen("target.txt", "w");
    
    if (source == NULL || target == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    // Copy contents with case conversion
    while ((ch = fgetc(source)) != EOF) {
        // Convert to lowercase and write
        ch = tolower(ch);
        fputc(ch, target);
    }
    
    fclose(source);
    fclose(target);
    
    // Open target file for reading and display
    target = fopen("target.txt", "r");
    if (target == NULL) {
        printf("Error opening target file!\n");
        return 1;
    }
    
    printf("\nContents of target file (in lowercase):\n");
    while ((ch = fgetc(target)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(target);
    return 0;
} 