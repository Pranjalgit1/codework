#include <stdio.h>

void findMaxMinInRows(int arr[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        int max = arr[i][0];
        int min = arr[i][0];
        for (int j = 1; j < n; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
        printf("Row %d - Max: %d, Min: %d\n", i, max, min);
    }
}

int main() {
    int m, n;

    printf("Enter number of rows (m): ");
    scanf("%d", &m);

    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    int arr[m][n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    findMaxMinInRows(arr, m, n);

    return 0;
}
