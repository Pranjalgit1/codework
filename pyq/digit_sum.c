#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int sum = 0;
    
    // Get input string
    printf("Enter an alphanumeric string: ");
    gets(str);
    
    // Iterate through each character
    for(int i = 0; str[i] != '\0'; i++) {
        // Check if character is a digit
        if(str[i] >= '0' && str[i] <= '9') {
            // Convert to integer and add to sum
            sum += (str[i] - '0');
        }
    }
    
    // Print result
    printf("\nInput string: %s\n", str);
    printf("Sum of digits: %d\n", sum);
    
    return 0;
} 