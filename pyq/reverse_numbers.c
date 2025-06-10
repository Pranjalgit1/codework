#include <stdio.h>

// Function to reverse a number
int reverseNumber(int num) {
    int rev = 0;
    while(num > 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    return rev;
}

int main() {
    FILE *fp1, *fp2;
    int n, num, rev;
    
    // Open files in w+ mode
    fp1 = fopen("INTEGER.txt", "w+");
    fp2 = fopen("REVERSE.txt", "w+");
    
    if(fp1 == NULL || fp2 == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    // Input number of integers
    printf("Enter number of integers: ");
    scanf("%d", &n);
    
    // Input and write numbers to first file
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(fp1, "%d\n", num);
    }
    
    // Reset file pointer to beginning
    rewind(fp1);
    
    // Read numbers, reverse them and write to second file
    while(fscanf(fp1, "%d", &num) != EOF) {
        rev = reverseNumber(num);
        fprintf(fp2, "%d\n", rev);
    }
    
    // Reset file pointers to beginning
    rewind(fp1);
    rewind(fp2);
    
    // Display contents of both files
    printf("\nContents of INTEGER.txt:\n");
    while(fscanf(fp1, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    
    printf("\nContents of REVERSE.txt:\n");
    while(fscanf(fp2, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    
    // Close files
    fclose(fp1);
    fclose(fp2);
    
    return 0;
} 