#include <stdio.h>

int isSubstring(char str[], char substr[]) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] == substr[j]) {
            // Start matching
            int temp = i;
            while (str[temp] == substr[j] && substr[j] != '\0') {
                temp++;
                j++;
            }
            if (substr[j] == '\0') {
                // Substring matched completely
                return 1;
            }
            j = 0;  // Reset substring index
        }
        i++;
    }

    return 0;  // Substring not found
}

int main() {
    char str[200], substr[100];

    printf("Enter the main string: ");
    gets(str);  // Reading the main string

    printf("Enter the substring: ");
    gets(substr);  // Reading the substring

    if (isSubstring(str, substr)) {
        printf("The substring is present in the main string.\n");
    } else {
        printf("The substring is not present in the main string.\n");
    }

    return 0;
}
