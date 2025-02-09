
#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int arr[m][n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }

    printf("The sum of all elements in the array is: %d\n", sum);

    return 0;
}