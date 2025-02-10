#include <stdio.h>

#define ROWS 3
#define COLS 4

void selectionSortColumn(int arr[ROWS][COLS], int col) {
    int i, j, min_idx, temp;
    for (i = 0; i < ROWS-1; i++) {
        min_idx = i;
        for (j = i+1; j < ROWS; j++) {
            if (arr[j][col] < arr[min_idx][col])
            //iterating rows and keeping column fixed 
                min_idx = j;
        }
        // Swap the found minimum element with the first element in the column
        temp = arr[min_idx][col];
        arr[min_idx][col] = arr[i][col];
        arr[i][col] = temp;
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

    for (int i = 0; i < COLS; i++) {
        selectionSortColumn(arr, i); 
    /* passing single colunmn is not possible so we passed whole array and
    i is the fixed column number */
    
    }

    printf("\nSorted array column-wise:\n");
    printArray(arr);

    return 0;
}
