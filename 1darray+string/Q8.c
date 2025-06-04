#include <stdio.h>

// Function to calculate string length using pointer arithmetic
int my_strlen(const char *str) {
    const char *ptr = str;  // Create a pointer to traverse the string
    while (*ptr != '\0') {  // Dereference pointer to check character
        ptr++;              // Move pointer to next character
    }
    return ptr - str;       // Return difference between pointers (length)
}

// Function to compare two strings using pointer arithmetic
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {  // While both strings have characters
        if (*str1 != *str2) { // Compare characters at current position
            return *str1 - *str2;
        }
        str1++;  // Move to next character
        str2++;
    }
    return *str1 - *str2;  // Return difference of last characters
}

// Function to concatenate two strings using pointer arithmetic
void my_strcat(char *dest, const char *src) {
    // Move pointer to end of destination string
    while (*dest) {
        dest++;
    }
    
    // Copy source string to end of destination
    while (*src) {
        *dest = *src;  // Copy character
        dest++;
        src++;
    }
    *dest = '\0';  // Add null terminator
}

// Function to copy one string to another using pointer arithmetic
void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;  // Copy character
        dest++;
        src++;
    }
    *dest = '\0';  // Add null terminator
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    
    // Test strlen
    printf("Length of str1: %d\n", my_strlen(str1));
    
    // Test strcmp
    printf("Comparison result: %d\n", my_strcmp(str1, str2));
    
    // Test strcat
    my_strcat(str1, " ");
    my_strcat(str1, str2);
    printf("After concatenation: %s\n", str1);
    
    // Test strcpy
    my_strcpy(str3, str1);
    printf("After copying: %s\n", str3);
    
    return 0;
} 