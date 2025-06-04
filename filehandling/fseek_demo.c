#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    
    // Create and write to file
    file = fopen("demo.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    // Write some text
    fprintf(file, "Hello World!");
    fclose(file);
    
    // Open for reading
    file = fopen("demo.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("Demonstrating fseek:\n");
    printf("-------------------\n");
    
    // 1. SEEK_SET: Start from beginning
    printf("\n1. Using SEEK_SET (from beginning):\n");
    fseek(file, 6, SEEK_SET);  // Move 6 bytes from start
    ch = fgetc(file);
    printf("Character at position 6: %c\n", ch);
    
    // 2. SEEK_CUR: From current position
    printf("\n2. Using SEEK_CUR (from current):\n");
    fseek(file, 2, SEEK_CUR);  // Move 2 bytes forward
    ch = fgetc(file);
    printf("Character 2 positions ahead: %c\n", ch);
    
    // 3. SEEK_END: From end of file
    printf("\n3. Using SEEK_END (from end):\n");
    fseek(file, -3, SEEK_END);  // Move 3 bytes back from end
    ch = fgetc(file);
    printf("Character 3 positions from end: %c\n", ch);
    
    // 4. Reading file in reverse
    printf("\n4. Reading file in reverse:\n");
    fseek(file, 0, SEEK_END);  // Go to end
    long size = ftell(file);    // Get file size
    
    printf("File contents in reverse: ");
    for (long i = 0; i < size; i++) {
        fseek(file, -1, SEEK_CUR);  // Move back one byte
        ch = fgetc(file);
        printf("%c", ch);
        fseek(file, -1, SEEK_CUR);  // Move back again
    }
    printf("\n");
    
    // 5. Reading from specific positions
    printf("\n5. Reading from specific positions:\n");
    fseek(file, 0, SEEK_SET);  // Go to start
    printf("First character: %c\n", fgetc(file));
    
    fseek(file, 5, SEEK_SET);  // Go to position 5
    printf("Character at position 5: %c\n", fgetc(file));
    
    fseek(file, -2, SEEK_END);  // Go to 2nd last position
    printf("Second last character: %c\n", fgetc(file));
    
    fclose(file);
    return 0;
} 