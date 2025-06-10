#include <stdio.h>
#include <string.h>

void reversePart(char str[], int start, int end) {
    char temp;
    while(start < end) {
        // Swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        // Move indices
        start++;
        end--;
    }
}

int main() {
    char str[100];
    int start, end;
    
    // Input string
    printf("Enter a string: ");
    gets(str);
    
    // Input indices
    printf("Enter start index: ");
    scanf("%d", &start);
    printf("Enter end index: ");
    scanf("%d", &end);
    
    // Check if indices are valid
    if(start < 0 || end >= strlen(str) || start > end) {
        printf("Invalid indices!\n");
        return 1;
    }
    
    // Print original string
    printf("\nOriginal string: %s", str);
    
    // Reverse the part
    reversePart(str, start, end);
    
    // Print final string
    printf("\nString after reversing part: %s", str);
    
    return 0;
} 