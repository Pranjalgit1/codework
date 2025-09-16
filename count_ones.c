#include <stdio.h>
#include <stdlib.h>

int countOnes(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size! Size must be positive.\n");
        return 1;
    }
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d elements (0s and 1s): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        
        // Validate input (only 0s and 1s allowed)
        if (arr[i] != 0 && arr[i] != 1) {
            printf("Invalid input! Only 0s and 1s are allowed.\n");
            free(arr);
            return 1;
        }
    }
    
    printf("\nArray: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int ones = countOnes(arr, n);
    printf("Total number of 1s: %d\n", ones);
    
    free(arr);
    return 0;
}  0) {
        count++;
        n = n / 2;
    }
    
    // Handle odd factors from 3 to sqrt(n)
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            count++;
            n = n / i;
        }
    }
    
    // If n is still > 1, it's a prime factor
    if (n > 1) {
        count++;
    }
    
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        int result = countPrimeFactors(n);
        printf("%d\n", result);
    }
    
    return 0;
}