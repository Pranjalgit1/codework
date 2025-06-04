#include <stdio.h>

void reverseArrayFromIndex(int arr[], int size, int startIndex) {
    int start = startIndex;
    int end = size - 1;
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int rows, cols, rowNum, startIndex;
    
    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declare matrix
    int matrix[rows][cols];
    int temp[cols];  // Temporary array for reversing

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

    // Input row number to reverse
    printf("\nEnter row number to reverse (1 to %d): ", rows);
    scanf("%d", &rowNum);
    if (rowNum < 1 || rowNum > rows) {
        printf("Invalid row number!\n");
        return 1;
    }
    rowNum--;  // Convert to 0-based index

    // Input start index
    printf("Enter start index for reversal (1 to %d): ", cols);
    scanf("%d", &startIndex);
    if (startIndex < 1 || startIndex > cols) {
        printf("Invalid start index!\n");
        return 1;
    }
    startIndex--;  // Convert to 0-based index

    // Copy row to temp array
    for (int j = 0; j < cols; j++) {
        temp[j] = matrix[rowNum][j];
    }

    // Reverse the row from start index
    reverseArrayFromIndex(temp, cols, startIndex);

    // Copy back to matrix
    for (int j = 0; j < cols; j++) {
        matrix[rowNum][j] = temp[j];
    }

    // Print modified matrix
    printf("\nMatrix after reversing row %d from index %d:\n", rowNum + 1, startIndex + 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
} 