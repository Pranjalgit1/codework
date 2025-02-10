#include <stdio.h>

#define ROWS 3
#define COLS 4

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {64, 25, 12, 22},
        {11, 9, 5, 6},
        {98, 34, 23, 11}
    };

    printf("Original array:\n");
    printArray(arr); 
    //dry run of passing 1 row into sort function
    
// Loop Iteration 1 (i = 0):

// The first row {64, 25, 12, 22} is passed to the selectionSort function.

// Inside selectionSort:

// Initial state: 64 25 12 22

// After sorting: 12 22 25 64
    for (int i = 0; i < ROWS; i++) {
        selectionSort(arr[i], COLS);
    }

    printf("\nSorted array row-wise:\n");
    printArray(arr);

    return 0;
}
