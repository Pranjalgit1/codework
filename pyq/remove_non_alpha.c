#include <stdio.h>
#include <string.h>

void removeNonAlpha(char *str) {
    int i, j = 0;
    
    // Traverse the string
    for(i = 0; str[i] != '\0'; i++) {
        // If character is alphabet, keep it
        if((str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= 'a' && str[i] <= 'z')) {
            str[j] = str[i];
            j++;
        }
    }
    
    // Add null terminator at the end
    str[j] = '\0';
}

int main() {
    char str[100];
    
    // Input string
    printf("Enter a string: ");
    gets(str);
    
    // Print original string
    printf("\nOriginal string: %s", str);
    
    // Call function to remove non-alphabets
    removeNonAlpha(str);
    
    // Print modified string
    printf("\nString after removing non-alphabets: %s", str);
    
    return 0;
} 