#include <stdio.h>

#define ROWS 3
#define COLS 3

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[ROWS][COLS] = {{3, 1, 2},
                           {9, 4, 8},
                           {7, 5, 6}};
    int oneDarray[ROWS * COLS];
    int index = 0;

    // Flatten the 2D array into a 1D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            oneDarray[index++] = arr[i][j];
        }
    }

    // Sort the 1D array
    sortArray(oneDarray, ROWS * COLS);

    // Convert the sorted 1D array back into a 2D array
    index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = oneDarray[index++];
        }
    }

    // Print the sorted 2D array
    printf("Sorted 2D Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
