#include <stdio.h>

int main() {
    int n;
    FILE *fptr;
    long position;
    
    // Open file in write mode
    fptr = fopen("odd_numbers.txt", "w");
    
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Get the value of n from user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Write odd numbers to file
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            // Get position before writing
            position = ftell(fptr);
            printf("Before writing %d: Position = %ld\n", i, position);
            
            // Write the number
            fprintf(fptr, "%d\n", i);
            
            // Get position after writing
            position = ftell(fptr);
            printf("After writing %d: Position = %ld\n", i, position);
        }
    }
    
    // Close the file
    fclose(fptr);
    printf("Odd numbers have been written to odd_numbers.txt\n");
    
    return 0;
} 