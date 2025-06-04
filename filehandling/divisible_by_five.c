#include <stdio.h>

int main() {
    FILE *file;
    int n, num, i;
    
    // Open file for writing
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    // Get number of integers to write
    printf("Enter how many numbers to write: ");
    scanf("%d", &n);
    
    // Write numbers to file
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
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
    
    // Read and display numbers divisible by 5
    printf("\nNumbers divisible by 5:\n");
    while (fscanf(file, "%d", &num) != EOF) {
        if (num % 5 == 0) {
            printf("%d\n", num);
        }
    }
    
    fclose(file);
    return 0;
} 