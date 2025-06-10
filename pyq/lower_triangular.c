#include <stdio.h>

int main() {
    int n, i, j, isLower = 1;
    
    // Input matrix size
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);
    
    // Declare matrix
    int matrix[n][n];
    
    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print the matrix
    printf("\nThe matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Check if matrix is lower triangular
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // Check elements above principal diagonal
            if(i < j && matrix[i][j] != 0) {
                isLower = 0;
                break;
            }
        }
        if(isLower == 0) {
            break;
        }
    }
    
    // Print result
    if(isLower) {
        printf("\nThe matrix is a lower triangular matrix\n");
    } else {
        printf("\nThe matrix is NOT a lower triangular matrix\n");
    }
    
    return 0;
} 