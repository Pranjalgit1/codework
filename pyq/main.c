#include<stdio.h>
#include<string.h>

int main() {
    FILE *fp;
    char str[100];
    int wordCount = 0;
    int i = 0;
    char ch;
    
    // Open file for both reading and writing
    fp = fopen("input.txt", "w+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Get string from user and write to file
    printf("Enter a string: ");
    gets(str);
    fprintf(fp, "%s", str);
    
    // Reset file pointer to beginning
    rewind(fp);
    
    // Read string from file character by character using fgetc
    i = 0;
    while((ch = fgetc(fp)) != EOF && ch != '\n') {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';  // Add null terminator
    
    // Count words
    for(i = 0; str[i] != '\0'; i++) {
        // If current character is space and next character is not space or end
        if(str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0') {
            wordCount++;
        }
    }
    // Add 1 for the last word
    wordCount++;
    
    // Write word count to file
    fprintf(fp, "\nNumber of words: %d", wordCount);
    
    // Print results
    printf("\nString: %s", str);
    printf("\nNumber of words: %d", wordCount);
    
    fclose(fp);
    return 0;
}   