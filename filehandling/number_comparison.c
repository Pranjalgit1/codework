#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers;
    int n, i, compare_num;
    int larger = 0, smaller = 0, equal = 0;
    
    // Get number of integers
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    
    // Allocate memory dynamically
    numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input numbers
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Get number to compare
    printf("\nEnter number to compare: ");
    scanf("%d", &compare_num);
    
    // Count numbers
    for (i = 0; i < n; i++) {
        if (numbers[i] > compare_num) {
            larger++;
        }
        else if (numbers[i] < compare_num) {
            smaller++;
        }
        else {
            equal++;
        }
    }
    
    // Display results
    printf("\nResults:\n");
    printf("Numbers larger than %d: %d\n", compare_num, larger);
    printf("Numbers smaller than %d: %d\n", compare_num, smaller);
    printf("Numbers equal to %d: %d\n", compare_num, equal);
    
    // Free allocated memory
    free(numbers);
    
    return 0;
} 