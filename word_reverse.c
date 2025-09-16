#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a substring from start to end
void reverseSubstring(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse each word in the string (fixed version)
void reverseWords(char* str) {
    int len = strlen(str);
    if (len == 0) return; // Handle empty string
    
    int start = 0;
    int i = 0;
    
    // Skip leading whitespace
    while (i < len && isspace(str[i])) {
        i++;
    }
    start = i;
    
    // Process each character
    while (i <= len) {
        // If we encounter whitespace or end of string, reverse the word
        if (i == len || isspace(str[i])) {
            // Only reverse if there's actually a word (start < i)
            if (start < i) {
                reverseSubstring(str, start, i - 1);
            }
            
            // Skip consecutive whitespace
            while (i < len && isspace(str[i])) {
                i++;
            }
            start = i;
        } else {
            i++;
        }
    }
}

int main() {
    char input[1000];
    
    printf("=== String Word Reversal Program ===\n");
    printf("This program reverses each word individually while maintaining word order.\n");
    printf("Example: 'asdf ghjkl' becomes 'fdsa lkjhg'\n\n");
    
    printf("Enter a string: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input!\n");
        return 1;
    }
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';
    
    // Check for empty string
    if (strlen(input) == 0) {
        printf("Error: Empty string!\n");
        return 1;
    }
    
    printf("\nOriginal string: '%s'\n", input);
    
    // Reverse each word
    reverseWords(input);
    
    printf("Reversed string: '%s'\n", input);
    
    return 0;
} 