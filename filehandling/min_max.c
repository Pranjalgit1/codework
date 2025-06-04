#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;
    int min, max;
    
    // Get array size
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    // Allocate memory
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize min and max with first element
    min = max = arr[0];
    
    // Find min and max
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Display array
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Display results
    printf("\nMinimum value: %d", min);
    printf("\nMaximum value: %d\n", max);
    
    // Free allocated memory
    free(arr);
    
    return 0;
} 