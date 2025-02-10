#include <stdio.h>

#define ROWS 2
#define COLS 3

void flattenArray(int arr[ROWS][COLS], int flatArray[ROWS * COLS]) {
    int k = 0; // Index for the flattened array

    // Iterate through the 2D array and copy elements to the flattened array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flatArray[k] = arr[i][j];
            k++;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int flatArray[ROWS * COLS];

    flattenArray(arr, flatArray);

    printf("Flattened array:\n");
    printArray(flatArray, ROWS * COLS);

    return 0;
}
