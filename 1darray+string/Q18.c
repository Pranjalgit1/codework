#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // Input string
    printf("Enter company name: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    printf("\nOriginal name: %s\n", str);
    printf("Initials: ");
    
    // Print first character
    printf("%c", str[0]);
    
    // Print first character after each space
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == ' ' && *(ptr + 1) != ' ' && *(ptr + 1) != '\0') {
            printf("%c", *(ptr + 1));
        }
    }
    printf("\n");
    
    return 0;
} 