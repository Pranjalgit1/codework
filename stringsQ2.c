#include <stdio.h>
#include <string.h>

void reverseWords(char* str) {
    int length = strlen(str);
    char temp;
    int start = 0;
    int end = length - 1;

    

    // Reverse each word in the reversed string
    start = 0;
    for (int i = 0; i <= length; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            end = i - 1;
            while (start < end) {
                temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main() {
    char str[] = "I love programming in C";
    printf("Original string: %s\n", str);
    reverseWords(str);
    printf("Reversed words string: %s\n", str);
    return 0;
}
