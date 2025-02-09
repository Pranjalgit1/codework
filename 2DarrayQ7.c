#include <stdio.h>

#define ROWS 3
#define COLS 3

void reverseRow(int arr[ROWS][COLS], int row) {
  for(int i = 0;i,COLS/2;i++){
    int temp = arr[row][i];
    arr[row][i] = arr[row][COLS-1-i];
    arr[row][COLS-1-i] = temp;
  }
}

void reverseColumn(int arr[ROWS][COLS], int col) {
    int start = 0;
    int end = ROWS - 1;
    while (start < end) {
        int temp = arr[start][col];
        arr[start][col] = arr[end][col];
        arr[end][col] = temp;
        start++;
        end--;
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
    int arr[ROWS][COLS];

    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int choice, index;
    printf("Enter 1 to reverse a row or 2 to reverse a column: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the row number to reverse (0-%d): ", ROWS - 1);
        scanf("%d", &index);
        reverseRow(arr, index);
    } else if (choice == 2) {
        printf("Enter the column number to reverse (0-%d): ", COLS - 1);
        scanf("%d", &index);
        reverseColumn(arr, index);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Array after reversing:\n");
    printArray(arr);

    return 0;
}