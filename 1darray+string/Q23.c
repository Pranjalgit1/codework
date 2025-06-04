#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int pos;
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';  // Remove newline
    
    // Input position
    printf("Enter position to delete (0-%d): ", strlen(str) - 1);
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 0 || pos >= strlen(str)) {
        printf("\nInvalid position!\n");
        return 1;
    }
    
    // Shift characters to remove the character using pointer notation
    for (int i = pos; *(str + i) != '\0'; i++) {
        *(str + i) = *(str + i + 1);
    }
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("Position deleted: %d\n", pos);
    printf("\nResult:\n");
    printf("--------------------\n");
    printf("Modified string: %s\n", str);
    printf("--------------------\n");
    
    return 0;
} 