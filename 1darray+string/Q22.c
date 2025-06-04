#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char ch;
    int pos;
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';  // Remove newline
    
    // Input character to insert
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    
    // Input position
    printf("Enter position to insert (0-%d): ", strlen(str));
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 0 || pos > strlen(str)) {
        printf("\nInvalid position!\n");
        return 1;
    }
    
    // Shift characters to make space using pointer notation
    for (int i = strlen(str); i >= pos; i--) {
        *(str + i + 1) = *(str + i);
    }
    
    // Insert character using pointer notation
    *(str + pos) = ch;
    
    // Display results
    printf("\nOriginal string: %s\n", str);
    printf("Character inserted: %c\n", ch);
    printf("Position: %d\n", pos);
    printf("\nResult:\n");
    printf("--------------------\n");
    printf("Modified string: %s\n", str);
    printf("--------------------\n");
    
    return 0;
} 