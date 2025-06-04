#include <stdio.h>

int main() {
    FILE *input, *single, *multiple;
    int num;
    
    // Open input file in read mode
    input = fopen("numbers.txt", "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    
    // Open output files in write mode
    single = fopen("single.txt", "w");
    multiple = fopen("multiple.txt", "w");
    
    if (single == NULL || multiple == NULL) {
        printf("Error opening output files!\n");
        fclose(input);
        return 1;
    }
    
    // Read 20 integers and separate them
    for (int i = 0; i < 20; i++) {
        if (fscanf(input, "%d", &num) == 1) {
            // Check if number is single digit (0-9)
            if (num >= 0 && num <= 9) {
                fprintf(single, "%d\n", num);
            } else {
                fprintf(multiple, "%d\n", num);
            }
        }
    }
    
    // Close all files
    fclose(input);
    fclose(single);
    fclose(multiple);
    
    printf("Numbers have been separated into single.txt and multiple.txt\n");
    
    return 0;
} 