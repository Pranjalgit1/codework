#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    
    // Open file
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Using fscanf for character by character (inefficient)
    while (fscanf(file, "%c", &ch) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file);
    return 0;
} 