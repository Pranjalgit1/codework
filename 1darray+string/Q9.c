#include <stdio.h>
#include <string.h>

// Function to reverse a string using pointers
void reverseString(char *str) {
    // Find the end of the string
    char *end = str;
    while (*end) {
        end++;
    }
    end--;  // Move back one position to point to last character
    
    // Swap characters from both ends until pointers meet in middle
    while (str < end) {
        // Swap characters
        char temp = *str;
        *str = *end;
        *end = temp;
        
        // Move pointers
        str++;
        end--;
    }
}

int main() {
    char str[100];
    
    // Input string using fgets
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character using strlen
    str[strlen(str) - 1] = '\0';
    
    // Print original string
    printf("Original string: %s\n", str);
    
    // Reverse the string
    reverseString(str);
    
    // Print reversed string
    printf("Reversed string: %s\n", str);
    
    return 0;
} 