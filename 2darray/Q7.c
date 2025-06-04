#include <stdio.h>

void interchangeRows(int rows, int cols, int matrix[rows][cols], int row1, int row2) {
    for (int j = 0; j < cols; j++) {
        // Swap elements between the two rows
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

int main() {
    int rows, cols, row1, row2;
    
    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declare variable-length array
    int matrix[rows][cols];

    // Input matrix elements
    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Input row numbers to interchange
    printf("\nEnter first row number (1 to %d): ", rows);
    scanf("%d", &row1);
    printf("Enter second row number (1 to %d): ", rows);
    scanf("%d", &row2);

    // Validate row numbers
    if (row1 < 1 || row1 > rows || row2 < 1 || row2 > rows) {
        printf("Invalid row numbers!\n");
        return 1;
    }

    // Convert to 0-based indexing
    row1--;
    row2--;

    // Interchange the rows
    interchangeRows(rows, cols, matrix, row1, row2);

    // Print modified matrix
    printf("\nMatrix after interchanging rows %d and %d:\n", row1 + 1, row2 + 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
} 