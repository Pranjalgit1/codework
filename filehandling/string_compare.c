#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str1, *str2;
    int len1, len2;
    
    // Allocate memory for strings
    str1 = (char *)malloc(100 * sizeof(char));
    str2 = (char *)malloc(100 * sizeof(char));
    
    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input first string
    printf("Enter first string: ");
    gets(str1);
    
    // Input second string
    printf("Enter second string: ");
    gets(str2);
    
    // Calculate lengths
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    // Compare and display result
    printf("\nLength of first string: %d", len1);
    printf("\nLength of second string: %d\n", len2);
    
    if (len1 > len2) {
        printf("\nLonger string is: %s", str1);
    }
    else if (len2 > len1) {
        printf("\nLonger string is: %s", str2);
    }
    else {
        printf("\nBoth strings are of equal length");
    }
    printf("\n");
    
    // Free allocated memory
    free(str1);
    free(str2);
    
    return 0;
} 