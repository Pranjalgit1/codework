#include <stdio.h>

int main() {
    FILE *source, *target;
    char ch;
    int n, i;
    
    // Open first file for writing
    source = fopen("source.txt", "w");
    if (source == NULL) {
        printf("Error creating source file!\n");
        return 1;
    }
    
    // Get number of characters
    printf("Enter number of characters: ");
    scanf("%d", &n);
    getchar();  // Clear buffer
    
    // Input characters and write to file
    printf("Enter %d characters:\n", n);
    for (i = 0; i < n; i++) {
        ch = getchar();
        fputc(ch, source);
    }
    
    fclose(source);
    
    // Open files for copying
    source = fopen("source.txt", "r");
    target = fopen("target.txt", "w");
    
    if (source == NULL || target == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    // Copy contents
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }
    
    // Close both files
    fclose(source);
    fclose(target);
    
    // Display contents of new file
    printf("\nContents of target.txt:\n");
    printf("------------------------\n");
    
    target = fopen("target.txt", "r");
    while ((ch = fgetc(target)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(target);
    return 0;
} 