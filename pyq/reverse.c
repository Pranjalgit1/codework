#include<stdio.h>
#include<string.h>

int main() {
    FILE *fp;
    char str[100];
    int i, len;
    
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
    
    // Read string from file character by character
    i = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF && ch != '\n') {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';  // Add null terminator
    
    // Find length of string
    len = strlen(str);
    
    // Print original and reversed string
    printf("\nOriginal string: %s", str);
    printf("\nReversed string: ");
    for(i = len-1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    fclose(fp);
    return 0;
} 