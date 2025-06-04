#include <stdio.h>

int main() {
    FILE *file;
    int num;
    
    // Open file
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Using fscanf for integers (recommended)
    while (fscanf(file, "%d", &num) == 1) {
        printf("Read number: %d\n", num);
    }
    
    fclose(file);
    return 0;
} 