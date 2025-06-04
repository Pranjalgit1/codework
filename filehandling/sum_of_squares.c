#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i, sum = 0;
    
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
        scanf("%d", (arr + i));
    }
    
    // Calculate sum of squares using pointer notation
    for (i = 0; i < n; i++) {
        sum += (*(arr + i)) * (*(arr + i));
    }
    
    // Display elements and their squares using pointer notation
    printf("\nElements and their squares:\n");
    printf("------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d^2 = %d\n", *(arr + i), (*(arr + i)) * (*(arr + i)));
    }
    
    // Display final sum
    printf("\nSum of squares = %d\n", sum);
    
    // Free allocated memory
    free(arr);
    
    return 0;
} 