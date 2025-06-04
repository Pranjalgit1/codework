#include <stdio.h>

int main() {
    FILE *file;
    int num, i;
    
    // Open file for writing
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    // Input and write 20 integers
    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    
    fclose(file);
    
    // Open file for reading
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Read and display even numbers
    printf("\nEven numbers from file:\n");
    printf("------------------------\n");
    
    while (fscanf(file, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            printf("%d\n", num);
        }
    }
    
    fclose(file);
    return 0;
} 