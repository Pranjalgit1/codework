#include <stdio.h>
#include <string.h>

// Define the student structure
struct Student {
    char name[50];
    int roll_no;
    float marks[5];  // Array for 5 subjects
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();  // Clear input buffer
    
    struct Student students[n];
    
    // Input details for n students
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i+1);
        
        printf("Enter Name: ");
        gets(students[i].name);
          // Remove newline
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);
        getchar();  // Clear input buffer
        
        // Input marks for 5 subjects
        float total = 0;
        printf("Enter marks for 5 subjects:\n");
        for(int j = 0; j < 5; j++) {
            printf("Subject %d: ", j+1);
            scanf("%f", &students[i].marks[j]);
            getchar();  // Clear input buffer
            total += students[i].marks[j];
        }
        
        // Calculate percentage (assuming each subject is out of 100)
        students[i].percentage = (total / 500.0) * 100;
    }
    
    // Display name and percentage of all students
    printf("\nStudent Results:\n");
    printf("----------------\n");
    for(int i = 0; i < n; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Percentage: %.2f%%\n", students[i].percentage);
        printf("----------------\n");
    }
    
    return 0;
} 