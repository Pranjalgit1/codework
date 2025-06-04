#include <stdio.h>
#include <string.h>

// Function to find character frequency and first/last occurrence using pointer notation
void findCharInfo(char *str, char target, int *freq, int *firstIndex, int *lastIndex) {
    *freq = 0;          // Initialize frequency to 0
    *firstIndex = -1;   // Initialize first index to -1 (not found)
    *lastIndex = -1;    // Initialize last index to -1 (not found)
    
    // Traverse string using pointer in for loop
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == target) {
            (*freq)++;  // Increment frequency
            if (*firstIndex == -1) {
                *firstIndex = ptr - str;  // Store first occurrence
            }
            *lastIndex = ptr - str;       // Update last occurrence
        }
    }
}

int main() {
    char str[100];
    char target;
    int frequency, firstIndex, lastIndex;
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    str[strlen(str) - 1] = '\0';
    
    // Input character to search (note the space before %c)
    printf("Enter character to search: ");
    scanf(" %c", &target);  // Space before %c to skip whitespace
    
    // Find character information
    findCharInfo(str, target, &frequency, &firstIndex, &lastIndex);
    
    // Print results
    printf("\nString: %s\n", str);
    printf("Character '%c':\n", target);
    printf("Frequency: %d\n", frequency);
    
    if (firstIndex != -1) {
        printf("First occurrence at index: %d\n", firstIndex);
        printf("Last occurrence at index: %d\n", lastIndex);
    } else {
        printf("Character not found in the string\n");
    }
    
    return 0;
} 