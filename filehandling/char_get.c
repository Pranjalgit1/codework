#include <stdio.h>

int main() {
    FILE *file;
    int ch;  // Note: int, not char
    
    // Open file
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Using fgetc for character by character (efficient)
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file);
    return 0;
} 