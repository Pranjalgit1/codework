#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;
    
    // Get number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input elements using pointer notation
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));  // Pointer notation
    }
    
    // Display original array using pointer notation
    printf("\nOriginal array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));  // Pointer notation
    }
    
    // Replace numbers using pointer notation
    for (i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {  // Pointer notation for checking
            // Even number: replace with next even
            *(arr + i) = *(arr + i) + 2;  // Pointer notation
        } else {
            // Odd number: replace with previous odd
            *(arr + i) = *(arr + i) - 2;  // Pointer notation
        }
    }
    
    // Display modified array using pointer notation
    printf("\n\nModified array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));  // Pointer notation
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    
    return 0;
} 