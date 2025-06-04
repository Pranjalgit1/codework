#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int size;
    
    // Get the size of string from user
    printf("Enter the size of string: ");
    scanf("%d", &size);
    
    // Allocate memory dynamically
    str = (char *)malloc((size + 1) * sizeof(char));  // +1 for null terminator
    
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Clear the input buffer
    getchar();
    
    // Get string input from user
    printf("Enter the string: ");
    fgets(str, size + 1, stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    // Print the string
    printf("The string is: %s\n", str);
    
    // Print the length of string
    printf("Length of string: %lu\n", strlen(str));
    
    // Free the allocated memory
    free(str);
    
    return 0;
} 