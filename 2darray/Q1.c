#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap elements
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int rows, cols, rowNum;
    
    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declare matrix
    int matrix[rows][cols];
    int temp[cols];  // Temporary array for sorting

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

    // Input row number to sort
    printf("\nEnter row number to sort (1 to %d): ", rows);
    scanf("%d", &rowNum);
    if (rowNum < 1 || rowNum > rows) {
        printf("Invalid row number!\n");
        return 1;
    }
    rowNum--;  // Convert to 0-based index

    // Copy row to temp array
    for (int j = 0; j < cols; j++) {
        temp[j] = matrix[rowNum][j];
    }

    // Sort the row using selection sort
    selectionSort(temp, cols);

    // Copy back to matrix
    for (int j = 0; j < cols; j++) {
        matrix[rowNum][j] = temp[j];
    }

    // Print modified matrix
    printf("\nMatrix after sorting row %d:\n", rowNum + 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
