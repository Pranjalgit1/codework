#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char ch;
    int n, i;
    char str[100];
    long pos;  // For method 2
    
    // Open first file for writing
    fp1 = fopen("DATA.txt", "w");
    
    if(fp1 == NULL) {
        printf("Error opening DATA.txt!\n");
        return 1;
    }
    
    // Input number of characters
    printf("Enter number of characters: ");
    scanf("%d", &n);
    getchar(); // Clear input buffer
    
    // Input and write characters
    printf("Enter %d characters:\n", n);
    for(i = 0; i < n; i++) {
        ch = getchar();
        fputc(ch, fp1);
    }
    
    // Close first file
    fclose(fp1);
    
    // Open first file for reading
    fp1 = fopen("DATA.txt", "r");
    
    if(fp1 == NULL) {
        printf("Error opening DATA.txt for reading!\n");
        return 1;
    }
    
    // Open second file for writing
    fp2 = fopen("OUT.txt", "w");
    
    if(fp2 == NULL) {
        printf("Error opening OUT.txt!\n");
        fclose(fp1);
        return 1;
    }
    
    /* Method 1: Using array to store and reverse
    // Read characters and store in array
    i = 0;
    while((ch = fgetc(fp1)) != EOF) {
        str[i] = ch;
        i++;
    }
    
    // Write characters in reverse order
    for(i = i-1; i >= 0; i--) {
        fputc(str[i], fp2);
    }
    */
    
    /* Method 2: Using fseek to read in reverse
    // Move to end of file
    fseek(fp1, 0, SEEK_END);
    pos = ftell(fp1);
    
    // Read and write in reverse order
    while(pos > 0) {
        pos--;
        fseek(fp1, pos, SEEK_SET);
        ch = fgetc(fp1);
        fputc(ch, fp2);
    }
    Method 3 : 
    fgets(str, 100, fp1);
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        fputc(str[i], fp2);
    */
    
    // Close both files
    fclose(fp1);
    fclose(fp2);
    
    // Display contents of both files
    printf("\nContents of DATA.txt:\n");
    fp1 = fopen("DATA.txt", "r");
    while((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp1);
    
    printf("\n\nContents of OUT.txt (in reverse):\n");
    fp2 = fopen("OUT.txt", "r");
    while((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp2);
    
    return 0;
} 