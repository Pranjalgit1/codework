


#include <stdio.h>

void calculateRowSum(int arr[][10], int row, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[row][i];
    }
    printf("Sum of row %d: %d\n", row, sum);
}

void calculateColumnSum(int arr[][10], int col, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i][col];
    }
    printf("Sum of column %d: %d\n", col, sum);
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

    printf("Enter 1 to calculate row sum or 2 to calculate column sum: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter row number (0-%d): ", m - 1);
        scanf("%d", &row);
        calculateRowSum(arr, row, n);
    } else if (choice == 2) {
        printf("Enter column number (0-%d): ", n - 1);
        scanf("%d", &col);
        calculateColumnSum(arr, col, m, n);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

