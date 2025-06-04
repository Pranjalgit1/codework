#include <stdio.h>
#include <string.h>

// Function to check if string is palindrome using pointers
int isPalindrome(char *str) {
    char *start = str;                    // Pointer to start of string
    char *end = str + strlen(str) - 1;    // Pointer to end of string
    
    // Compare characters from both ends until pointers meet
    while (start < end) {
        if (*start != *end) {
            return 0;  // Not a palindrome
        }
        start++;
        end--;
    }
    return 1;  // Is a palindrome
}

int main() {
    char str[100];
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Print original string
    printf("Original string: %s\n", str);
    
    // Check if string is palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    
    return 0;
} 