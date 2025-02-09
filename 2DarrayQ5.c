#include <stdio.h>

void selectionSortRow(int arr[][10], int row, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[row][j] < arr[row][minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[row][minIndex];
        arr[row][minIndex] = arr[row][i];
        arr[row][i] = temp;
    }
}

void selectionSortColumn(int arr[][10], int col, int m) {
    for (int i = 0; i < m - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m; j++) {
            if (arr[j][col] < arr[minIndex][col]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex][col];
        arr[minIndex][col] = arr[i][col];
        arr[i][col] = temp;
    }
}

int main() {
    int m, n, choice, row, col;

    printf("Enter number of rows (m): ");
    scanf("%d", &m);

    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    int arr[10][10];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter 1 to sort a row or 2 to sort a column: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter row number (0-%d): ", m - 1);
        scanf("%d", &row);
        selectionSortRow(arr, row, n);
        printf("Sorted row %d:\n", row);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[row][i]);
        }
        printf("\n");
    } else if (choice == 2) {
        printf("Enter column number (0-%d): ", n - 1);
        scanf("%d", &col);
        selectionSortColumn(arr, col, m);
        printf("Sorted column %d:\n", col);
        for (int i = 0; i < m; i++) {
            printf("%d ", arr[i][col]);
        }
        printf("\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
