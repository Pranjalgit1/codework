#include <stdio.h>

int main() {
    FILE *source, *target;
    char ch;
    
    // Open source file for reading
    source = fopen("source.txt", "r");
    if (source == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }
    
    // Open target file for writing
    target = fopen("vowels.txt", "w");
    if (target == NULL) {
        printf("Error creating target file!\n");
        fclose(source);
        return 1;
    }
    
    // Read from source and write vowels to target
    while ((ch = fgetc(source)) != EOF) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            fputc(ch, target);
        }
    }
    
    // Close both files
    fclose(source);
    fclose(target);
    
    // Open target file for reading and display
    target = fopen("vowels.txt", "r");
    if (target == NULL) {
        printf("Error opening target file!\n");
        return 1;
    }
    
    printf("Vowels extracted from source file:\n");
    while ((ch = fgetc(target)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(target);
    return 0;
} 