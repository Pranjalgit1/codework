#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, i, isSame = 1;
    
    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));
    
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Check if array reads same from front and back
    for(i = 0; i < n/2; i++) {
        if(arr[i] != arr[n-1-i]) {
            isSame = 0;
            break;
        }
    }
    
    // Print array
    printf("\nArray elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Print result
    if(isSame) {
        printf("\nArray is same");
    } else {
        printf("\nArray is not same");
    }
    
    // Free allocated memory
    free(arr);
    
    return 0;
} 