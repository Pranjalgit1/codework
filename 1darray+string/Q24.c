#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int j = 0;  // Index for non-space characters
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';  // Remove newline
    
    // Remove spaces using pointer notation
    for (int i = 0; *(str + i) != '\0'; i++) {
        if (*(str + i) != ' ') {
            *(str + j) = *(str + i);
            j++;
        }
    }
    *(str + j) = '\0';  // Add null terminator at the end
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("\nResult:\n");
    printf("--------------------\n");
    printf("String without spaces: %s\n", str);
    printf("--------------------\n");
    
    return 0;
} 