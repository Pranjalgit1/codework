#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[100];
    int pos;
    
    // Input main string
    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';  // Remove newline
    
    // Input substring
    printf("Enter substring to insert: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strlen(sub) - 1] = '\0';  // Remove newline
    
    // Input position
    printf("Enter position to insert (0-%d): ", strlen(str));
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 0 || pos > strlen(str)) {
        printf("\nInvalid position!\n");
        return 1;
    }
    
    // Check if there's enough space
    if (strlen(str) + strlen(sub) >= sizeof(str)) {
        printf("\nNot enough space to insert substring!\n");
        return 1;
    }
    
    // Shift characters to make space for substring
    for (int i = strlen(str); i >= pos; i--) {
        *(str + i + strlen(sub)) = *(str + i);
    }
    
    // Insert substring
    for (int i = 0; *(sub + i) != '\0'; i++) {
        *(str + pos + i) = *(sub + i);
    }
    
    // Display results
    printf("\nMain string: %s\n", str);
    printf("Substring: %s\n", sub);
    printf("Position: %d\n", pos);
    printf("\nResult:\n");
    printf("--------------------\n");
    printf("Modified string: %s\n", str);
    printf("--------------------\n");
    
    return 0;
} 