#include <stdio.h>
#include <string.h>

void deleteChar(char str[], int pos) {
    int len = strlen(str);
   
    
    for (int i = pos; i < len - 1; i++) {
        str[i] = str[i + 1]; // Shift characters left
    }
    
    str[len - 1] = '\0';  // Null-terminate the string
}

int main() {
    char str[100];  
    int pos;

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline if present
    str[strlen(str)-1] = '\0';

    // Input position
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);

    printf("Before: %s\n", str);
    deleteChar(str, pos);
    printf("After:  %s\n", str);

    return 0;
}
