#include <stdio.h>

// Function to count frequency of a character in a string
void countFrequency(char str[], char ch, int *frequency) {
    *frequency = 0;  // Initialize frequency to 0
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch) {
            (*frequency)++;  // Increment frequency when character is found
        }
    }
}

int main() {
    char str[100];
    char ch;
    int frequency;  // Regular variable, not a pointer
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Enter character to count: ");
    scanf(" %c", &ch);
    
    // Pass address of frequency because we want to modify it
    countFrequency(str, ch, &frequency);
    
    printf("Frequency of '%c' in '%s' is: %d\n", ch, str, frequency);
    
    return 0;
} 