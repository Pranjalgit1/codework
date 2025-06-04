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
    int rows, cols, colNum;
    
    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declare matrix
    int matrix[rows][cols];
    int temp[rows];  // Temporary array for sorting

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

    // Input column number to sort
    printf("\nEnter column number to sort (1 to %d): ", cols);
    scanf("%d", &colNum);
    if (colNum < 1 || colNum > cols) {
        printf("Invalid column number!\n");
        return 1;
    }
    colNum--;  // Convert to 0-based index

    // Copy column to temp array
    for (int i = 0; i < rows; i++) {
        temp[i] = matrix[i][colNum];
    }

    // Sort the column using selection sort
    selectionSort(temp, rows);

    // Copy back to matrix
    for (int i = 0; i < rows; i++) {
        matrix[i][colNum] = temp[i];
    }

    // Print modified matrix
    printf("\nMatrix after sorting column %d:\n", colNum + 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
} 